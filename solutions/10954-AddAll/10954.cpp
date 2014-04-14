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
  int n;

  while(scanf("%d", &n))
  {
    if(n == 0) break;

    priority_queue<int, vector<int>, greater<int> > values;
    int v;

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d", &v));
      values.push(v);
    }

    v = 0;
    int x, y;
    while(values.size() > 1)
    {
      x = values.top();
      values.pop();
      y = values.top();
      values.pop();
      values.push(x + y);
      DEBUG(printf("POP x = %d y = %d v = %d\n", x, y, v));
      v += x + y;
    }

    printf("%d\n", v);
  }

  return 0;
}
