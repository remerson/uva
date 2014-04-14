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

const unsigned N_MAX = 1024 * 1024;

bitset<N_MAX> red;
bitset<N_MAX> blue;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n;

  if(scanf("%d", &n));
  DEBUG(printf("N = %d\n", n));
  for(int t = 0; t < n; ++t)
  {
    for(size_t i = 0; i < N_MAX; ++i) red[i] = 0, blue[i] = 0;
    int c;
    if(scanf("%d", &c));
    DEBUG(printf("C = %d\n", c));
    int low = N_MAX, high = 0;
    for(int i = 0; i < c; ++i)
    {
      int x;
      if(scanf("%d", &x));
      DEBUG(printf("READ x = %d\n", x));
      if(x > 0)
      {
        DEBUG(printf("RED %d\n", x));
        red[x] = 1;
      }
      else
      {
        x *= -1;
        DEBUG(printf("BLUE %d\n", x));
        blue[x] = 1;
      }
      if(x < low) 
      {
        DEBUG(printf("LOW = %d\n", x));
        low = x;
      }
      if(x > high) 
      {
        DEBUG(printf("HIGH = %d\n", x));
        high = x;
      }
    }
    
    size_t l = 0;
    bool match = red[low];

    DEBUG(printf("PASS 1: Low = %d High = %d\n", low, high));

    for(int k = low; k <= high; ++k)
    {
      if(red[k] == 0 && blue[k] == 0) continue;

      DEBUG(printf("l = %u Match = %c R[%d] = %c B[%d] = %c\n", l, match ? 'R' : 'B', k, red[k] ? '1' : '0', k, blue[k] ? '1' : '0'));

      if(red[k])
      {
        if(match)
        {
          ++l;
          DEBUG(printf("MATCH RED l = %d\n", l));
        }
        match = false;
//         else
//         {
//           if(l > max_l) max_l = l;
//           l = 1;        
//           match = false;
//           DEBUG(printf("NO MATCH RED - RESET max = %d\n", max_l));
//         }
      }
      else
      {
        if(!match)
        {
          ++l;
          DEBUG(printf("MATCH BLUE l = %d\n", l));
        }
        match = true;
//         else
//         {
//           if(l > max_l) max_l = l;
//           l = 1;
//           match = true;
//           DEBUG(printf("NO MATCH BLUE - RESET max = %d\n", max_l));
//         }
      }

    }

    //if(l > max_l) max_l = l;

    printf("%u\n", l);
  }

  return 0;
}
