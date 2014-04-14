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

const unsigned MAX_N = 8;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int n;

  while(scanf("%d\n", &n) == 1)
  {
    DEBUG(printf("N = %d\n", n));

    unsigned range = 0;

    switch(n)
    {
    case 2:
      range = 10;
      break;
    case 4:
      range = 100;
      break;
    case 6:
      range = 1000;
      break;
    case 8:
      range = 10000;
      break;
    }

    DEBUG(printf("range = %d\n", range));

    for(unsigned i = 0; i < range; ++i)
    {
      const unsigned s = i * i;
      DEBUG(printf("i = %u s = %u\n", i, s));
      const unsigned u = s - (s / range) * range;
      const unsigned v = (s - u) / range;
      DEBUG(printf(" s = %u => %u %u\n", s, v, u));
      const unsigned t = (u + v) * (u + v);
      if(s == t)
        printf("%0*u\n", n, t);
    }

  }

  return 0;
}
