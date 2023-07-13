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
  int N;

  while(scanf("%d\n", &N) !=EOF)
  {
    if(N == 0)
      break;

    const int MAX_CARS = 10100;
    int grid[MAX_CARS] =  {0};
    bool valid {true};

    for(int pos = 1; pos <= N; ++pos)
    {
      int c, p;

      if(scanf("%d %d\n", &c, &p));

      int start = pos + p;

      DEBUG(printf("c = %d p = %d pos =%d start = %d\n", c, p, pos, start));

      if(start < 1 || start > N)
      {
        DEBUG(printf("Invalid start\n"));
        valid = false;
      }
      else if(grid[start] != 0)
      {
        DEBUG(printf("Bad grid[%d] = %d\n", start, grid[start]));
        valid = false;
      }
      else
      {
        grid[start] = c;
      }
    }

    if(!valid)
    {
      printf("-1\n");
    }
    else
    {
      printf("%d", grid[1]);
      for(int i = 2; i <= N; ++i)
        printf(" %d", grid[i]);
      printf("\n");
    }
  }

  return 0;
}
