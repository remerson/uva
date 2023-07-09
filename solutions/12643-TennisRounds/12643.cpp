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

  int N, i, j;

  while(scanf("%d %d %d\n", &N, &i, &j) == 3)
  {
    DEBUG(printf("START %d %d %d\n", N, i, j));
    
    if(i > j)
      swap(i, j);

    int max = pow(2, N);
    
    for(int r = 1; r <= max; ++r)
    {
      DEBUG(printf("ROUND %d %d %d\n", r, i, j));
      
      if((j % 2 == 0) && i == (j-1))
      {
        printf("%d\n", r);
        break;
      }
      else
      {
        i = ceil(i / 2.0);
        j = ceil(j / 2.0);
      }
    } 
  }
  return 0;
}
