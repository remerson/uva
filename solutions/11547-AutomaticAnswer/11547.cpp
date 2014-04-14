#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

int B_MAX = 64;

using namespace std;

int main()
{
  int tests, n;
  char buffer[B_MAX];

  if(scanf("%d\n", &tests));

  for(int i = 0; i < tests; ++i)
  {
    if(scanf("%d\n", &n));

    double k = (double) n;

    k *= 567.0;

    k /= 9.0;

    k += 7492.0;

    k *= 235.0;

    k /= 47.0;

    k -= 498.0;

    int j = (int) k;

    sprintf(&buffer[0], "%d", j);

    int l = strlen(buffer);

    printf("%c\n", buffer[l - 2]);
  }

  return 0;
}
