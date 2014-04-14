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

const unsigned C_MAX = 20;

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int n, l;

  while(scanf("%d", &n) == 1)
  {
    DEBUG(printf("==== N = %d\n", n));

    if(scanf("%d", &l));

    short values[C_MAX];
    for(int i = 0; i < l; ++i)
      if(scanf("%hi", &values[i]));

    DEBUG(for(int i = 0; i < l; ++i) printf(" %d", values[i]); printf("\n"));

    int u = 0;

    for(int j = 0; j < l; ++j)
      u = (u | (1 << j));

    ++u;

    DEBUG(printf("N = %d u = %d\n", n, u));

    int max_len = 0;
    int c = 0;

    for(int i = u; i > 0; --i)
    {
      int len = 0;
      for(int j = 0; j < l; ++j)
      {
        if(i & (1 << j))
          len += values[j];
      }
      if(len > n) continue;

      if(len > max_len)
      {
        max_len = len;
        c = i;
      }
    }

    for(int j = 0; j < l; ++j)
      if(c & (1 << j))
        printf("%d ", values[j]);

    printf("sum:%d\n", max_len);

  }

  return 0;
}
