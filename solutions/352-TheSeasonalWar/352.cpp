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

const int MAX_SIZE = 32;

char field[MAX_SIZE][MAX_SIZE];

void ffill(int i, int j)
{
  //  DEBUG(printf("ffill i = %d j = %d\n", i, j));

  if(field[i][j] != '1') return;
  
  field[i][j] = '0';
  
  bool imin = (i - 1 >= 0);
  bool imax = (i + 1 < MAX_SIZE);
  bool jmin = (j - 1 >= 0);
  bool jmax = (j + 1 < MAX_SIZE);
    
  if(imin) ffill( i - 1, j);
  if(imax) ffill( i + 1, j);

  if(jmax) ffill( i, j + 1);
  if(jmin) ffill( i, j - 1);

  if(imin && jmax) ffill( i - 1, j + 1);
  if(imin && jmin) ffill( i - 1, j - 1);

  if(imax && jmax) ffill( i + 1, j + 1);
  if(imax && jmin) ffill( i + 1, j - 1);
}

int main()
{
  int m, n;
  int t = 0;

  while(scanf("%d\n", &n) != EOF)
  {
    if(n == 0) break;

    m = n;

    memset(&field[0][0], '*', sizeof(char) * (m + 2) * (n + 2));

    DEBUG(printf("field m = %d n = %d\n", m, n));

    char buffer[MAX_SIZE];

    for(int i = 1; i <= m; ++i)
    {
      if(fgets(&buffer[0], MAX_SIZE, stdin));

      for(int j = 1; j <=n; ++j)
      {
        field[i][j] = buffer[j - 1];
        DEBUG(printf("field[%d][%d] = %c\n", i, j, field[i][j])); 
      }
    }

    int oil = 0;

    for(int i = 1; i <= m; ++i)
    {
      for(int j = 1; j <=n; ++j)
      {
        if(field[i][j] == '1')
        {
          ++oil;
          ffill(i, j);
        }
      }
    }

    printf("Image number %d contains %d war eagles.\n", ++t, oil);
  }

  return 0;
}
