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

const size_t MAX_N = 128;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int n;

  while(scanf("%d", &n))
  {
    DEBUG(printf("N = %d\n", n));
    if(n == 0)
      break;

    bool found = false;

    const int v = n * (n + 1) / 2;

    for(int m = 1; m < v && !found; ++m)
    {
      DEBUG(printf("===== attempt m = %d\n", m));

      int remain = n - 1;
      bitset<MAX_N> stations;
      stations.flip();

      stations[1] = false;

      int p = 1;

      while(remain > 0)
      {
        int count = 0;
        
        while(count < m)
        { 
          ++p;
          
          if(p > n)
            p = 1;

          if(stations[p])
            ++count;
        }      
        
        // Strike off the station at this position
        stations[p] = false;
        --remain;

        DEBUG(printf("strike off p = %d remain = %d\n", p, remain));

        if(p == 13)
        {
          if(remain == 0)
          {
            printf("%d\n", m);
            found = true;
          }
          break;
        }
      }

    }
  }

  return 0;
}
