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

///////////////////////////////////////////////////////////////////////////////

const int coins[] = {1, 5, 10, 25, 50};

const int MAX_N = 1 << 15;
const int MAX_M = sizeof(coins) / sizeof(int);

long long dp[MAX_M+1][MAX_N];

// Count number of ways to make n using only 0.. m-1 coins
long long count(int m, int n)
{
  DEBUG(printf("count(%d, %d)\n", m, n));

  if(n == 0)
    return 1;

  if(n < 0)
    return 0;

  if(m <= 0 && n >= 1)
    return 0;

  if(dp[m][n] == -1)
    dp[m][n] = count(m - 1, n) + count(m, n - coins[m - 1]);
  
  return dp[m][n];
}

int main()
{
  for(int i = 0; i < MAX_M+1; ++i)
    for(int j = 0; j < MAX_N; ++j)
      dp[i][j] = -1;

  int n;

  while(scanf("%d", &n) != EOF)
  {
    DEBUG(printf("n = %d\n", n));
    //printf("%d\n", count(MAX_M, n));
    const long long c = count(MAX_M, n);
    if(c == 1)
      printf("There is only 1 way to produce %d cents change.\n", n);
    else
      printf("There are %lld ways to produce %d cents change.\n", c, n);
  }
  
  return 0;
}
