#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;




int main()
{
  int n, b, h, w;

  while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
  {
    int v = INT_MAX;
    DEBUG(printf("START N = %d B = %d H = %d W = %d\n", n, b, h, w));
    for(int i = 0; i < h; ++i)
    {
      int c;
      if(scanf("%d", &c));
      for(int j = 0; j < w; ++j)
      {
        int a;
        if(scanf("%d", &a));
        if(a < n) continue;
        else 
        {
          v = min(v, c * n);
          DEBUG(printf("set v = %d for i = %d j = %d c = %d a = %d n = %d b = %d h = %d w = %d\n", v, i, j, c, a, n, b, h, w));
        }
      }  
    }
    
    if(v > b) printf("stay home\n");
    else printf("%d\n", v);
  }

  return 0;
}
