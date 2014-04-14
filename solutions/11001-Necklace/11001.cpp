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
#include <limits>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

double calculate(double u, double v)
{
  const double z = u - v;
  double r = 0.0;

  if(z > 0)
    r = 0.3 * sqrt(z);

  DEBUG(printf("u = %f v = %f r = %f\n", u, v, r));

  return r;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int vt, v0;

  while(scanf("%d %d", &vt, &v0))
  {
    if(vt == 0 && v0 == 0)
      break;

    DEBUG(printf("vt = %d v0 = %d\n", vt, v0));

    if(vt <= v0)
      printf("0\n");
    else
    {
      const int n0 = static_cast<int>(ceil( (vt / v0) / 2.0));
      
      double d0 = 0.0;
      
      if(n0 > 0)
        d0 = n0 * calculate(static_cast<double>(vt) / n0, v0);
      
      DEBUG(printf("n0 = %d d0 = %.20f\n", n0, d0));
      
      const int n1 = n0 - 1;
      double d1 = 0.0; 
      
      if(n1 > 0) 
        d1 = n1 * calculate(static_cast<double>(vt) / n1, v0);
      
      DEBUG(printf("n1 = %d d1 = %.20f\n", n1, d1));
      
      DEBUG(printf("epsilon =   %.20f\n", std::numeric_limits<double>::epsilon()));
      
      if(fabs(d0 - d1) < std::numeric_limits<float>::epsilon())
        printf("0\n");
      else if(d0 < d1)
        printf("%d\n", n1);
      else if(d0 > d1)
        printf("%d\n", n0);
    }
  
  }
  

  return 0;
}
