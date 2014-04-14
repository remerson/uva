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

const unsigned short MAX_N = 10010;

unsigned short numbers[MAX_N];

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  unsigned short z, i, m, l;
  unsigned c = 0;

  while(scanf("%hu %hu %hu %hu\n", &z, &i, &m, &l) == 4)
  {
    DEBUG(printf("Z = %u I = %u M = %u L = %u\n", z, i, m, l));
    if(z == 0 && i == 0 && m == 0 && l == 0)
      break;

    // generate the sequence
    bitset<MAX_N> generated;
    unsigned short n = 0;
    while(1)
    {
      //numbers[n++] = l;
      l = (z * l + i) % m;
      if(generated.test(l))
      {
        DEBUG(printf("BREAK at %u\n", l));
        break;
      }
      numbers[n++] = l;
      generated.set(l);
    }

    // scan forward to find occurance of l (what Floyd would call mu)
    unsigned short v = 0;

    while(numbers[v] != l)
      ++v;

    DEBUG(printf("v = %u\n", v));
   
    DEBUG(printf("n = %u\n", n));
    DEBUG(for(unsigned short k = 0; k < n; ++k) printf("numbers[%u] = %u\n", k, numbers[k]); );
    
    printf("Case %d: %u\n", ++c, n - v);
    
    
  }

  return 0;
}
