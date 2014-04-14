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

const size_t MAX_N = 32;
const size_t MAX_L = 16;
const int TOO_LARGE = 1 << 26;

char names[MAX_N][MAX_L];

int adj[MAX_N][MAX_N];

void dump(unsigned short n)
{
  for(int i = 1; i <= n; ++i)
  {
    printf("%d:", i);
    for(int j = 1; j <= n; ++j)
      printf(" %d", adj[i][j]);
    printf("\n");
  }
}



int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int n, m, c = 0;

  while(scanf("%d %d\n", &n, &m) == 2)
  {
    DEBUG(printf("N = %d M = %d\n", n, m));
    if(n == 0 && m == 0)
      break;

    for(int i = 1; i <= n; ++i)
    {
      for(int j = 1; j <= n; ++j)
        adj[i][j] = TOO_LARGE;
      adj[i][i] = 0;
    }    

    for(int i = 1; i <= n; ++i)
      if(scanf("%s", &names[i][0]));
    
    for(int q = 0; q < m; ++q)
    {
      int i, j, k;
      if(scanf("%d %d %d", &i, &j, &k));
      adj[i][j] = adj[j][i] = k;
    }

    DEBUG(dump(n));

    // Classic
    for(int k = 1; k <= n; ++k)
      for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    DEBUG(dump(n));

    int min_cost = TOO_LARGE;
    int min_index = -1;

    for(int i = 1; i <= n; ++i)
    {
      int row_sum = 0;
      for(int j = 1; j <= n; ++j)
        if(adj[i][j] < TOO_LARGE)
          row_sum += adj[i][j];

      DEBUG(printf("row sum %d %s = %d\n", i, &names[i][0], row_sum));

      if(row_sum < min_cost)
      {
        min_cost = row_sum;
        min_index = i;
      }
    }

    printf("Case #%d : %s\n", ++c, &names[min_index][0]);
    
    
  }

  return 0;
}
