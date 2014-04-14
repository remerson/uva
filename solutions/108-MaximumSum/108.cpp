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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_N = 128;

int main()
{
  std::ios_base::sync_with_stdio(false);

  int values[MAX_N][MAX_N];

  int n;

  if(scanf("%d", &n));

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    {
      if(scanf("%d", &values[i][j]));
      if(i > 0) values[i][j] += values[i-1][j];
      if(j > 0) values[i][j] += values[i][j-1];
      if(i > 0 && j > 0) values[i][j] -= values[i-1][j-1];      
    }

  int maxSubRect = -127 * MAX_N * MAX_N;
  int subRect;

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int k = i; k < n; ++k)
        for(int l = j; l < n; ++l)
        {
          subRect = values[k][l];
          if(i > 0) subRect -= values[i-1][l];
          if(j > 0) subRect -= values[k][j-1];
          if(i > 0 && j > 0) subRect += values[i-1][j-1];
          if(subRect > maxSubRect) maxSubRect = subRect;
        }

  printf("%d\n", maxSubRect);

  return 0;
}
