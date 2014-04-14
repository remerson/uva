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

const int B_MAX = 512;
const int M_MAX = 32;

int adjacency[M_MAX][M_MAX];
bool candles[M_MAX];

int toIndex(char c)
{
  return static_cast<int>(c) - 64;
}

char toChar(int i)
{
  return static_cast<char>(i + 64);
}

void print_adjacency()
{
  for(int i = 1; i < M_MAX; ++i)
  {
    if(adjacency[i][0] > 0)
    {
      printf("%c ->", toChar(i));
      for(int j = 1; j <= adjacency[i][0]; ++j)
        printf(" %c", toChar(adjacency[i][j]));
      printf("\n");
    }
  }
}

int main()
{
  char buffer[B_MAX];

  while(fgets(buffer, B_MAX, stdin))
  {
    if(buffer[0] == '#') break;
    
    for(int k = 0; k < M_MAX; ++k)
    {
      adjacency[k][0] = 0;
      candles[k] = false;
    }

    char *c = &buffer[0];
    int n = 0;

    while(*c != '.')
    {
      DEBUG(printf("READ %c\n", *c));
      if(n == 0) 
      {
        n = toIndex(*c);
        DEBUG(printf("SET n = %c c = %c\n", toChar(n), *c));
      }
      else if (*c == ';')
      {
        n = 0;
        DEBUG(printf("RESET n = 0 c = %c\n", *c));
      }
      else if (*c != ':')
      {
        adjacency[n][++adjacency[n][0]] = toIndex(*c);
        DEBUG(printf("adjacency[%c][%d] -> %d (%c)\n", 
                     toChar(n), 
                     adjacency[n][0],
                     adjacency[n][adjacency[n][0]],
                     toChar(adjacency[n][adjacency[n][0]])));
      }
      ++c;
    }

    ++c;
    ++c;
    int m = toIndex(*c);
    ++c;
    ++c;
    int t = toIndex(*c);
    ++c;
    int k = atoi(c);

    DEBUG(printf("START t = %d m = %d k = %d\n", t, m, k));

    DEBUG(print_adjacency());

    int move = 0;
    int i;

    do
    {
      // Drop a candle.
      if(move % k == 0 && move > 0)
      {
        DEBUG(printf("DROP move = %d k = %d t = %c\n", move, k, toChar(t)));
        candles[t] = true;
        printf("%c ", toChar(t));
      }
      
      // Move minotaur
      i = 1;

      while(adjacency[m][i] == t || candles[adjacency[m][i]]) ++i;

      if(i > adjacency[m][0]) break;

      DEBUG(printf("MOVE T %c -> %c\n", toChar(t), toChar(m)));

      t = m;

      DEBUG(printf("MOVE M %c -> %c\n", toChar(m), toChar(adjacency[m][i])));
      
      m = adjacency[m][i];

      ++move;

    } while(true);

    printf("/%c\n", toChar(m));
  }

  return 0;
}
