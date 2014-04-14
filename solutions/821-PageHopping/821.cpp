#include <iostream>
#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_N = 102;
const int MAX_INF = MAX_N;

int path[MAX_N][MAX_N];

int main()
{
  std::ios_base::sync_with_stdio(false);

  int a, b, n = 0, c = 0;

  for(int i = 0; i < MAX_N; ++i)
    for(int j = 0; j < MAX_N; ++j)
      path[i][j] = MAX_INF;

  while(scanf("%d %d", &a, &b))
  {
    if(a == 0 && b == 0)
    {
      if(n > 0)
      {
        DEBUG(printf("START N = %d\n", n));

        // FW DP
        for(int k = 1; k <= n; ++k)
          for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
              path[i][j] = min(path[i][j], path[i][k] + path[k][j]);

        int total = 0;
        int pairs = 0;

        for(int i = 1; i <= n; ++i)
          for(int j = 1; j <= n; ++j)
            if(i != j)
              if(path[i][j] < MAX_INF) 
              {
                ++pairs;
                total += path[i][j];
              }

        DEBUG(printf("TOTAL = %d PAIRS = %d\n", total, pairs));

        printf("Case %d: average length between pages = %0.3f clicks\n", ++c, static_cast<double>(total) / static_cast<double>(pairs));

        // reset
        n = 0;
        for(int i = 0; i < MAX_N; ++i)
          for(int j = 0; j < MAX_N; ++j)
            path[i][j] = MAX_INF;
      }  
      else
        break;
    }
    else
    {
      path[a][b] = 1;
      n = max(n, max(a, b));
    }
  }

  return 0;
}
