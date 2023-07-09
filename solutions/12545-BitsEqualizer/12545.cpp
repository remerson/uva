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
  int C;

  if(scanf("%d\n", &C));

  for(int c = 0; c < C; ++c)
  {
    const int MAX_T = 128;
    char s[MAX_T];
    char t[MAX_T];

    if(scanf("%s\n", &s[0]));
    if(scanf("%s\n", &t[0]));

    int change = 0;

    int t_swaps = 0;
    int s_swaps = 0;

    int len = strlen(s);
    int ones {0};
    
    for(int i = 0; i < len; ++i)
    {
      if(s[i] == '1' && t[i] == '0')
      {
        ++s_swaps;
      }
      if(s[i] == '0' && t[i] == '1')
      {
        ++t_swaps;
      }
      if(s[i] == '?')
      {
        ++change;
      }

      if(s[i] == '1')
        ++ones;
      if(t[i] == '1')
        --ones;      
    }

    DEBUG(printf("ones = %d change = %d s_swaps = %d t_swaps = %d\n", ones, change, s_swaps, t_swaps));

    if(ones > 0)
      change = -1;
    else
      change += std::max(s_swaps, t_swaps);
    
    printf("Case %d: %d\n", c+1, change);
    
  }

  return 0;
}
