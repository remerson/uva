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

const size_t P_MAX = 1000;
const size_t D_MAX = 10000;
const size_t B_MAX = 101;

int main(int argc, char **argv)
{
  srand(unsigned(time(0)));

  const int t = atoi(argv[1]);

  printf("%d\n", t);

  for(int i = 0; i < t; ++i)
  {
    int p = rand() % P_MAX;
    int sl = rand() % B_MAX;
    int d = rand() % D_MAX;

    if(p == 0) p = 1;
    if(sl == 0) sl = 1;
    if(d == 0) d = 1;

    printf("%d %d %d\n", p, sl, d);

    int startpoint[B_MAX] = {0};
    int endpoint[B_MAX] = {0};

    for(int j = 0; j < sl; ++j)
    {
      int a = rand() % (B_MAX - 1);
      while(startpoint[a] || a >= 100 || a <= 0) a = rand() % (B_MAX - 1);
      
      startpoint[a] = 1;

      int b = rand() % (B_MAX - 1);
      while(endpoint[b] || b <= 0 || b >= 100 || a == b) b = rand() % (B_MAX - 1);

      endpoint[b] = 1;

      printf("%d %d\n", a, b);
    }

    for(int j = 0; j < d; ++j)
    {
      const int r = (rand() % 6) + 1;

      printf("%d\n", r);
    }
  }

  return 0;
}
