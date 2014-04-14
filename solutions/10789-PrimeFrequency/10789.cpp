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

const int MAX_N = 2048;

bitset<MAX_N> prime;

char input[MAX_N];

void sieve()
{
  for(int i = 0; i < MAX_N; ++i) prime[i] = true;

  prime[0] = false;
  prime[1] = false;

  const int upp = sqrt(static_cast<double>(MAX_N)) + 1;

  DEBUG(printf("upper = %d\n", upp));

  for(int j = 4; j < MAX_N; j += 2) prime[j] = false; 
      
  for(int i = 3; i <= upp; i += 2)
  {
    if(prime[i])
    {
      DEBUG(printf("test prime[%d]\n", i));
      for(int j = i; j < MAX_N; j += i) 
      {
        DEBUG(printf("mark not prime[%d]\n", j));
        prime[j] = false;
      }
      DEBUG(printf("mark prime[%d]\n", i));
      prime[i] = true;
    }
  }

  for(int i = 0; i < MAX_N; ++i) if(prime[i]) DEBUG(printf("prime[%d]\n", i));
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  sieve();

  int n;

  if(scanf("%d", &n));

  for(int t = 1; t <= n; ++t)
  {
    int freq[256] = {0};

    if(scanf("%s", input));

    char *p = input;

    DEBUG(printf("INPUT [%s]\n", input));

    while(*p != '\0') ++freq[*p], ++p;

    printf("Case %d: ", t);

    bool found = false;

    for(int j = 0; j <= 255; ++j)
    {
      if(prime[freq[j]])
      {
        DEBUG(printf("freq[%d] = %d\n", j, freq[j]));
        found = true;
        printf("%c", j);
      }
    }

    if(!found) printf("empty");
    printf("\n");
  }

  return 0;
}
