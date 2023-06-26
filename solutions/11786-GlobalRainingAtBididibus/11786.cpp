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
#include <stack>

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

  int T;

  if(scanf("%d\n", &T));

  while(T)
  {
    const int MAX_N=16384;
    char buffer[MAX_N];

    if(scanf("%s\n", &buffer[0]));
    char *v = &buffer[0];

    
    int total = 0;
    stack<int> depth;
    bool valid = true;
    int pos = 0;
    
    while(valid)
    {
      switch(*v)
      {
      case '\\':
      {
        depth.push(pos);
        break;
      }
      case '/':
      {
        if(!depth.empty())
        {
          total += pos - depth.top();
          depth.pop();
        }
        break;
      }
      case '_':
      {
        break;
      }
      default:
      {
        valid = false;
        break;
      }
      }
      ++v;
      ++pos;
    }

    printf("%d\n", total);
    --T;
  }

  return 0;
}
