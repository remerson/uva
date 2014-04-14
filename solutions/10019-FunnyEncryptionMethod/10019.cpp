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

// Not very efficient - reinterpret k as hex.
inline int as_hex(int k)
{
  char buffer[16] = {0};

  sprintf(buffer, "%d", k);

  DEBUG(printf("k = %d buffer = [%s]\n", k, buffer));

  int h = -1;

  sscanf(buffer, "%x", &h);

  DEBUG(printf("h = %d %x\n", h, h));

  return h;
}

inline int count_bits(int k)
{
  int count = 0;

  for(; k; ++count)
    k &= k - 1;

  DEBUG(printf("count_bits %d = %d\n", k, count));

  return count;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int n, m;

  if(scanf("%d", &n));

  DEBUG(printf("N = %d\n", n));

  for(int t = 0; t < n; ++t)
  {
    if(scanf("%d", &m));

    const int b1 = count_bits(m);

    const int b2 = count_bits(as_hex(m));

    printf("%d %d\n", b1, b2);
  }

  return 0;
}
