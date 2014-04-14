#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t N_MAX = 128;
const size_t M_MAX = 128;
const size_t S_MAX = 65536;

char grid[N_MAX][M_MAX];

int main()
{
  int n, m, s;

  while(scanf("%d %d %d", &n, &m, &s))
  {
    DEBUG(printf("START n = %d m = %d s = %d\n", n, m, s));
    if(n == 0 || m == 0 || s == 0) break;

    int r_dir = 0, c_dir = 0;
    int r_pos = 0, c_pos = 0;

    bool found = false;

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%s", &grid[i][0]));

      DEBUG(printf("READ ROW: %d %s %s\n", i, (found ? "found" : "scan"), &grid[i][0]));

      if(!found)
      {
        for(int j = 0; j < m && !found; ++j)
        {
          switch(grid[i][j])
            {
            case 'N':
              found = true;
              r_pos = i;
              c_pos = j;
              r_dir = -1;
              DEBUG(printf("FOUND N r_pos = %d c_pos = %d r_dir = %d c_dir = %d\n", r_pos, c_pos, r_dir, c_dir));
              break;
            case 'L':
              found = true;
              r_pos = i;
              c_pos = j;
              c_dir = 1;
              DEBUG(printf("FOUND L/E r_pos = %d c_pos = %d r_dir = %d c_dir = %d\n", r_pos, c_pos, r_dir, c_dir));
              break;
            case 'S':
              found = true;
              r_pos = i;
              c_pos = j;
              r_dir = 1;
              DEBUG(printf("FOUND S r_pos = %d c_pos = %d r_dir = %d c_dir = %d\n", r_pos, c_pos, r_dir, c_dir));
              break;
            case 'O':
              found = true;
              r_pos = i;
              c_pos = j;
              c_dir = -1;
              DEBUG(printf("FOUND O/W r_pos = %d c_pos = %d r_dir = %d c_dir = %d\n", r_pos, c_pos, r_dir, c_dir));
              break;
            }
        }
      }
    }

    // DEBUG(printf("GRID:\n"));
//     for(int i = 0; i < n; ++i)
//     {
//       for(int j = 0; j < m; ++j)
//         DEBUG(printf("%c", grid[i][j]));
//       DEBUG(printf("\n"));
//     }

    char commands[S_MAX];

    if(scanf("%s", commands));

    int stickers = 0;
    
    int next_r, next_c;

    for(int c = 0; c < s; ++c)
    {
      DEBUG(printf("COMMAND %c\n", commands[c]));

      switch(commands[c])
      {
      case 'F':
        next_r = r_pos + r_dir;
        next_c = c_pos + c_dir;
        DEBUG(printf("F/FORWARD r_pos = %d c_pos = %d next_r = %d next_c = %d\n", r_pos, c_pos, next_r, next_c));
        if(next_r < 0 || next_r >= n) 
        {
          DEBUG(printf("OOB/R\n"));
          continue;
        }
        else if(next_c < 0 || next_c >= m)
        {
          DEBUG(printf("OOB/C\n"));
          continue;
        }

        DEBUG(printf("GRID[%d][%d] = %c\n", next_r, next_c, grid[next_r][next_c]));

        if(grid[next_r][next_c] == '#')
        {
          DEBUG(printf("PILLAR\n"));
          continue;
        }
        if(grid[next_r][next_c] == '*')
        {
          DEBUG(printf("STICKER\n"));
          ++stickers;
          grid[next_r][next_c] = '.';
        }
        r_pos = next_r;
        c_pos = next_c;
        break;
      case 'D':
        DEBUG(printf("ROTATE RIGHT c_dir = %d r_dir = %d\n", c_dir, r_dir));
        if(c_dir == 1 && r_dir == 0)
        {
          c_dir = 0;
          r_dir = 1;
        }
        else if(c_dir == 0 && r_dir == 1)
        {
          c_dir = -1;
          r_dir = 0;
        }
        else if(c_dir == -1 && r_dir == 0)
        {
          c_dir = 0;
          r_dir = -1;
        }
        else if(c_dir == 0 && r_dir == -1)
        {
          c_dir = 1;
          r_dir = 0 ;
        }
        break;
      case 'E':
        DEBUG(printf("ROTATE LEFT c_dir = %d r_dir = %d\n", c_dir, r_dir));
        if(c_dir == 1 && r_dir == 0)
        {
          c_dir = 0;
          r_dir = -1;
        }
        else if(c_dir == 0 && r_dir == -1)
        {
          c_dir = -1;
          r_dir = 0;
        }
        else if(c_dir == -1 && r_dir == 0)
        {
          c_dir = 0;
          r_dir = 1;
        }
        else if(c_dir == 0 && r_dir == 1)
        {
          c_dir = 1;
          r_dir = 0;
        }
        break; 
      }
    }

    printf("%d\n", stickers);

  }

  return 0;
}
