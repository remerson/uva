#include <cstdio>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 500;
const int M_MAX = 100;

bool sums_to[N_MAX * M_MAX];
int coins[M_MAX];

int main()
{
  int c, m, i, j, r, total_sum, half_sum, gap;

  if(scanf("%d", &c) == 1);

  for(int t = 0; t < c; ++t)
  {
    if(scanf("%d", &m) == 1);

    total_sum = 0;

    for(i = 0; i < m; ++i) 
    {
      if(scanf("%d", &coins[i]));
      total_sum += coins[i];
    }

    DEBUG(printf("COINS: "));
    for(i = 0; i < m; ++i) DEBUG(printf("%d ", coins[i]));
    DEBUG(printf("\n"));
    
    sort(coins, coins + m);

    for(i = 1; i <= total_sum; ++i) sums_to[i] = false;
    sums_to[0] = true;

    r = 0;

    half_sum = total_sum / 2;
    gap = total_sum % 2;

    for(i = 0; i < m; ++i)
    {
      r = min(half_sum, r + coins[i]);
      for(j = r; j >= 0; j--) if(sums_to[j]) sums_to[j + coins[i]] = true;
    }

    for(i = 0; i <= total_sum; ++i) DEBUG(printf("sums_to[%d] ? %s\n", i, sums_to[i] ? "true" : "false"));
    

    DEBUG(printf("half_sum = %d gap = %d\n", half_sum, gap));

    j = half_sum;
    r = half_sum + gap;
    while(!sums_to[j]) --j;
    while(!sums_to[r]) ++r;
    printf("%d\n", r - j);

  }

  return 0;
}
