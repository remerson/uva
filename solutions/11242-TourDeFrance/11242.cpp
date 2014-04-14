#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <set>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_S = 16;
const int MAX_T = MAX_S * MAX_S;

int main()
{
  int f, r;

  while(scanf("%d %d", &f, &r) == 2)
  {
    int front[MAX_S];
    int rear[MAX_S];

    for(int i = 0; i < f; ++i) if(scanf("%d", &front[i]));
    for(int i = 0; i < r; ++i) if(scanf("%d", &rear[i]));

    double ratios[MAX_T];
    int k = 0;
    
    for(int i = 0; i < f; ++i)
      for(int j = 0; j < r; ++j)
      {
        const double ratio = static_cast<double>(rear[j]) / static_cast<double>(front[i]);
        DEBUG(printf("RATIO %f front[%d] = %d rear[%d] = %d\n", ratio, i, front[i], j, rear[j]));
        ratios[k++] = ratio;
      }

    const int sz = f * r;
    sort(ratios, ratios + sz);
    
    double max_spread = 0.0;

    for(int i = 1; i < sz; ++i)
    {
      const double spread = ratios[i] / ratios[i - 1];
      max_spread = max(max_spread, spread);
      DEBUG(printf("SPREAD %f ratios[%d] = %f ratios[%d] = %f max_spread = %f\n", spread, i, ratios[i], i - 1, ratios[i - 1], max_spread));
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << round(max_spread * 100) / 100.0 << endl;
  }

  return 0;
}
