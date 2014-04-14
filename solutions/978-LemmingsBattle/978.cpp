#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <vector>
#include <queue>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

typedef priority_queue<int> Army;

int main()
{
  int n, b, sg, sb, v;

  DEBUG(printf("TEST CASES n = %d\n", n));

  if(scanf("%d\n", &n));

  for(int t = 0; t < n; ++t)
  {
    Army blue;
    Army green;
    
    

    if(scanf("%d %d %d\n", &b, &sg, &sb) == 3);

    DEBUG(printf("SETUP b = %d sg = %d sb = %d\n", b, sg, sb));

    for(int i = 0; i < sg; ++i)
      if(scanf("%d\n", &v)) green.push(v);

    for(int i = 0; i < sb; ++i)
      if(scanf("%d\n", &v)) blue.push(v);
    
    while(!blue.empty() && !green.empty())
    {
      Army bx;
      Army gx;

      size_t c = b;
      c = min(c, blue.size());
      c = min(c, green.size());

      DEBUG(printf("PASS c = %d blue = %d green = %d\n", c, blue.size(), green.size()));

      for(size_t i = 0; i < c; ++i)
      {
        int b = blue.top();
        int g = green.top();

        DEBUG(printf("ELIM i = %d b = %d g = %d\n", i, b, g));

        if(b > g)
        {
          DEBUG(printf("BLUE WINS %d\n", b - g));
          bx.push(b - g);
        }
        else if(g > b)
        {
          DEBUG(printf("GREEN WINS %d\n", g - b));
          gx.push(g - b);
        }
        else
        {
          DEBUG(printf("BOTH DIED\n"));
        }

        blue.pop();
        green.pop();
      }

      while(!bx.empty())
      {
        DEBUG(printf("BLUE SURVIVOR %d\n", bx.top()));
        blue.push(bx.top());
        bx.pop();
      }
      
      while(!gx.empty())
      {
        DEBUG(printf("GREEN SURVIVOR %d\n", bx.top()));
        green.push(gx.top());
        gx.pop();
      }
    }

    if(t != 0) printf("\n");

    if(blue.empty() && green.empty())
      printf("green and blue died\n");
    else if(blue.empty())
    {
      printf("green wins\n");
      while(!green.empty())
      {
        printf("%d\n", green.top());
        green.pop();
      }
    }
    else if(green.empty())
    {
      printf("blue wins\n");
      while(!blue.empty())
      {
        printf("%d\n", blue.top());
        blue.pop();
      }
    }
    
  }

  return 0;
}
