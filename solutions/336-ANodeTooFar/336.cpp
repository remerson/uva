#include <cstdio>
#include <cstring>
#include <queue>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_NODES = 64;

int adjacency[MAX_NODES][MAX_NODES];
int nodes[MAX_NODES];

int add_node(int n)
{
  for(int i = 1; i <= nodes[0] + 1; ++i)
  {
    if(nodes[i] == n)
    {
      DEBUG(printf("FOUND node %d => %d\n", n, i));
      return i;
    }

    if(nodes[i] == -1)
    {
      ++nodes[0];
      nodes[nodes[0]] = n;
      DEBUG(printf("ADDED node %d => %d - %d nodes total.\n", n, i, nodes[0]));
      return nodes[0];
    }
  }
  DEBUG(printf("ERROR failed to map node %d (%d nodes total)\n", n, nodes[0]));
  return -1;
}

int find_node(int n)
{
  for(int i = 1; i <= nodes[0] + 1; ++i)
  {
    if(nodes[i] == n)
    {
      DEBUG(printf("FOUND node %d => %d\n", n, i));
      return i;
    }

    if(nodes[i] == -1)
    {
      DEBUG(printf("SPOOF node %d => %d - %d nodes total.\n", n, i, nodes[0]));
      return nodes[0] + 1;
    }
  }
  DEBUG(printf("ERROR failed to map node %d (%d nodes total)\n", n, nodes[0]));
  return -1;
}

void add_edge(int x, int y)
{
  adjacency[x][++adjacency[x][0]] = y;
  DEBUG(printf("EDGE %d => %d - node %d has %d edges.\n", x, y, x, adjacency[x][0]));
}

void dump_graph(int s, int t, bool *visited)
{
  int printed[MAX_NODES] = {0};
  printf("graph \"start = %d TTL = %d\" { ", s, t);

  for(int k = 1; k <= MAX_NODES; ++k)
  {
    if(nodes[k] == -1) break; 
    printf(" %d [fillcolor=%s,style=filled];", nodes[k], visited[k]?"blue":"red");
  }

  for(int k = 1; k <= nodes[0]; ++k)
  {
    for(int j = 1; j <= adjacency[k][0]; ++j)
    {
      if(!printed[adjacency[k][j]]) 
        printf(" %d -- %d;", nodes[k], nodes[adjacency[k][j]]);
    }
    printed[k] = true;
  }

  printf(" }\n");
}

int count(int v, int t)
{
  int c = 0;
  int n = v;
  int x;
  bool visited[MAX_NODES] = {0};
  int depth[MAX_NODES] = {-1};
  int d;
  queue<int> pending;

  pending.push(n);
  visited[n] = true;
  depth[n] = 0;
  ++c;

  DEBUG(printf("START c = %d n = %d\n", c, nodes[n]));

  while(!pending.empty())
  {
    n = pending.front();
    pending.pop();

    d = depth[n];

    for(int k = 1; k <= adjacency[n][0]; ++k)
    {
      x = adjacency[n][k];

      if(!visited[x]) depth[x] = 1 + d;

      DEBUG(printf("CONSIDER %d -> %d depth[%d] = %d depth[%d] = %d visited[%d] = %s\n", nodes[n], nodes[x], nodes[x], depth[x], nodes[n], depth[n], nodes[x], visited[x] ? "yes" : "no"));
     
      if(depth[x] > t) 
      {
        DEBUG(printf("SKIP %d\n", nodes[x]));
        continue;
      }  
      
      if(!visited[x])
      {
        visited[x] = true;
        ++c;
        DEBUG(printf("QUEUE %d c = %d\n", nodes[x], c));

        pending.push(x);
      }
      else
      {
        DEBUG(printf("VISITED %d\n", nodes[x]));
      }
    }
  }

  DEBUG(dump_graph(v, t, &visited[0]));

  return c;
}

int main()
{
  int nc, test = 0;

  while(scanf("%d\n", &nc) != EOF)
  {
    memset(&adjacency[0][0], 0, sizeof(int) * MAX_NODES * MAX_NODES);
    memset(&nodes[0], -1, sizeof(int) * MAX_NODES);
    nodes[0] = 0;

    int a, b;
    int x, y;

    for(int c = 0; c < nc; ++c)
    {
      if(scanf("%d %d", &a, &b));

      x = add_node(a);
      y = add_node(b);     

      add_edge(x, y);
      add_edge(y, x);
    }

    int start, ttl, c, v;
    
    while(scanf("%d %d", &start, &ttl) != EOF)
    {
      if(start == 0 && ttl == 0) break;

      v = find_node(start);

      DEBUG(printf("\nQUERY start %d => %d ttl = %d\n", start, v, ttl));

      c = count(v, ttl);

      DEBUG(printf("QUERY c = %d\n", c));
      
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++test, nodes[0] - c, start, ttl);
    }
  }

  return 0;
}
