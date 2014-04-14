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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  unsigned short n;

  unsigned short a;
  unsigned short b;

  printf("PERFECTION OUTPUT\n");

  while(scanf("%u", &n) == 1 && n > 0)
  {
    // reset
    a = 1;

    unsigned total = 0;

    do
    {
      b = n / a;
      DEBUG(printf("TEST %u %u\n", a, b));
      if(a * b == n)
      {
        DEBUG(printf("FACTOR %u %u\n", a, b));

        if(a == b)
          total += a;
        else
          total += a + b;
      }
      ++a;
    }
    while(a < b);

    total -= n;

    DEBUG(printf("total = %u\n", total));

    if(total == n)
      printf("%5u  PERFECT\n", n);
    else if(total > n)
      printf("%5u  ABUNDANT\n", n);
    else
      printf("%5u  DEFICIENT\n", n);
  }
  
  printf("END OF OUTPUT\n");

  return 0;
}
