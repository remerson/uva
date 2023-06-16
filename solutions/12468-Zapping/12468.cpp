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

  int a, b;

  while(scanf("%d %d\n", &a, &b))
  {
    if(a == -1 && b == -1)
      break;

    int high = max(a, b);
    int low = min(a, b);

    printf("%d\n", min(high - low, low + 100 - high));
  }
  
  return 0;
}
