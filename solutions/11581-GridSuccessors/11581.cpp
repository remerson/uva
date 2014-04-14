#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <cctype>

#define foreach(X, Y) for(typeof(Y) X = 0; X < Y; ++X)

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const unsigned MAX_N = 3;

unsigned grid[MAX_N][MAX_N];

inline void dump()
{
  printf("DUMP\n");
  for(unsigned i = 0; i < MAX_N; ++i)
  {
    printf("%u %u %u\n", grid[i][0], grid[i][1], grid[i][2]);
  }
}

inline bool is_finite()
{
  DEBUG(dump());
  bool result = false;
  for(unsigned i = 0; i < MAX_N; ++i)
  {
    for(unsigned j = 0; j < MAX_N; ++j)
    {
      if(grid[i][j] != 0) result = true;
    }
  }
  DEBUG(printf("FINITE => %s\n", result ? "yes" : "no"));
  return result;
}

inline void reduce()
{
  unsigned update[MAX_N][MAX_N];

  update[0][0] = (grid[0][1] + grid[1][0]) % 2;
  update[0][1] = (grid[0][0] + grid[1][1] + grid[0][2]) % 2;
  update[0][2] = (grid[0][1] + grid[1][2]) % 2;

  update[1][0] = (grid[0][0] + grid[1][1] + grid[2][0]) % 2;
  update[1][1] = (grid[1][0] + grid[1][2] + grid[0][1] + grid[2][1]) % 2;
  update[1][2] = (grid[1][1] + grid[0][2] + grid[2][2]) % 2;
  
  update[2][0] = (grid[1][0] + grid[2][1]) % 2;
  update[2][1] = (grid[2][0] + grid[2][2] + grid[1][1]) % 2;
  update[2][2] = (grid[2][1] + grid[1][2]) % 2;

  memcpy(grid, update, sizeof(unsigned) * MAX_N * MAX_N);
}

int main()
{
  unsigned n;

  if(scanf("%u", &n))
  {
    foreach(g, n)
    {
      DEBUG(printf("START %u\n", g));
      for(unsigned i = 0; i < MAX_N; ++i)
      {
        for(unsigned j = 0; j < MAX_N; ++j)
        {
          char c;
          do
          {
            if(scanf("%c", &c));
            DEBUG(printf("c = %c\n", c));
          } while(!isdigit(c));
          // 0 => 48
          // 1 => 49
          unsigned x = static_cast<unsigned>(c) - static_cast<unsigned>(48);
          DEBUG(printf("X = %u\n", x));

          grid[i][j] = x;
        }
      }
       
      int count = -1;
      while(is_finite())
      {
        reduce();
        ++count;
      }

      printf("%d\n", count);
    }
  }
  return 0;
}

