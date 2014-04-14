#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <bitset>
#include <list>
#include <iterator>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const unsigned A = 0xAAAAAAAA;
const unsigned B = 0x55555555;

int main()
{
  unsigned n;

  while(scanf("%u", &n))
  {
    if(n == 0) break;
    unsigned a = 0;
    bool assign = true;

    for(int i = 0; i < 32; ++i)
    {
      const unsigned mask = 1 << i;
      if(mask & n)
      {
        if(assign)
        {
          a = a | (mask & n);
          assign = false;
        }
        else
          assign = true;
      }
    }

    printf("%u %u\n", a, n - a);
  }

  return 0;
}
