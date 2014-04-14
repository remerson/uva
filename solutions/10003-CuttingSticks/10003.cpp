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

const int MAX_CUTS = 64;

const int MAX_COST = MAX_CUTS * 1024;

int memo[MAX_CUTS][MAX_CUTS];

int points[MAX_CUTS];

int cut(int left, int right)
{
  if(memo[left][right] != MAX_COST)
    return memo[left][right];

  int cost = 0;

  if(left + 1 < right)
  {
    const int cut_cost = points[right] - points[left];

    cost = MAX_COST;

    for(int i = left + 1; i < right; ++i)
      cost = min(cost, cut_cost + cut(left, i) + cut(i, right));
  }

  return memo[left][right] = cost;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int length;

  while(scanf("%d", &length))
  {
    if(length == 0)
      break;

    int n;

    if(scanf("%d", &n));

    int num_points = 0;

    points[num_points++] = 0;

    for(int i = 0; i < n; ++i)
      if(scanf("%d", &points[num_points++]));

    points[num_points++] = length;

    for(int i = 0; i < num_points; ++i)
      for(int j = 0; j < num_points; ++j)
        memo[i][j] = MAX_COST;

    int min_cost = cut(0, num_points - 1);

    printf("The minimum cutting is %d.\n", min_cost);
  }

  return 0;
}
