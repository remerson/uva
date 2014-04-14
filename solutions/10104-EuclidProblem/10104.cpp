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

using namespace std;

void extended_gcd(int a, int b)
{
  bool same = (a == b);
  int x = 0, y = 1;
  int u = 1, v = 0;

  while(a != 0)
  {
    const int q = b / a;
    const int r = b % a;

    const int m = x - u * q;
    const int n = y - v * q;

    b = a;
    a = r;
    x = u;
    y = v;
    u = m;
    v = n;
  }

  DEBUG(printf("a = %d b = %d x = %d y = %d\n", a, b, x, y));

  if(y == 0 && same)
    printf("%d %d %d\n", y, x, b);
  else
    printf("%d %d %d\n", x, y, b);
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int a, b;

  while(scanf("%d %d", &a, &b) == 2)
  {
    DEBUG(printf("A = %d B = %d\n", a, b));
    extended_gcd(a, b);
  }
  return 0;
}
