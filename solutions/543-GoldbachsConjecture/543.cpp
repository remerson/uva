#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_N = 1000 * 1000;

bitset<MAX_N> is_prime;

int primes[MAX_N];

int max_index;

char input[MAX_N];

inline char *read_int(int &v, char *b)
{ 
  bool negative = false;
  v = 0;
  while(!isdigit(*b))
  {
    if(*b == '-')
      negative = true;
    ++b;
  }
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  if(negative) v *= -1;
  return b;
}

void sieve()
{
  for(int i = 0; i < MAX_N; ++i) is_prime[i] = true;

  is_prime[0] = false;
  is_prime[1] = false;
  
  max_index = 0;

  for(int i = 2; i < 1000; ++i)
  {
    if(is_prime[i])
    {
      for(int j = i; j < MAX_N; j += i) is_prime[j] = false;
      is_prime[i] = true;
      if(i != 2) primes[max_index++] = i;
    }
  }

  for(int i = 0; i < MAX_N; ++i) if(is_prime[i]) DEBUG(printf("is_prime[%d]\n", i));
  for(int i = 0; i < max_index; ++i) DEBUG(printf("primes[%d] = %d\n", i, primes[i]));
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  sieve();

  int n;

  char buffer[16];

  while(true)
  {
    char *b = fgets(buffer, 16, stdin);
    DEBUG(printf("BUFFER [%s]\n", buffer));
    b = read_int(n, b);

    if(n == 0) break;

    bool found = false;

    for(int i = 0; i < max_index; ++i)
    {
      if(primes[i] > n / 2)
        break;

      const int x = n - primes[i];

      if(is_prime[x])
      {
        printf("%d = %d + %d\n", n, primes[i], x);
        found = true;
        break;
      }
    }

    // !!!!
    if(!found)
      printf("Goldbach's conjecture is wrong.\n");
  }

  return 0;
}
