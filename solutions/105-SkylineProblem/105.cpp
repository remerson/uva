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

const int H_MAX = 128 * 128;

int main()
{
  int left, height, right;
  int start = 99999, end = 0;

  int height_map[H_MAX] = {0};

  while(scanf("%d %d %d", &left, &height, &right) == 3)
  {
    DEBUG(printf("READ left = %d height = %d right = %d\n", left, height, right));
    start = min(start,left);
    end = max(end, right);
    for(int i = left; i < right; ++i)
    {
      height_map[i] = max(height_map[i], height);
      DEBUG(printf("SET height_map[%d] = %d\n", i, height_map[i]));
    }
  }

  height = height_map[start];

  printf("%d %d", start, height_map[start]);
  
  DEBUG(printf("START %d\n", start));
  DEBUG(printf("END %d\n", end));

  for(int i = start; i <= end; ++i)
  {
    if(height_map[i] != height)
    {
      height = height_map[i];
      printf(" %d %d", i, height);
    }
  }
  
  printf("\n");

  return 0;
}
