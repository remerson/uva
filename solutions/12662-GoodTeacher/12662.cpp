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

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int n;

  if(scanf("%d\n", &n));

  char names[128][4] = {0};
  
  for(int i = 0; i < n; ++i)
  {
    if(scanf("%s", &names[i][0]));
    DEBUG(printf("names[%d] = [%s]\n", i, &names[i][0]));
  }

  int right[128] = {0};
  int count = 0;
  bool found = false;
  for(int i = 0; i < n; ++i)
  {
    if(names[i][0] != '?')
      found = true;
    if(found && names[i][0] == '?')
      right[i] = ++count;
    else
      count = 0;
  }

  DEBUG(for(int i = 0; i < n; ++i) printf("right[%d] = %d\n", i, right[i]));

  int left[128] = {0};
  count = 0;
  found = false;
  for(int i = n - 1; i >= 0; --i)
  {
    if(names[i][0] != '?')
      found = true;
    if(found && names[i][0] == '?')
      left[i] = ++count;
    else
      count = 0;
  }
  
  DEBUG(for(int i = 0; i < n; ++i) printf("left[%d] = %d\n", i, left[i]));

  int q;

  if(scanf("%d\n", &q));

  DEBUG(printf("q = %d\n", q));

  for(int i = 0; i < q; ++i)
  {
    int p;
    if(scanf("%d\n", &p));
    --p; // 1 offset, not zero

    DEBUG(printf("QUERY p = %d left[%d] = %d right[%d] = %d\n", p, p, left[p], p, right[p]));

    if(names[p][0] != '?')
    {
      DEBUG(printf("HIT\n"));
      printf("%s\n", &names[p][0]);
    }
    else if(left[p] == right[p])
    {
      DEBUG(printf("MIDDLE\n"));
      printf("middle of %s and %s\n", &names[p - right[p]][0], &names[p + left[p]][0]);
    }
    else if((left[p] > 0 && left[p] < right[p]) || (right[p] == 0))
    {
      DEBUG(printf("LEFT\n"));
      int k = left[p];
      while(k--)
      {
        printf("left of ");
      }
      printf("%s\n", &names[p + left[p]][0]);
    }
    else if((right[p] > 0 && right[p] < left[p]) || (left[p] == 0))
    {
      DEBUG(printf("RIGHT\n"));
      int k = right[p];
      while(k)
      {
        printf("right of ");
        --k;
      }
      printf("%s\n", &names[p - right[p]][0]);
    }
  }

  return 0;
}
