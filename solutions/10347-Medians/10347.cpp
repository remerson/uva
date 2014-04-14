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
  double a, b, c;

  const double r = 1.0 / 3.0;

  while(scanf("%lf %lf %lf", &a, &b, &c) == 3)
  {
    double area;

    DEBUG(printf("a = %lf b = %lf c = %lf\n", a, b, c));

    if(a > b + c || b > a + c || c > a + b)
    {
      area = -1.0;
    }
    else
    {
      const double a2 = a * a;
      const double b2 = b * b;
      const double c2 = c * c;

      const double a4 = a2 * a2;
      const double b4 = b2 * b2;
      const double c4 = c2 * c2;

      area = r;

      double d = 2 * (a2 * b2 + b2 * c2 + c2 * a2) - (a4 + b4 + c4);
      
      area *= sqrt(static_cast<double>(d));

      if(area <= 0.0) area = -1.0;
    }

    printf("%.3f\n", area);
  }

  return 0;
}
