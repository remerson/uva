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
  int n;
  int p, c;

  if(scanf("%d", &t) == 1);

  for(int i = 1; i <= t; ++i)
  {
    int h = 0, l = 0;

    if(scanf("%d", &n) == 1);

    if(n < 1) continue;

    if(scanf("%d", &p) == 1);

    for(int j = 1; j < n; ++j)
    {
      if(scanf("%d", &c) == 1);

      if (c == p) continue;
      if (c > p) ++h;
      else ++l;
      p = c;
    }

    printf("Case %d: %d %d\n", i, h, l);
  }

  return 0;
}
