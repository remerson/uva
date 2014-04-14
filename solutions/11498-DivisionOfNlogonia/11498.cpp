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
  int k;
  int n, m;
  int x, y;

  while(scanf("%d", &k) == 1)
  {
    if (k == 0) break;

    if(scanf("%d %d", &n, &m) == 2);

    for(int i = 0; i < k; ++i)
    {
      if(scanf("%d %d", &x, &y) == 2);

      if(x == n || y == m)
      {
        printf("divisa\n");
      }
      else if (x > n && y > m)
      {
        printf("NE\n");
      }
      else if (x < n && y > m)
      {
        printf("NO\n");
      }
      else if (x > n && y < m)
      {
        printf("SE\n");
      }
      else if (x < n && y < m)
      {
        printf("SO\n");
      }
    }
  }

  return 0;
}
