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
#define DEBUG(X) { X; fflush(stdout); }
#else
#define DEBUG(X)
#endif

using namespace std;

inline bool make_fraction(int k, int x, int &y)
{
  DEBUG(printf("make_fraction %d %d %d\n", k, x, y));
  bool found = false;
  int v = (x * k) / (x - k);

  const int n = x * v;
  const int d = x + v;
  DEBUG(printf("attempt n = %d d = %d k = %d x = %d y = %d\n", n, d, k, x, y));
  if(k * d == n)
  {
    y = v;
    found = true;
  }

  return found;
}

inline void print_fraction(int k, int x, int y)
{
  printf("1/%d = 1/%d + 1/%d\n", k, x, y);
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int k;

  const int K_MAX = 10000;

  int x_vals[K_MAX];
  int y_vals[K_MAX];

  while(scanf("%d", &k) == 1)
  {
    DEBUG(printf("k = %d\n", k));

    int x, y, c = 0;

    x_vals[0] = 0;
    y_vals[0] = 0;

    x = k + 1;
    y = (x * k) / (x - k);

    DEBUG(printf("initial %d %d %d\n", k, x, y));

    // must be at least 1
    while(x <= y)
    {
      if(make_fraction(k, x, y))
      {
        x_vals[++x_vals[0]] = x;
        y_vals[++y_vals[0]] = y;
        ++c;
      }
      ++x;

    };


    printf("%d\n", c);

    for(int i = 1; i <= c; ++i)
      print_fraction(k, y_vals[i], x_vals[i]);
    
  }

  return 0;
}
