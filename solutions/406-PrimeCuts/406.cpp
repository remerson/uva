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

const size_t MAX_PRIME = 1024;

bitset<MAX_PRIME> is_prime;

unsigned primes[MAX_PRIME];

void sieve()
{
  for(size_t i = 0; i < MAX_PRIME; ++i) is_prime[i] = true;

  is_prime[0] = false;
  is_prime[1] = true;
  
  primes[1] = 1;
  primes[2] = 2;

  size_t max_index = 3;

  for(size_t i = 2; i < MAX_PRIME; ++i)
  {
    if(is_prime[i])
    {
      for(size_t j = i; j < MAX_PRIME; j += i) is_prime[j] = false;
      is_prime[i] = true;
      if(i != 2) primes[max_index++] = i;
    }
  }

  for(size_t i = 0; i < MAX_PRIME; ++i) if(is_prime[i]) DEBUG(printf("is_prime[%zu]\n", i));
  for(size_t i = 0; i < MAX_PRIME; ++i) DEBUG(printf("primes[%zu] = %u\n", i, primes[i]));
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  unsigned n, c;

  sieve();

  while(scanf("%u %u\n", &n, &c) == 2)
  {
    DEBUG(printf("==== N = %u C = %u\n", n, c));

    size_t l = 1;

    while(true)
    {
      ++l;
      if(primes[l] > n)
      {
        --l;
        break;
      }
    }

    DEBUG(printf("l = %zu\n", l));
    
    DEBUG(printf("Complete list of primes between 1 and %u:\n", n); for(unsigned k = 1; k <= l; ++k) printf(" %u", primes[k]); printf("\n"););

    int plen = 2 * c;

    int lo = 1;

    if(plen > l)
    {
      plen = l;
    }
    else
    {
      if(l % 2 == 0)
      {
        lo = l / 2 - c + 1;
      }
      else
      {
        lo = l / 2 - c + 2;
        --plen;
      }
    }

    int hi = lo + plen;

    DEBUG(printf("plen = %d lo = %zu hi = %zu\n", plen, lo, hi));

    printf("%u %u:", n, c);

    for(size_t k = lo; k < hi; ++k)
      printf(" %u", primes[k]);

    printf("\n\n");
      
  }
  
  return 0;
}
