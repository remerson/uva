#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_N = 64;
const int B_MAX = 128;

char right(char direction)
{
  switch(direction)
  {
  case 'N':
    return 'E';
  case 'E':
    return 'S';
  case 'S':
    return 'W';
  case 'W':
    return 'N';
  }
}

char left(char direction)
{
  switch(direction)
  {
  case 'N':
    return 'W';
  case 'E':
    return 'N';
  case 'S':
    return 'E';
  case 'W':
    return 'S';
  }
}

int main()
{
  int n, m;
  int x, y;
  char direction;
  char buffer[B_MAX];
  bool lost[MAX_N][MAX_N];

  memset(lost, 0, sizeof(bool) * MAX_N * MAX_N);

  if(scanf("%d %d\n", &n, &m));

  while(scanf("%d %d %c\n", &x, &y, &direction) == 3)
  {
    if(scanf("%s\n", &buffer[0]) != 1) break;

    bool dead = false;
    const size_t l = strlen(buffer);

    for(size_t k = 0; k < l; ++k)
    {
      if(dead) break;
      switch(buffer[k])
      {
      case 'F':
        switch(direction)
        {
        case 'N':
          if(y == m)
          {
            if (!lost[x][y])
            {
              lost[x][y] = true;
              dead = true;
            }
            break;
          }
          else ++y;
          break;
        case 'E':
          if(x == n)
          {
            if (!lost[x][y])
            {
              lost[x][y] = true;
              dead = true;
            }
            break;
          }
          else ++x;
          break;
        case 'S':
          if(y == 0)
          {
            if (!lost[x][y])
            {
              lost[x][y] = true;
              dead = true;
            }
            break;
          }
          else --y;
          break;
        case 'W':
          if(x == 0)
          {
            if (!lost[x][y])
            {
              lost[x][y] = true;
              dead = true;
            }
            break;
          }
          else --x;
          break;
        }
        break;
      case 'R':
        direction = right(direction);
        break;
      case 'L':
        direction = left(direction);
        break;
      }
    }

    printf("%d %d %c", x, y, direction);
    if(dead) printf(" LOST\n");
    else printf("\n");
  }


  return 0;
}
