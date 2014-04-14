#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>
#include <string>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_CITIES = 128;
const size_t MAX_ROUTES = 1024;
const size_t NAME_MAX = 48;
const int LARGE = MAX_ROUTES * MAX_CITIES * MAX_CITIES;

struct route
{
  route() 
    : vertex(-1),
      depart(-1),
      travel(-1),
      arrive(-1)
    { }

  route(int v, int d, int t)
    : vertex(v),
      depart(convert(d)),
      travel(t),
      arrive(depart + travel)
    { }

  bool valid() const
  {
    return depart >= 0 && depart <= 11 && arrive >= 1 && arrive <= 12 && travel <= 12;
  }

  int convert(int t)
  {
    return ((t % 24) + 6) % 24;
  }

  void print()
  {
    printf(" [%d %d/%d/%d %c]", vertex, depart, travel, arrive, (valid() ? 'Y' : 'N'));
  }

  int vertex; // The city vertex from which this route arrives at
  int depart; // The departure time (normalised, 18 = 0)
  int travel; // The journey travel time (in hours).
  int arrive; // The arrival time (normalised, <= 11)
};

// Store all the loaded input routes
route all_routes[MAX_CITIES][MAX_CITIES];

bool unweighted[MAX_CITIES][MAX_CITIES];
    
// The number of routes held in all_routes for vertex i
int num_routes[MAX_CITIES];

// Map of city name to vertex, for convenience
typedef map<string, int> vertex_map;
vertex_map vertices;
int max_vertex;

// Helper
int get_vertex(const string &city)
{
  vertex_map::const_iterator it = vertices.find(city);

  if(it == vertices.end())
  {
    ++max_vertex;
    DEBUG(printf("ADD VERTEX %d -> %s\n", max_vertex, city.c_str()));
    it = vertices.insert(vertex_map::value_type(city, max_vertex)).first;
  }
  return it->second;
}

void dump_vertices()
{
  vector<string> names;
  names.resize(max_vertex + 1);

  vertex_map::const_iterator it = vertices.begin();
  const vertex_map::const_iterator ie = vertices.end();

  while(it != ie)
  {
    names[it->second] = it->first;
    ++it;
  }

  printf("ALL VERTICES\n");
  
  // Ignore vertex 0
  for(size_t i = 1; i < names.size(); ++i)
    printf(" %lu -> %s\n", i, names[i].c_str());
}

void dump_routes()
{
  printf("ALL ROUTES\n");
  
  for(int i = 1; i <= max_vertex; ++i)
  {
    printf(" %d (%d):", i, num_routes[i]);
    for(int j = 0; j < num_routes[i]; ++j)
      all_routes[i][j].print();
    printf("\n");
  }
}

void dump_unweighted()
{
  printf("UNWEIGHTED\n");

  for(int i = 1; i <= max_vertex; ++i)
  {
    printf(" %d:", i);
    for(int j = 1; j <= max_vertex; ++j)
      if(unweighted[i][j])
	printf(" %d", j);
    printf("\n");
  }  
}

int main()
{
  int t;
  if(scanf("%d", &t));
  DEBUG(printf("T = %d\n", t));

  for(int q = 1; q <= t; ++q)
  {
    printf("Test Case %d.\n", q);;

    int r;
    if(scanf("%d", &r));
    DEBUG(printf("R = %d\n", r));

    // Reset
    for(size_t i = 0; i < MAX_CITIES; ++i)
      num_routes[i] = 0;

    vertices.clear();
    max_vertex = 0;

    char from[NAME_MAX], to[NAME_MAX];
    int depart, travel;

    // Load routes
    for(int i = 0; i < r; ++i)
    {
      if(scanf("%s %s %d %d\n", &from[0], &to[0], &depart, &travel));

      const int from_vertex = get_vertex(string(from));
      const int to_vertex = get_vertex(string(to));

      route leg(to_vertex, depart, travel);

      DEBUG(printf("READ ROUTE %s -> %s depart = %d travel = %d\n", from, to, depart, travel));

      if(leg.valid())
      {
	DEBUG(printf("ADD ROUTE %d ->", from_vertex); leg.print(); printf("\n"));
	all_routes[from_vertex][num_routes[from_vertex]++] = leg;
      }
      else
      {
	DEBUG(printf("SKIP ROUTE %d ->", from_vertex); leg.print(); printf("\n"));
      }  
    }

    DEBUG(dump_vertices());
    DEBUG(dump_routes());

    const int loaded_vertex = max_vertex;

    if(scanf("%s %s\n", &from[0], &to[0]));

    const int source_vertex = get_vertex(string(from));
    const int dest_vertex = get_vertex(string(to));

    DEBUG(printf("SHORTEST %s (%d) -> %s (%d)\n", from, source_vertex, to, dest_vertex));
    
    // Initialised unweighted "travel per day" matrix
    // for(int i = 1; i <= max_vertex; ++i)
    //   for(int j = 1; j <= max_vertex; ++j)
    // 	unweighted[i][j] = 0;

    typedef pair<int, int> CityTimePair;
    queue<CityTimePair> next_day;

    next_day.push(make_pair(source_vertex, 0));

    bitset<MAX_CITIES> visited;
    visited[source_vertex] = true;

    int min_days = LARGE;

    while(!next_day.empty())
    {
      int r = next_day.front().first;
      int d = next_day.front().second;
      next_day.pop();

      if(r == dest_vertex)
      {
	min_days = min(min_days, d);
	DEBUG(printf("ARRIVED AT %d min_days = %d\n", r, min_days));
      }

      // Where can we travel from start at r without crossing day boundary
      queue<CityTimePair> today;

      DEBUG(printf("START %d\n", r));

      // Start at time 0 from r
      today.push(make_pair(r, 0));

      while(!today.empty())
      {
	int u = today.front().first;
	int t = today.front().second;
	today.pop();

	DEBUG(printf("LOCATION %d at time %d (day %d)\n", u, t, d));

	for(int i = 0; i < num_routes[u]; ++i)
	{
	  const route &current = all_routes[u][i];

	  // More journies possible today, add it
	  if(current.depart >= t)
	  {
	    DEBUG(printf("TRAVEL %d arrive = %d\n", current.vertex, current.arrive));
	    if(current.vertex == dest_vertex)
	    {
	      min_days = min(min_days, d);
	      DEBUG(printf("ARRIVED AT %d min_days = %d\n", dest_vertex, min_days));
	    }
	    else
	    {
	      today.push(make_pair(current.vertex, current.arrive));
	    }
	  }
	  // Not possible, queue to try the next day leaving from u
	  
	  if(!visited[u])
	  {
	    DEBUG(printf("DAWN AT %d\n", u));
	    next_day.push(make_pair(u, d + 1));
	    visited[u] = true;
	  }
	}
      }
    }

    if(min_days == LARGE || loaded_vertex != max_vertex)
    {
      printf("There is no route Vladimir can take.\n");	
    }
    else
    {
      printf("Vladimir needs %d litre(s) of blood.\n", min_days);
    }
  }

  return 0;
}
