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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int P_MAX = 1 << 6;
const int E_MAX = 1 << 16;

int adj[P_MAX][P_MAX];

typedef map<string, int> NameIndexMap;

NameIndexMap indices;
int next_index = 0;

void dump_adj(const int p)
{
  for(int i = 0; i < p; ++i)
  {
    printf("%d:", i);
    for(int j = 0; j < p; ++j)
      printf(" %d", adj[i][j]);
    printf("\n");
  }
}

int get_index(const string &name)
{
  NameIndexMap::const_iterator it = indices.find(name);

  if(it == indices.end())
  {
    DEBUG(printf("INSERTED %s -> %d\n", name.c_str(), next_index));
    it = indices.insert(NameIndexMap::value_type(name, next_index++)).first;
  }
  return it->second;
}

int main()
{
  typedef map<string, int> NameIndexMap;

  int p, r;

  int t = 1;

  while(scanf("%d %d\n", &p, &r) == 2)
  {
    DEBUG(printf("p = %d r = %d\n", p, r));

    if(p == 0 && r == 0)
      break;

    for(int i = 0; i < p; ++i)
      for(int j = 0; j < p; ++j)
        adj[i][j] = E_MAX;

    next_index = 0;
    indices.clear();

    const size_t B_MAX = 1024;

    char first[B_MAX], second[B_MAX];

    for(int i = 0; i < r; ++i)
    {
      if(scanf("%s", &first[0]));
      const int a = get_index(string(&first[0]));
      DEBUG(printf("READ first = [%s] a = %d\n", &first[0], a));

      if(scanf("%s", &second[0]));
      const int b = get_index(string(&second[0]));
      DEBUG(printf("READ second = [%s] b = %d\n", &second[0], b));

      adj[a][b] = 1;
      adj[b][a] = 1;
    }

    DEBUG(dump_adj(p));

    for(int k = 0; k < p; ++k)
      for(int i = 0; i < p; ++i)
        for(int j = 0; j < p; ++j)
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    
    int max_sep = 0;
    
    for(int i = 0; i < p; ++i)
      for(int j = i + 1; j < p; ++j)
          max_sep = max(max_sep, adj[i][j]);

    if(max_sep == E_MAX)
      printf("Network %d: DISCONNECTED\n\n", t++);
    else
      printf("Network %d: %d\n\n", t++, max_sep);

  }
  
  return 0;
}
