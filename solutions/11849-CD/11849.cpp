#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const unsigned N_MAX = 1024 * 1024 * 2;

unsigned x[N_MAX];
unsigned y[N_MAX];

int main()
{
  unsigned n = 0, m = 0;

  while(scanf("%u %u", &n, &m))
  {
    DEBUG(printf("N = %u M = %u\n", n, m));
    if(n == 0 && m == 0) break;

    for(unsigned i = 0; i < n; ++i)
    {
      if(scanf("%u", &x[i]));
      DEBUG(printf("READ x[%u] = %u\n", i, x[i]));
    }

    for(unsigned i = 0; i < m; ++i)
    {
      if(scanf("%u", &y[i]));
      DEBUG(printf("READ y[%u] = %u\n", i, y[i]));
    }

    unsigned i = 0;
    unsigned j = 0;
    unsigned count = 0;

    while(i < n && j < m)
    {
      if(x[i] == y[j])
      {
        ++i;
        ++j;
        ++count;
      }
      else if(x[i] < y[j])
      {
        ++i;
      }
      else if(x[i] > y[j])
      {
        ++j;
      }
    }
    
    printf("%d\n", count);
  }

  return 0;
}
