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

const int MAX_F = 2048;
const int MAX_D = 1422;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int n;

  while(scanf("%d", &n) == 1)
  {
    DEBUG(printf("N = %d\n", n));
    if(n == 0) break;

    int stations[MAX_F];
    stations[0] = 0;

    for(int i = 0; i < n; ++i)
      if(scanf("%d", &stations[i]));

    sort(stations, stations + n);

    DEBUG(printf("STATIONS (%d):", n); for(int i = 0; i < n; ++i) printf(" %d", stations[i]); printf("\n"););

    // Two conditions must hold
    bool possible = true;

    // a) Absolute distance between two neighbouring stations must be <= 200
    for(int i = 1; i < n && possible; ++i)
      if(stations[i] - stations[i - 1] > 200)
        possible = false;

    // b) Distance between the last station and the end must be <= 100
    if( (MAX_D - stations[n - 1]) > 100)
      possible = false;

    if(possible)
      printf("POSSIBLE\n");
    else
      printf("IMPOSSIBLE\n");

  }
  

  return 0;
}
