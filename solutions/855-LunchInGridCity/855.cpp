#include <cstdio>
#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const size_t F_MAX = 65535;

int main()
{
  int t, s, a, f;

  if(scanf("%d", &t));

  for(int c = 0; c < t; ++c)
  {
    if(scanf("%d %d %d", &s, &a, &f));

    unsigned short streets[F_MAX];
    unsigned short avenues[F_MAX];

    for(int i = 0; i < f; ++i) if(scanf("%hu %hu", &streets[i], &avenues[i]));

    sort(streets, streets + f);
    sort(avenues, avenues + f);

    size_t mid = (f + 1) / 2;

    if(f % 2 == 0) mid = f / 2;

    printf("(Street: %d, Avenue: %d)\n", streets[mid - 1], avenues[mid - 1]);
  }

  return 0;
}
