#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const int N_MAX = 8;

int coords_x[N_MAX];
int coords_y[N_MAX];

double dist[N_MAX][N_MAX];

using namespace std;

int main()
{
  int n;
  int t = 1;

  while(scanf("%d", &n))
  {
    if(n == 0) break;

    int nodes[N_MAX];

    DEBUG(printf("START n = %d\n", n));

    for(int i = 0; i < n; ++i)
    {
      scanf("%d %d", &coords_x[i], &coords_y[i]);
      nodes[i] = i;
      DEBUG(printf("READ x = %d y = %d n = %d\n", coords_x[i], coords_y[i], nodes[i]));
    }

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
      {
        if(i == j) dist[i][j] = 0.0;
        else
        {
          const double x = coords_x[i] - coords_x[j];
          const double y = coords_y[i] - coords_y[j]; 
          dist[i][j] = sqrt(x * x + y * y) + 16.0;
          DEBUG(printf("DIST %d %d = %.2f x = %.4f y = %.4f\n", i, j, dist[i][j], x, y));
        }
      }

    double min_dist = -1.0;

    int path[N_MAX] = {0};
    do
    { 
      DEBUG(printf("NODES:"); for(int i = 0; i < n; ++i) printf(" %d", nodes[i]); printf("\n"));

      double calc_dist = 0.0;
      for(int i = 1; i < n; ++i)
        calc_dist += dist[nodes[i]][nodes[i - 1]];

      DEBUG(printf("calc_dist = %.2f min_dist = %.2f\n", calc_dist, min_dist));

      if(min_dist == -1.0 || calc_dist < min_dist)
      {
        min_dist = calc_dist;
        memcpy(&path[0], &nodes[0], n * sizeof(int));
        DEBUG(printf("FOUND min_dist = %.2f\n"));
      }

    } while(next_permutation(nodes, nodes + n));

    printf("**********************************************************\n");
    printf("Network #%d\n", t++);
    for(int i = 1; i < n; ++i)
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", 
             coords_x[path[i - 1]],
             coords_y[path[i - 1]],
             coords_x[path[i]],
             coords_y[path[i]],
             dist[path[i - 1]][path[i]]);
    printf("Number of feet of cable required is %.2f.\n", min_dist);
      
  }

  return 0;
}
