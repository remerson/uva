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

const int MAX_N = 1000020;

const int MAX_T = 128;

struct Task
{
  int start;
  int end;
  int interval;
};

Task onetime[MAX_T];
Task repeating[MAX_T];

bitset<MAX_N> schedule;

// Returns true iff conflict found
inline bool mark(int a, int b)
{
  for(int i = a; i < b; ++i)
  {
    if(schedule[i])
    {
      DEBUG(printf("FOUND CONFLICT AT %d\n", i));
      return true;
    }
    schedule.set(i);
  }
  return false;
}
  
int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int n, m;
  int a, b;

  while(scanf("%d %d", &n, &m) == 2)
  {
    DEBUG(printf("N = %d M = %d\n", n, m));
    if(n == 0 && m == 0) break;

    schedule.reset();

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d %d\n", &onetime[i].start, &onetime[i].end));
      DEBUG(printf("ONETIME %d %d\n", onetime[i].start, onetime[i].end));
    }

    for(int i = 0; i < m; ++i)
    {
      if(scanf("%d %d %d\n", &repeating[i].start, &repeating[i].end, &repeating[i].interval));
      DEBUG(printf("REPEAT %d %d %d\n", repeating[i].start, repeating[i].end, repeating[i].interval));
    }

    bool conflict = false;

    for(int i = 0; i < n; ++i)
      if(conflict = mark(onetime[i].start, onetime[i].end))
        break;

    for(int i = 0; i < m; ++i)
    {
      if(conflict)
        break;

      a = repeating[i].start;
      b = repeating[i].end;

      while(b < MAX_N) // (as a < b)
      {
        if(conflict = mark(a, b))
          break;
        a += repeating[i].interval;
        b += repeating[i].interval;
      }
    }

    if(conflict)
      printf("CONFLICT\n");
    else
      printf("NO CONFLICT\n");
  }
  

  return 0;
}
