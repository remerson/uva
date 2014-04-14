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

const size_t T_MAX = 64;
const size_t S_MAX = 128;
const size_t L_MAX = S_MAX * S_MAX;

char square[S_MAX][S_MAX];
char powers[L_MAX];

int main()
{
  for(int i = 0; i < L_MAX; ++i)
  {
    powers[i] = 0;
  }

  for(int i = 0; i < S_MAX; ++i)
  {
    powers[i * i] = i;
  }
  
  int t;

  if(scanf("%d\n", &t));

  for(int v = 1; v <= t; ++v)
  {
    char buffer[L_MAX];
    char word[L_MAX] = {0};

    if(fgets(buffer, L_MAX, stdin));

    DEBUG(printf("BUFFER [%s]\n", buffer));

    char *p = &buffer[0];
    size_t len = 0;
    
    while(*p != '\0')
    {
      if(*p >= 'a' && *p <= 'z') word[len++] = *p;
      ++p;
    }

    word[len] = '\0';

    DEBUG(printf("LEN = %d\n", len));
    DEBUG(printf("WORD = [%s]\n", word));

    const size_t side = powers[len];

    DEBUG(printf("(GUESS) SIDE = %d\n", side));

    bool magic = (side != 0);
    
    DEBUG(printf("(GUESS) MAGIC? %s\n", magic ? "maybe" : "no"));

    // Copy word into square
    DEBUG(printf("SQUARE:\n"));
    if(magic)
    {
      for(int r = 0; r < side; ++r)
      {
        for(int c = 0; c < side; ++c)
        {
          square[r][c] = word[(r * side) + c];
          DEBUG(printf("%c", square[r][c]));
        }
        DEBUG(printf("\n"));
      }
    }

    // Check 2 - Start 1,1 and read down by column then by row
    if(magic)
    {
      int i = 0;
      for(int c = 0; c < side && magic; ++c)
        for(int r = 0; r < side; ++r)
          if(square[r][c] != word[i++])
          {
            DEBUG(printf("FAILED (2) square[%d][%d] = %c word[%d] = %c\n", r, c, square[r][c], i - 1, word[i - 1]));
            magic = false;
            break;
          }
    }

    // Check 3 - Start k,k and read backwards by row then up by column
    if(magic)
    {
      int i = 0;
      for(int r = (side - 1); r >= 0 && magic; --r)
        for(int c = (side - 1); c >= 0; --c)
          if(square[r][c] != word[i++])
          {
            DEBUG(printf("FAILED (3) square[%d][%d] = %c word[%d] = %c\n", r, c, square[r][c], i - 1, word[i - 1]));
            magic = false;
            break;
          }
    }

    // Check 4 - Start k,k and read backwards up by column then back by row
    if(magic)
    {
      int i = 0;
      for(int c = (side - 1); c >= 0 && magic; --c)
        for(int r = (side - 1); r >= 0; --r)
          if(square[r][c] != word[i++])
          {
            DEBUG(printf("FAILED (4) square[%d][%d] = %c word[%d] = %c\n", r, c, square[r][c], i - 1, word[i - 1]));
            magic = false;
            break;
          }
    }
    
    if(magic)
      printf("Case #%d:\n%d\n", v, side);
    else
      printf("Case #%d:\nNo magic :(\n", v); 
  }

  return 0;
}
