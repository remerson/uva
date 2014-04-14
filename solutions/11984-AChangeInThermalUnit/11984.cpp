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

double to_f(double c)
{
  double r = c;

  r *= 9.0;
  r /= 5.0;
  r += 32.0;

  DEBUG(printf("to_f(%.2f) = %.2f\n", c, r));

  return r;
}

double to_c(double f)
{
  double r = f;

  r -= 32.0;
  r *= 5.0;
  r /= 9.0;
  
  DEBUG(printf("to_c(%.2f) = %.2f\n", f, r));

  return r;
}

int main()
{
  int tests;

  if(scanf("%d\n", &tests));

  for(int t = 1; t <= tests; ++t)
  {
    int c, d;

    if(scanf("%d %d\n", &c, &d));

    DEBUG(printf("c = %d d = %d\n", c, d));

    printf("Case %d: %.2f\n", t, to_c(to_f(c) + d));
  }

  return 0;
}
