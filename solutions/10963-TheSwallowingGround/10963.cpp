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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int t;

  if(scanf("%d\n", &t));

  DEBUG(printf("T = %d\n", t));

  for(int s = 0; s < t; ++s)
  {
    if(s > 0)
      printf("\n");
    int w;
    if(scanf("%d\n", &w));
    DEBUG(printf("W = %d\n", w));

    int a, b;
    if(scanf("%d %d\n", &a, &b));

    int gap = a - b;
    DEBUG(printf("gap = %d\n", gap));
    
    bool valid = true;

    for(int i = 1; i < w; ++i)
    {
      if(scanf("%d %d\n", &a, &b));
      const int g = a - b;
      DEBUG(printf("g = %d a = %d b = %d\n", g, a, b));
      if(g != gap)
	valid = false;
    }
     
    if(valid)
      printf("yes\n");
    else
      printf("no\n");
  }
  

  return 0;
}
