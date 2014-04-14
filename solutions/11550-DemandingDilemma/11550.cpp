#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using std::bitset;

const size_t N_MAX = 48;

const size_t M_MAX = (N_MAX * (N_MAX - 1)) / 2;

const size_t B_MAX = M_MAX * 3;

char buffer[B_MAX];

int main()
{  
  int t;

  // The number of vertices for edge j
  char vertex_count[M_MAX];
  char connected[N_MAX][N_MAX];
  char start[N_MAX];

  if(scanf("%d", &t));
  DEBUG(printf("TESTS = %d\n", t));

  for(int q = 0; q < t; ++q)
  {
    int n, m;
    if(scanf("%d %d\n", &n, &m));

    DEBUG(printf("N = %d M = %d\n", n, m));

    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        connected[i][j] = 0;
      
    for(int i = 1; i <= m; ++i)
    {
      vertex_count[i] = 0;
      start[i] = 0;
    }

    bool valid = true;

    for(int i = 1; i <= n; ++i)
    {
      if(m > 0)
      {
        fgets(buffer, B_MAX, stdin);
        DEBUG(printf("READ node %d buffer = [%s]\n", i, buffer));
      }

      for(int j = 1; j <= m && valid; ++j)
      {
        const size_t index = (j - 1) * 2;

        if(buffer[index] == '1')
        {
          ++vertex_count[j];
          DEBUG(printf("FOUND. Vertex count for edge %d = %d\n", j, vertex_count[j]));

          if(vertex_count[j] > 2)
          {
            DEBUG(printf("INVALID. Too many (> 2) vertices for edge %d.\n", j));
            valid = false;
            continue;
          }

          DEBUG(printf("Edge %d joins node %d to...", j, i));
          if(start[j] == 0)
          {
            start[j] = i;
            DEBUG(printf("... not sure yet. \n"));
          }
          else
          {
            DEBUG(printf("... node %d. Connect.\n", start[j]));

            if(connected[i][start[j]] || connected[start[j]][i])
            {
              DEBUG(printf("INVALID These two nodes are already connected.\n"));
              valid = false;
            }
            else
            {
              connected[i][start[j]] = 1;
              connected[start[j]][i] = 1;
            }
          }
        }
      }
    }

    for(int j = 1; j <= m && valid; ++j)
    {
      if(vertex_count[j] != 2)
        valid = false;
    }

    if(valid)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
