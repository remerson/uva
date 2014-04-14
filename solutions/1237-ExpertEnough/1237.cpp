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

const int N_MAX = 24;
const int D_MAX = 10000;

char names[D_MAX][N_MAX];

struct Price
{
  int lower;
  int upper;
  unsigned short index;
};

Price prices[D_MAX];

struct PriceCompare
{
  bool operator()(const Price &lhs, const Price &rhs)
  {
    return lhs.lower < rhs.lower;
  }
};

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t;

  if(scanf("%d", &t));

  DEBUG(printf("T = %d\n", t));

  for(int s = 0; s < t; ++s)
  {
    int d;

    if(scanf("%d", &d));

    DEBUG(printf("D = %d\n", d));

    for(int i = 0; i < d; ++i)
    {
      if(scanf("%s %d %d\n", &names[i][0], &prices[i].lower, &prices[i].upper));
      DEBUG(printf("read %d name = [%s] lower = %d upper = %d\n", i, &names[i][0], prices[i].lower, prices[i].upper));
      prices[i].index = i;
    }

    int q, p;

    PriceCompare comp;

    sort(prices, prices + d, comp);

    if(scanf("%d", &q));

    DEBUG(printf("Q = %d\n", q));

    if(s > 0)
      printf("\n");

    for(int i = 0; i < q; ++i)
    {
      if(scanf("%d", &p));

      DEBUG(printf("p = %d\n", p));

      int match = -1;

      for(int j = 0; j < d; ++j)
      {
        DEBUG(printf("check p = %d j = %d lower = %d upper = %d\n", p, j, prices[j].lower, prices[j].upper));

        if(p >= prices[j].lower && p <= prices[j].upper)
        {
          if(match == -1)
          {
            DEBUG(printf("found match = %d\n", j));
            match = prices[j].index;
          }
          else
          {
            DEBUG(printf("multiple match\n"));
            match = -1;
            break;
          }
        }
      }

      if(match != -1)
        printf("%s\n", names[match]);
      else
        printf("UNDETERMINED\n");
    }
  }

  return 0;
}
