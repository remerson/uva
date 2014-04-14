#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

namespace io
{
  inline char *read_unsigned_short(unsigned short &v, char *b)
  {
    while(!isdigit(*b)) ++b;
    v = 0;

    while(isdigit(*b)) 
      v = v * 10 + *(b++) - '0';
    return b;
  }

}

const unsigned N_MAX = 1024;

const unsigned B_MAX = 8 * 1024;

using namespace io;

int main()
{
  char buffer[B_MAX];

  unsigned short pattern[N_MAX];
  unsigned short station[N_MAX];

  unsigned short n;

  while(true)
  {
    char *b = fgets(buffer, B_MAX - 1, stdin);

    read_unsigned_short(n, b);

    DEBUG(printf("N = %d\n", n));

    if(n == 0) break;

    while(true)
    {
      char *b = fgets(buffer, B_MAX - 1, stdin);
      
      DEBUG(printf("BUFFER [%s]\n", buffer));
      
      b = read_unsigned_short(pattern[1], b);
      
      DEBUG(printf("pattern[1] = %u\n", pattern[1]));
      
      if(pattern[1] == 0) 
      {
        //printf("\n");
        write(1, "\n", 1);
        break;
      }
      
      station[0] = 0;

      unsigned short k = 1;
      
      while(++k <= n) 
      {
        b = read_unsigned_short(pattern[k], b);
        DEBUG(printf("pattern[%u] = %u\n", k, pattern[k]));
      }

      unsigned m = 1, c = 1;

      //DEBUG(printf("PUSH %d\n", c));
      //station[++station[0]] = c++;

      DEBUG(printf("c = %u n = %u\n", c, n));
      DEBUG(printf("station[0] = %u\n", station[0]));

      while(station[0] > 0 || c <= n)
      //while(true)
      {
        DEBUG(printf("CHECK station[%u] = %u pattern[%u] = %u\n", station[0], station[station[0]], m, pattern[m]));

        if(station[station[0]] == pattern[m])
        {
          DEBUG(printf("MATCH station[%u] == pattern[%u]\n", station[0], m));
          --station[0];
          ++m;
        }
        else
        {
          if(c <= n)
          {
            DEBUG(printf("PUSH %d\n", c));
            station[++station[0]] = c++;
          }
          else
          {
            DEBUG(printf("NO MORE MATCHES\n"));
            break;
          }
        }
      }


      if(station[0] == 0)
      {
        write(1, "Yes\n", 4);
        //printf("Yes\n");
      }
      else
      {
        //printf("No\n");
        write(1, "No\n", 3);
      }
    }
  }

  return 0;
}
