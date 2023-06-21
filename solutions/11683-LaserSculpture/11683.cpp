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

//using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int A, C;

  while(scanf("%d %d\n", &A, &C) != EOF)
  {
    if(A == 0 || C == 0)
      break;

    int heights[128 * 128] = {0};

    for(int i = 0; i < C; ++i)
    {
      if(scanf("%d", &heights[i]));
      DEBUG(printf("READ heights[%d] = %d\n", i, heights[i]));
    }

    // TLE
    //int count = 0;
    //bool on {false};

    // TLE
    // for(int i = A; i >= 0; --i)
    // {
    //   for(int j = 0; j < C; ++j)
    //   {
    //     DEBUG(printf("DEPTH %d heights[%d] = %d on = %s\n", i, j, heights[j], on ? "true" : "false"));
        
    //     if(heights[j] < i)
    //     {
    //       if(!on)
    //       {
    //         on = true;
    //         ++count;
    //       }
    //     }
    //     else
    //     {
    //       on = false;
    //     }
    //   }
    //   on = false;
    // }
    int prev_depth = A - heights[0];
    int count = prev_depth;

    for(int i = 1; i < C; ++i)
    {
      int depth = A - heights[i];

      if(depth <= prev_depth)
      {
        
      }
      else
      {
        count += (depth - prev_depth);
      }

      prev_depth = depth;
    }
    
    
    printf("%d\n", count);
  }

  

  return 0;
}
