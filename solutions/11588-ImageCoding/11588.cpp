#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const unsigned MAX_RC = 32;


int main()
{
  unsigned n;

  if(scanf("%u", &n))
  {
    for(unsigned t = 1; t <= n; ++t)
    {
      unsigned r, c, m, n;
      
      if(scanf("%u %u %u %u\n", &r, &c, &m, &n));
      
      DEBUG(printf("r = %u c = %u m = %u n = %u\n", r, c, m, n));
      
      unsigned short counts[MAX_RC] = {0};
      
      unsigned short maxval = 0;
      
      for(unsigned i = 0; i < r; ++i)
      {
        char buffer[MAX_RC] = {0};
        char *b = fgets(buffer, MAX_RC, stdin);
        while(*b >= 65 && *b <= 90)
        {
          unsigned index = (unsigned) 90 - *b;
          ++counts[index];
          DEBUG(printf("READ b = %c index = %u\n", *b, index));
          if(counts[index] > maxval) maxval = counts[index];
          ++b;
        }
      }

      DEBUG(printf("maxval = %u\n", maxval));
      
      unsigned total = 0;
      
      for(unsigned i = 0; i < MAX_RC; ++i)
        if(counts[i] == maxval) total += counts[i];
      
      printf("Case %u: %u\n", t, total * m + ((r * c) - total) * n);
    }

  }
  return 0;
}

