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

const int MAX_D = 128;

char field[MAX_D][MAX_D];

bool adjacent(int i, int j)
{
  if(field[i + 1][j] == '*') return true;
  if(field[i - 1][j] == '*') return true;

  if(field[i][j + 1] == '*') return true;
  if(field[i][j - 1] == '*') return true;
  
  if(field[i + 1][j + 1] == '*') return true;
  if(field[i + 1][j - 1] == '*') return true;

  if(field[i - 1][j + 1] == '*') return true;
  if(field[i - 1][j - 1] == '*') return true;

  return false;
}

int main()
{
  int r, c;
  char buffer[MAX_D];
  int k;

  while(scanf("%d %d\n", &r, &c) == 2)
  {
    if(r == 0 || c == 0) break;

    DEBUG(printf("\n\nSTART r = %d c = %d\n", r, c));

    memset(field, '.', sizeof(char) * MAX_D * MAX_D); 

    for(int i = 1; i <= r; ++i)
    {
      fgets(&buffer[0], MAX_D, stdin);
      k = 0;
      DEBUG(printf("buffer = [%s]\n", &buffer[0]));

      for(int j = 1; j <= c; ++j)
      {
        if(buffer[k] == '.' || buffer[k] == '*')
        {
          field[i][j] = buffer[k++];
          DEBUG(printf("%c", field[i][j]));
        }
      }
      DEBUG(printf("\n"));
    }

    int count = 0;
    
    for(int i = 1; i <= r; ++i)
    {
      for(int j = 1; j <= c; ++j)
      {
        if(field[i][j] == '*')
        {
          DEBUG(printf("DETECT i = %d j = %d\n", i, j));
          if(!adjacent(i, j))
          {
            DEBUG(printf("HIT i = %d, j = %d\n", i, j));
            ++count;
          }
        }
      }
    }
    printf("%d\n", count);
  }

  return 0;
}
