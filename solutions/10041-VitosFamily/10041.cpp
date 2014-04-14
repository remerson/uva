#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int MAX_R = 512;
int MAX_B = 4;

int main()
{
  int num;

  if(scanf("%d\n", &num));

  for(int t = 0; t < num; ++t)
  {
    int r;
    int s[MAX_R];

    if(scanf("%d", &r));

    const int b = r - MAX_B;

    int i = 0;

    while(i < r)
    {
      if(i < b)
      {
        scanf("%d %d %d %d", &s[i], &s[i+1], &s[i+2], &s[i+3]);
        i+=4;
      }
      else
      {
        scanf("%d", &s[i]);
        ++i;
      }
    }

    sort(s, s + r);

    int m = r / 2;

    DEBUG(printf("m = %d\n", m));

    int k = 0;
    int j;

    for(int i = 0; i < r; ++i)
    {
      j = s[m] - s[i];
      if(j < 0) j *= -1;
      k += j;
    }

    printf("%d\n", k);
  }

  return 0;
}
