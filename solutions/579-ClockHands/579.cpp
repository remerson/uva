#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  int hour, mins;

  while(scanf("%d:%d\n", &hour, &mins))
  {
    if(hour == 0 && mins == 0) break;

    DEBUG(printf("hour = %d mins = %d\n", hour, mins));

    const double m = static_cast<double>(mins) * 6.0;

    DEBUG(printf("m = %f\n", m));

    double h = (static_cast<double>(hour) * 30.0) + (m / 12.0);

    DEBUG(printf("h = %f\n", h));
    
    const double v3 = fabs(m - h);
    const double v1 = 360.0 - v3;

    printf("%0.3f\n", min(v1, v3));
  }


  return 0;
}
