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

const int SQRT_N = 1000;
const int MAX_N = SQRT_N * SQRT_N;
const int HALF_N = MAX_N / 2;

bitset<HALF_N> is_prime;

void sieve()
{
  is_prime.flip();

  for(int n = 3; n <= SQRT_N; n += 2)
    if(is_prime[n>>1])
      for(int j = n * n; j < MAX_N; j += (n<<1))
	is_prime[j>>1] = false;
}

int to_int(char *buffer)
{
  int v = 0;
  char *s = &buffer[0];

  do
  {
    v *= 10;
    v += *s - '0';
    ++s;
  } while(*s);

  DEBUG(printf("INT [%s] => %d\n", &buffer[0], v));
  return v;
}

char *reverse(char *buffer)
{
  char *u = buffer;
  char *v = u;

  while(*v)
    ++v;
  --v;

  while(u < v)
  {
    char t = *u;
    *u = *v;
    *v = t;
    ++u;
    --v;
  }

  DEBUG(printf("REVERSE [%s]\n", &buffer[0]));

  return buffer;
}

int main()
{
  sieve();

  int B_MAX = 32;

  char buffer[B_MAX];

  while(fgets(buffer, B_MAX, stdin))
  {
    char *s = &buffer[0];

    while(*s)
    {
      if(*s == '\n')
      {
	*s = '\0';
	break;
      }
      ++s;
    }

    DEBUG(printf("READ [%s]\n", &buffer[0]));

    int v1 = to_int(buffer);

    if(v1 == 2)
      printf("%d is prime.\n", v1);
    else if((v1 & 1) && is_prime[v1>>1])
    {
      // v1 prime
      reverse(buffer);
      int v2 = to_int(buffer);

      if((v2 & 1) && is_prime[v2>>1] && v2 > 10 && v1 != v2)
	printf("%d is emirp.\n", v1);
      else
	printf("%d is prime.\n", v1);
    }
    else
      printf("%d is not prime.\n", v1);
  }

  return 0;
}
