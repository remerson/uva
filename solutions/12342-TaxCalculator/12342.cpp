#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int BAND_1 = 180000;
const int BAND_2 = 300000;
const int BAND_3 = 400000;
const int BAND_4 = 300000;

const double RATE_1 = 0.10;
const double RATE_2 = 0.15;
const double RATE_3 = 0.20;
const double RATE_4 = 0.25;

inline double calculate(const int v,
                        const int lower,
                        const int upper,
                        const double rate)
{
  DEBUG(printf("CALC v = %d lower = %d upper = %d\n", v, lower, upper));
  if(v > lower)
  {
    const int e = min(upper - lower, v - lower);
    DEBUG(printf("CALC v = %d e = %d rate = %f\n", v, e, rate));
    if(e > 0) 
    {
      DEBUG(printf("TAX = %f\n", e * rate));
      return e * rate;
    }
  }
  DEBUG(printf("NO TAX \n"));
  return 0.0;
}

int main()
{
  unsigned n;

  if(scanf("%u\n", &n));

  DEBUG(printf("N = %u\n", n));

  for(unsigned t = 1; t <= n; ++t)
  {
    int v;
    if(scanf("%d", &v));
    
    double tax = 0.0;

    tax += calculate(v, BAND_1, BAND_1 + BAND_2, RATE_1);
    tax += calculate(v, BAND_1 + BAND_2, BAND_1 + BAND_2 + BAND_3, RATE_2);
    tax += calculate(v, BAND_1 + BAND_2 + BAND_3, BAND_1 + BAND_2 + BAND_3 + BAND_4, RATE_3);
    tax += calculate(v, BAND_1 + BAND_2 + BAND_3 + BAND_4, 999999999, RATE_4);

    int result = (int) ceil(tax);
    if(tax > 0 && tax < 2000)
    {
      result = 2000;
    }

    printf("Case %d: %d\n", t, result);
  }

  return 0;
}
