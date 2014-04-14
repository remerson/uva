#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 10000;
const int K_MAX = 1000000000;

int main()
{
  int t, n, k, v = 0;

  scanf("%d\n", &t);

  DEBUG(printf("t = %d\n", t));

  for(int j = 1; j <= t; ++j)
  {
    scanf("%d %d\n", &n, &k);

    DEBUG(printf("n = %d k = %d\n", n, k));

    //v = josephus(n, k);
    v = 0;

    for(int i = 1; i <= n; ++i)
    {
      v = (v + k) % i;
    }

    printf("Case %d: %d\n", j, v + 1);
  }

  return 0;
}
