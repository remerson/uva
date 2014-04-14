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

const size_t C_MAX = 10;

unsigned counts[C_MAX];

void dump()
{
  printf("%d", counts[0]);
  for(size_t i = 1; i < C_MAX; ++i)
    printf(" %d", counts[i]);
  printf("\n");
}

inline void add(unsigned n)
{
  unsigned top = n;

  const unsigned d1 = top / 1000;
  top -= d1 * 1000;

  const unsigned d2 = top / 100;
  top -= d2 * 100;

  const unsigned d3 = top / 10;
  top -= d3 * 10;

  const unsigned d4 = top;

  if(d1 > 0)
  {
    ++counts[d1];
    ++counts[d2];
    ++counts[d3];
    ++counts[d4];
  }
  else if(d2 > 0)
  {
    ++counts[d2];
    ++counts[d3];
    ++counts[d4];
  }
  else if(d3 > 0)
  {
    ++counts[d3];
    ++counts[d4];
  }
  else if(d4 > 0)
    ++counts[d4];

}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  unsigned v, n;

  if(scanf("%u\n", &v));

  DEBUG(printf("SETS = %u\n", v));

  for(unsigned t = 0; t < v; ++t)
  {
    memset(counts, 0, sizeof(unsigned) * C_MAX);
    if(scanf("%u\n", &n));
    DEBUG(printf("===== N = %u\n", n));

    for(unsigned i = 1; i <= n; ++i)
      add(i);

    dump();
  }


  return 0;
}
