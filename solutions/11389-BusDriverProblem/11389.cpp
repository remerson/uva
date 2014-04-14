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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  int n, d, r;

  while(scanf("%d %d %d", &n, &d, &r))
  {
    DEBUG(printf("START n = %d d = %d r = %d\n", n, d, r));

    if(n == 0 && d == 0 && r == 0) break;

    priority_queue<int, vector<int>, less<int> > morning;

    int v;

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d", &v));
      morning.push(v);
    }

    priority_queue<int, vector<int>, greater<int> > evening;

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d", &v));
      evening.push(v);
    }

    int overtime = 0;

    while(morning.size() > 0)
    {
      const int total = morning.top() + evening.top();
      DEBUG(printf("OVERTIME %d total %d morning %d evening %d d = %d\n", overtime, total, morning.top(), evening.top(), d));
      if(total > d)
      {
        overtime += total - d;
      }
      
      morning.pop();
      evening.pop();
    }

    printf("%d\n", overtime * r);
  }

  return 0;
}
