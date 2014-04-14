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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t;

  if(scanf("%d", &t));

  DEBUG(printf("T = %d\n", t));

  for(int s = 1; s <= t; ++s)
  {
    int x, y, z;

    if(scanf("%d %d %d", &x, &y, &z));

    if(x <= 20 && y <= 20 && z <= 20)
      printf("Case %d: good\n", s);
    else
      printf("Case %d: bad\n", s);
  }
  
  return 0;
}
