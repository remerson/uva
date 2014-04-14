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

const int V = 9;

inline int turn(int x)
{
  int v = 0;
  if (x < 0) v = x + 40;
  else v = x;
  return v;
}

int main()
{
  int i, a, b, c;
  int v;
  
  while(scanf("%d %d %d %d", &i, &a, &b, &c) == 4)
  {
    if(i == 0 && a == 0 && b == 0 && c == 0) break;

    v = 120 + turn(i - a) + turn(b - a) + turn(b - c);

    // if (i - a < 0) v += (i - a) + 40;
    // else v += (i - a);

    // if (b - a < 0) v += (b - a) + 40;
    // else v += (b - a);

    // if (b - c < 0) v += (b - c) + 40;
    // else v += (b - c);

    printf("%d\n", v * V);
  }
    
  return 0;
}
