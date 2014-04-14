#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const size_t B_MAX = 2048 * 1024;

char buffer[B_MAX];

int main()
{
  unsigned n;

  while(scanf("%u\n", &n) != EOF)
  {
    DEBUG(printf("N = %u\n", n));
    if(n == 0) break;
    
    fgets(buffer, B_MAX - 1, stdin);
    DEBUG(printf("BUFFER = [%s]\n", buffer));

    char match = '.';
    size_t start = 0;
    size_t min_dist = B_MAX;
    bool clear = false;

    for(size_t i = 0; i < n && !clear; ++i)
    {
      DEBUG(printf("SCAN %u %c MATCH %c\n", i, buffer[i], match));
      switch(buffer[i])
      {
        case 'D':
          switch(match)
          {
          case 'R':
            start = i;
            break;
          case 'D':
            if(i - start < min_dist) min_dist = i - start;
            match = 'R';
            start = i;
            break;
          case '.':
            start = i;
            match = 'R';
            break;
          }
          break;

        case 'R':
          switch(match)
          {
          case 'D':
            start = i;
            break;
          case 'R':
            if(i - start < min_dist) min_dist = i - start;
            match = 'D';
            start = i;
            break;
          case '.':
            start = i;
            match = 'D';
            break;
          }
          break;

        case '.':
          break;

        case 'Z':
          clear = true;
          min_dist = 0;
          break;
      }
    }
    printf("%u\n", min_dist);
  }

  return 0;
}
