#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  int t;

  if(scanf("%d", &t));

  for(int i = 1; i <= t; ++i)
  {
    int n, m, x;

    if(scanf("%d %d", &n, &m));

    x = m;

    for(int j = 1; j < n; ++j)
      if(scanf("%d", &m) && m > x)x= m;

    printf("Case %d: %d\n", i, x);

  }

  return 0;
}
