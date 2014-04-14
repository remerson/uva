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

const int N_MAX = 21;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int t;

  if(scanf("%d", &t));

  

  for(int w = 0; w < t; ++w)
  {
    int blocks[N_MAX];
    int power[N_MAX];
    int n, total = 0;
    if(scanf("%d", &n));
    for(int i = 0; i < n; ++i) 
    {
      scanf("%d", &blocks[i]);
      total += blocks[i];
      power[i] = 0;
    }

    //if(total % 2 != 0) ++total;
    const int majority = total / 2;
    
    DEBUG(printf("N = %d MAJORITY = %d\n", n, majority));
    unsigned int current = 0;
    const int upper = 1 << n;
    DEBUG(printf("UPPER = %d\n", upper));
    while(current < upper)
    {
      int score = 0;
      // Calculate the score for current
      for(int j = 0; j < n; ++j)
        if((1 << j) & current)
          score += blocks[j];

      DEBUG(printf("CURRENT = %d SCORE = %d MAJORITY = %d\n", current, score, majority));

      // If a majority can be formed
      if(score > majority)
      {
        // Try removing each party
        for(int j = 0; j < n; ++j)
          if((1 << j) & current)
            // If removing party j now no majority => power
            if(score - blocks[j] <= majority)
              ++power[j];
      }
      ++current;
    }

    for(int j = 0; j < n; ++j)
    {
      printf("party %d has power index %d\n", j+1, power[j]);
    }

    printf("\n");
  }

  return 0;
}
