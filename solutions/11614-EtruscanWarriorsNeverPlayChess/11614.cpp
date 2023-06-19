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
  int T;

  if(scanf("%d\n", &T));

  for(int t = 0; t < T; ++t)
  {
    unsigned long long n;
    if(scanf("%llu\n", &n));

    unsigned long long k = floor(0.5 * ((sqrt(8 * n + 1) - 1)));

    printf("%llu\n", k);
    
  }
  

  return 0;
}
