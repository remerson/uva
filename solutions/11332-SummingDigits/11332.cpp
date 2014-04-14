#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main()
{
  int n;

  while(scanf("%d", &n) == 1)
  {
    if(n == 0) break;
    n = n % 9;
    if(n == 0) n = 9;
    printf("%d\n", n);
  }
  return 0;
}
