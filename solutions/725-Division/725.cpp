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
  int d;
  bool first = true;

  while(scanf("%d", &d))
  {
    if(d == 0)
      break;

    const int MAX_B = 98765 / d + 1;

    int count = 0;

    if(!first)
      printf("\n");
    first = false;

    for(int b = 1234; b < MAX_B; ++b)
    {
      const int a = b * d;

      if(a < 98765)
      {
        int x = a, y = b;

        int histo[10] = {0};

        while(x)
        {
          ++histo[x % 10];
          x /= 10;
        }

        while(y)
        {
          ++histo[y % 10];
          y /= 10;
        }

        bool match = true;

        for(int i = 1; i < 10 && match; ++i)
          match = (histo[i] == 1);

        if(match)
        {
          printf("%05d / %05d = %d\n", a, b, d);
          ++count;
        }
      }
    }

    if(count == 0)
      printf("There are no solutions for %d.\n", d);
  }
  

  return 0;
}
