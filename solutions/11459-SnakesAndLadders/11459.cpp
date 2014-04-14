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

const size_t P_MAX = 1000000;
const size_t D_MAX = 1000000;
const size_t B_MAX = 101;

int main()
{
  int t;

  if(scanf("%d\n", &t));

  char positions[P_MAX];
  
  for(int v = 0; v < t; ++v)
  {
    char board[B_MAX];
    for(size_t i = 0; i < B_MAX; ++i)
      board[i] = i;

    int a, b, c;

    if(scanf("%d %d %d\n", &a, &b, &c));

    DEBUG(printf("START a = %d b = %d c = %d\n", a, b, c));

    for(size_t i = 0; i < a; ++i)
      positions[i] = 1;

    int x, y;

    for(size_t i = 0; i < b; ++i)
      if(scanf("%d %d\n", &x, &y))
      {
        DEBUG(printf("%s %d -> %d\n", (x < y ? "LADDER" : "SNAKE"), x, y));
        board[x] = y;
      }

    int n;
    bool play = true;

    int dice[D_MAX];

    for(size_t i = 0; i < c;)
    {
      if(c - i > 20)
      {
        if(scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                 &dice[i], &dice[i+1], &dice[i+2], &dice[i+3], &dice[i+4],
                 &dice[i+5], &dice[i+6], &dice[i+7], &dice[i+8], &dice[i+9],
                 &dice[i+10], &dice[i+11], &dice[i+12], &dice[i+13], &dice[i+14],
                 &dice[i+15], &dice[i+16], &dice[i+17], &dice[i+18], &dice[i+19]));
        i += 20;
      }
      else
      {
        if(scanf("%d", &dice[i]));
        ++i;
      }
    }

    for(size_t i = 0; i < c; ++i)
    {
      const int p = dice[i];

      DEBUG(printf("DICE %d\n", p));
      if(play)
      {
        n = positions[i % a] + p;
        if(n >= 100) n = 100;
        positions[i % a] = board[n];
        if(board[n] == 100) play = false;
      }
      
    }

    for(size_t i = 0; i < a; ++i)
      printf("Position of player %d is %d.\n", i+1, positions[i]);

    DEBUG(printf("DONE\n"));
  }

  return 0;
}
