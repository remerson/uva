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

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int p, a, b, c, d, n;

  while(scanf("%d %d %d %d %d %d\n", &p, &a, &b, &c, &d, &n) != EOF)
  {
    double high {0.0};
    double low {999999999999.0};
    double drop {0.0};
    
    for(int k = 1; k <= n; ++k)
    {      
      double price = p * (sin(a * k + b) + cos(c * k + d) + 2);

      DEBUG(printf("PRICE %d = %f high = %f low = %f drop = %f\n", k, price, high, low, drop));
      
      if(price > high)
      {
        high = price;
        low = 999999999999.0;
      }
      if(price < low)
      {
        low = price;
        drop = max(drop, high - low);
      }
    }

    printf("%.6lf\n", drop);
  }

  return 0;
}
