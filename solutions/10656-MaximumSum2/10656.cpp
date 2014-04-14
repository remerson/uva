#include <iostream>
#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_N = 1024;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n = 0;

  while(true)
  {
    if(scanf("%d", &n));
    if(n == 0) break;
    int k = 0;
    bool out = false;
    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d", &k));
      if(k > 0)
      {
        if(out)
          printf(" %d", k);
        else
          printf("%d", k);
        out = true;
      }
    }
    if(out)
      printf("\n");
    else
      printf("0\n");
    
  }

  return 0;
}
