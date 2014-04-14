#include <cstdio>

using namespace std;

int main()
{
  int t;
  int s, d;

  if(scanf("%d", &t));

  for(int i = 0; i < t; ++i)
  {
    if(scanf("%d %d", &s, &d));

    const int k = (s - d);

    if(k < 0 || k % 2 != 0)
    {
      printf("impossible\n");
      continue;
    }

    const int b = k / 2;
    const int a = d + b;

    printf("%d %d\n", a, b);
  }

  return 0;
}
