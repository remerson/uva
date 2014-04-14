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
  int n, m;

  while(scanf("%d %d", &n, &m) != EOF)
  {
    printf("%d\n", n * m - 1);
  }

  return 0;
}
