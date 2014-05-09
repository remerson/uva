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

const int SQRT_N = 36;
const int MAX_N = SQRT_N * SQRT_N;
const int HALF_N = MAX_N / 2;

bitset<HALF_N> is_prime;

void generate_primes()
{
  is_prime.flip();

  for(int n = 3; n <= SQRT_N; n += 2)
    if(is_prime[n>>1])
    {
      for(int j = n * n; j <= MAX_N; j += 2 * n)
	is_prime[j>>1] = false;
    }

  DEBUG(for(int i = 3; i <= MAX_N; i += 2) if(is_prime[i>>1]) printf("found prime %d\n", i););
}

int score(char *word)
{
  int v = 0;
  char *orig = word;

  while(*word && *word != '\n')
  {
    int c = 0;

    if(*word >= 'a' && *word <= 'z')
      c = *word - 'a' + 1;
    else if(*word >= 'A' && *word <= 'Z')
      c = *word - 'A' + 1 + 26;

    v += c;

    DEBUG(printf("score %c = %d v = %d\n", *word, c, v));
    ++word;
  }

  DEBUG(printf("SCORE [%s] = %d\n", orig, v));
  return v;
}

int main()
{
  const size_t L_MAX = 32;
  char word[L_MAX];

  generate_primes();

  while(fgets(&word[0], L_MAX, stdin) != 0)
  {
    DEBUG(printf("READ [%s]\n", word));

    const int s = score(&word[0]);

    if((s == 2) || ((s & 1) && is_prime[s>>1]))
      printf("It is a prime word.\n");
    else
      printf("It is not a prime word.\n");
  }
  
  return 0;
}
