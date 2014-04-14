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

const int MAX_N = 101;

bitset<MAX_N> is_prime;
int primes[MAX_N];

int factors[MAX_N][MAX_N];

void sieve()
{
  is_prime.flip();

  is_prime[0] = false;
  is_prime[1] = false;

  primes[0] = 0;

  for(int i = 2; i < MAX_N; ++i)
    if(is_prime[i])
    {
      primes[++primes[0]] = i;
      DEBUG(printf("prime[%d] = %d\n", primes[0], primes[primes[0]]));
      for(int j = i * i; j < MAX_N; j += i)
        is_prime[j] = false;
    }

}

// basic by trial division
void trial()
{
  for(int i = 2; i < MAX_N; ++i)
  {
    int n = i;
    int p;

    DEBUG(printf("Start factoring n = %d\n", n));

    for(p = 1; p <= primes[0]; ++p)
      factors[n][p] = 0;

    p = 1;

   
    while(n > 1)
    {
      // try to take out p, j times
      while(n % primes[p] == 0)
      {
        n /= primes[p];
        ++factors[i][p];
        DEBUG(printf("n = %d factors[%d][%d] = %d\n", n, i, primes[p], factors[i][p]));
      }

      ++p;
    }
  }
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
 
  sieve();
  trial();

  int n;

  while(scanf("%d\n", &n))
  {
    DEBUG(printf("N = %d\n", n));

    if(n == 0)
      break;

    int f[MAX_N] = {0};

    // sum
    for(int j = 2; j <= n ; ++j)
      for(int k = 1; k <= primes[0]; ++k)
        f[k] += factors[j][k];

    int count = 0;

    printf("%3d! =", n);
    for(int k = 1; k <= primes[0] && f[k] > 0; ++k)
    {
      ++count;
      if(count == 16)
      {
        printf("\n      ");
        count = 1;
      }

      printf("%3d", f[k]);

    }

    printf("\n");
  }

  return 0;
}
