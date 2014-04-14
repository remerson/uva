#include <iostream>
#include <cstdio>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

int cola(int n)
{
  if(n == 1) 
    return 1;

  if(n % 2 == 0) 
    return 2 + cola(n - 1);
  else 
    return 1 + cola(n - 1);
}

int main()
{
  int n;

  while(scanf("%d",&n) != EOF)
  {
    DEBUG(printf("cola(%d) = %d\n", n, cola(n)));
    printf("%d\n", cola(n));
  }
  return 0;
}
