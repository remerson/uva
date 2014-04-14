#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_N = 128 * 1024;

inline char *read_int(int &v, char *b)
{ 
  bool negative = false;
  v = 0;
  while(!isdigit(*b))
  {
    if(*b == '-')
      negative = true;
    ++b;
  }
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  if(negative) v *= -1;
  return b;
}
int main()
{
  // Hope this is big enough!
  char buffer[MAX_N + 1];

  int opened[MAX_N];
  int remaining[MAX_N];
             

  opened[0] = 0;
  int x;
  bool ismat;

  while(char *b = fgets(buffer, MAX_N, stdin))
  {
    opened[0] = 0;
    remaining[0] = 0;
    ismat = true;

    DEBUG(printf("BUFFER [%s]\n", buffer));

    while(*b != '\n')
    {
      b = read_int(x, b);

      DEBUG(printf("READ x = %d\n", x));
      DEBUG(printf(" BEFORE opened (%d) = %d\n", opened[0], opened[opened[0]]));
      DEBUG(printf(" BEFORE remaining (%d) = %d\n", remaining[0], remaining[opened[0]]));

      if(x == 0) break;

      if(x < 0)
      {
        x = abs(x);
        DEBUG(printf("  OPEN %d\n", x));

        if(remaining[0] == 0 || remaining[remaining[0]] > x)
        {
          opened[++opened[0]] = x;
          remaining[++remaining[0]] = x;
        }
        else
        {
          ismat = false;
          break;
        }
      }
      else
      {
        DEBUG(printf("  CLOSE %d\n", x));
        if(opened[0] == 0 || opened[opened[0]] != x)
        {
          ismat = false;
          break;
        }
        else
        {
          --opened[0];
          if(remaining[0] > 0)
          {
            --remaining[0];
            remaining[remaining[0]] = max(0, remaining[remaining[0]] - x);
            //--remaining[0];
          }
        }
      }

      DEBUG(printf(" AFTER opened (%d) = %d\n", opened[0], opened[opened[0]]));
      DEBUG(printf(" BEFORE remaining (%d) = %d\n", remaining[0], remaining[opened[0]]));
    }

    ismat = ismat && (opened[0] == 0);

    if(ismat)
      printf(":-) Matrioshka!\n");
    else
      printf(":-( Try again.\n");
  }

  return 0;
}
