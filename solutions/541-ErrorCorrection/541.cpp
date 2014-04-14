#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_N = 128;

int main()
{
  int n;

  while(scanf("%d", &n))
  {
    if(n == 0) break;

    char matrix[MAX_N][MAX_N];

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(scanf("%d", &matrix[i][j]));

    int r = -1, c = -1;
    
    for(int i = 0; i < n; ++i)
    {
      int sum = 0;
      for(int j = 0; j < n; ++j) sum += matrix[i][j];
      DEBUG(printf("SUM r %d = %d\n", i, sum));
      if(sum % 2 != 0) 
        if(r == -1) r = i;
        else 
        {
          r = -2;
          break;
        }
    }

    for(int j = 0; j < n; ++j)
    {
      int sum = 0;
      for(int i = 0; i < n; ++i) sum += matrix[i][j];
      DEBUG(printf("SUM c %d = %d\n", j, sum));
      if(sum % 2 != 0) 
        if(c == -1) c = j;
        else 
        {
          c = -2;
          break;
        }
    }

    if(r == -1 && c == -1)
      printf("OK\n");
    else if(r == -2 || c == -2)
      printf("Corrupt\n");
    else
      printf("Change bit (%d,%d)\n", r+1, c+1);
        
  }

  return 0;
}
