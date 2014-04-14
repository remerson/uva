#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <deque>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_NODES = 256;
const int V = MAX_NODES - 1;

int adjacency[MAX_NODES][MAX_NODES];
int colour[MAX_NODES] = {0};

void graphviz(const int n)
{
  printf("graph \"%s\" { ", "bicoloring");

  for(int k = 0; k < n; ++k)
  {
    printf(" %d [colorscheme=%s,fillcolor=%d,style=filled];", 
           k, 
           "pastel13",
           1 + colour[k]);
  }

  int printed[MAX_NODES] = {0};

  for(int k = 0; k < n; ++k)
  {
    for(int j = 0; j < adjacency[k][V]; ++j) 
    {
      if(!printed[adjacency[k][j]]) 
        printf(" %d -- %d;", k, adjacency[k][j]);
    }
    printed[k] = true;
  }

  printf(" }\n");
}

void dump_adj(const int n)
{
  printf("%d NODES:\n", n);
  
  for(int k = 0; k < n; ++k)
  {
    printf("%d:", k);
    for(int j = 0; j < adjacency[k][V]; ++j) 
      printf(" %d", adjacency[k][j]);
    printf("\n");
  }
}

int main()
{
  int n, l;
  int a, b;
  int t = 0;
  deque<int> pending;

  while(scanf("%d\n%d\n", &n, &l))
  {
    DEBUG(printf("======= TEST %d => n = %d l = %d\n", ++t, n, l));

    for(int i = 0; i < n; ++i)
    {
      colour[i] = 0;
      adjacency[i][V] = 0;
    }

    if(n == 0) break;

    for(int i = 0; i < l; ++i)
    {
      if(scanf("%d %d\n", &a, &b));

      adjacency[a][adjacency[a][V]++] = b;
      adjacency[b][adjacency[b][V]++] = a;
    }

    bool ok = true;

    pending.clear();

    pending.push_back(0);
    colour[0] = 1;

    int x, y, c, k;

    while(ok && !pending.empty())
    {
      x = pending.front();
      pending.pop_front();

      c = colour[x] % 2 + 1;

      for(k = 0; k < adjacency[x][V]; ++k)
      {
        y = adjacency[x][k];

        if(!colour[y]) 
        { 
          colour[y] = c;
          pending.push_back(y);
        }
        else if(colour[y] != c)
        {
          ok = false;
          break;
        }
      }
    }

    // int k, c, x;

    // while(ok && pending[V*V] > 0)
    // {
    //   k = pending[--pending[V*V]];

    //   c = (colour[k] == 0) ? 1 : (colour[k] == 1) ? 2 : 1;

    //   DEBUG(printf("CONSIDER %d COLOUR %d NEXT %d\n", k, colour[k], c));

    //   for(int i = 0; i < adjacency[k][V]; ++i)
    //   {
    //     x = adjacency[k][i];

    //     if(!colour[x])
    //     {
    //       colour[x] = c;
    //       pending[pending[V*V]++] = k;
    //       pending[pending[V*V]++] = i;
    //       DEBUG(printf("VISIT %d SET %d\n", x, colour[x]));
    //     }
    //     else if(colour[x] != c)
    //     {
    //       ok = false;
    //       break;
    //     }
    //   }
    // }

    DEBUG(graphviz(n));
    DEBUG(dump_adj(n));
    if(ok)
      printf("BICOLORABLE.\n");
    else
      printf("NOT BICOLORABLE.\n");
  }

  return 0;
}
