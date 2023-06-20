#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

//using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  char buffer[5][64] = {0};

  int n;

  if(scanf("%d\n", &n));

  for(int i = 0; i < 5; ++i)
  {
    if(scanf("%s\n", &buffer[i][0]));
    DEBUG(printf("buffer[%d] = %s\n", i, &buffer[i][0]));
  }

  for(int j = 0; j < (4 * n); j += 4)
  {
    DEBUG(printf("j = %d buffer = %c%c%c%c%c\n", j, buffer[0][j], buffer[1][j], buffer[2][j], buffer[3][j] , buffer[4][j]))
    if(buffer[0][j] == '.')
    {
      printf("%d", 1);
    }
    else if(buffer[3][j] == '*')
    {
      printf("%d", 2);
    }
    else
    {
      printf("%d", 3);
    }
  }
  printf("\n");

  return 0;
}
