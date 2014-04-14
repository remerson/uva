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
#include <sstream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_C = 24;
const int MAX_B = 1024;

int i;
int c[MAX_C];
int d;

inline long long term(int n)
{
  long long t = c[0];
  long long v = n;

  for(int j = 1; j <= i; ++j)
  {
    t += c[j] * v;
    v *= n;
  }

  DEBUG(printf("n = %d t = %lld\n", n, t));

  return t;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int C;

  if(scanf("%d", &C));

  for(int t = 0; t < C; ++t)
  {
    DEBUG(printf("=========== t = %d\n", t));

    int k;

    if(scanf("%d", &i));

    DEBUG(printf("i = %d\n", i));

    for(int j = 0; j <= i; ++j)
      if(scanf("%d", &c[j]));
    
    DEBUG(printf("c ="); for(int j = 0; j <= i; ++j) printf(" %d", c[j]); printf("\n"));

    if(scanf("%d", &d));
    if(scanf("%d", &k));

    DEBUG(printf("d = %d k = %d\n", d, k));

    int s = 0;

    int j = 1;
    long long u;

    // Calculate k'th term
    while(s < k)
    {
      u = term(j);
      s += j * d;
      ++j;
    }

    printf("%lld\n", u);
  }
  

  return 0;
}
