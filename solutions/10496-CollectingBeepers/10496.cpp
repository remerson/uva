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

const int MAX_N = 11;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int scenarios;

  if(scanf("%d", &scenarios));

  DEBUG(printf("SCENARIOS %d\n", scenarios));
  
  for(int c = 0; c < scenarios; ++c)
  {
    int nodes_x[MAX_N];
    int nodes_y[MAX_N];

    int max_x, max_y;

    int nodes[MAX_N];

    if(scanf("%d %d", &max_x, &max_y));

    DEBUG(printf("max_x = %d max_y = %d\n", max_x, max_y));

    if(scanf("%d %d", &nodes_x[0], &nodes_y[0]));
    nodes[0] = 0;

    DEBUG(printf("INITIAL %d %d\n", nodes_x[0], nodes_y[0]));

    int b;

    if(scanf("%d", &b));

    DEBUG(printf("BEEPERS %d\n", b));

    for(int i = 1; i <= b; ++i)
    {
      if(scanf("%d %d", &nodes_x[i], &nodes_y[i]));
      nodes[i] = i;
      DEBUG(printf("nodes_x[%d] = %d nodes_y[%d] = %d\n", i, nodes_x[i], i, nodes_y[i]));
    }

    int dist[MAX_N][MAX_N];

    b++;

    for(int i = 0; i < b; ++i)
      for(int j = 0; j < b; ++j)
      {
        dist[i][j] = abs(nodes_x[i] - nodes_x[j]) + abs(nodes_y[i] - nodes_y[j]);
        DEBUG(printf("dist[%d][%d] = %d\n", i, j, dist[i][j]));
      }

    int min_dist = 20 * 20 * 20;
    
    do
    {
      DEBUG(printf("NODES:"); for(int i = 0; i < b; ++i) printf(" %d", nodes[i]); printf("\n"));

      //bool minimal = true;
      int length = dist[nodes[b - 1]][nodes[0]];
      for(int i = 1; i < b; ++i)
      {
        length += dist[nodes[i - 1]][nodes[i]];
        
        DEBUG(printf("LENGTH %d = %d\n", i, length));

        //if(length >= min_dist) minimal = false;
      }

      if(length < min_dist) min_dist = length;

    } while(next_permutation(nodes, nodes + b));

    printf("The shortest path has length %d\n", min_dist);
  }

  return 0;
}
