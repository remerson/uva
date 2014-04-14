#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 6;
const int W_MAX = 32;

struct Board
{
  char board[B_MAX][B_MAX];
  size_t i;
  size_t j;
  size_t c;
};

char word[W_MAX];

bool backtrack(const size_t l, Board initial)
{
  stack<Board> pending;

  pending.push(initial);

  while(!pending.empty())
  {
    Board board = pending.top();
    pending.pop();

    const size_t i = board.i;
    const size_t j = board.j;
    const size_t c = board.c;

    if(c == l) return true;

    if(word[c] == board.board[i+1][j])
    {
      Board next = board;
      next.c++;
      next.i = i+1;
      next.j = j;
      next.board[i+1][j] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i+1][j-1])
    {
      Board next = board;
      next.c++;
      next.i = i+1;
      next.j = j-1;
      next.board[i+1][j-1] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i+1][j+1])
    {
      Board next = board;
      next.c++;
      next.i = i+1;
      next.j = j+1;
      next.board[i+1][j+1] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i][j-1])
    {
      Board next = board;
      next.c++;
      next.i = i;
      next.j = j-1;
      next.board[i][j-1] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i][j+1])
    {
      Board next = board;
      next.c++;
      next.i = i;
      next.j = j+1;
      next.board[i][j+1] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i-1][j+1])
    {
      Board next = board;
      next.c++;
      next.i = i-1;
      next.j = j+1;
      next.board[i-1][j+1] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i-1][j])
    {
      Board next = board;
      next.c++;
      next.i = i-1;
      next.j = j;
      next.board[i-1][j] = 0; // mark;
      pending.push(next);
    }

    if(word[c] == board.board[i-1][j-1])
    {
      Board next = board;
      next.c++;
      next.i = i-1;
      next.j = j-1;
      next.board[i-1][j-1] = 0; // mark;
      pending.push(next);
    }
    
  }

  return false;
}

bool boggle(size_t len, const Board &initial)
{
  for(int i = 1; i <= 4; ++i)
    for(int j = 1; j <= 4; ++j)
      {
        if(word[0] == initial.board[i][j]) 
        {
          DEBUG(printf("START %d %d\n", i, j));
          Board next = initial;
          next.i = i;
          next.j = j;
          next.c = 1;
          next.board[i][j] = 0;
          if(backtrack(len, next)) return true;
        }
      }

  DEBUG(printf("NO MATCH\n"));
  return false;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n;

  if(scanf("%d", &n));

  DEBUG(printf("TOTAL GAMES %d\n", n));

  for(int g = 1; g <= n; ++g)
  {
    if(scanf("\n"));

    DEBUG(printf("GAME %d\n", g));

    Board board;

    for(int i = 1; i <= 4; ++i)
      if(scanf("%c%c%c%c\n", &board.board[i][1], &board.board[i][2], &board.board[i][3], &board.board[i][4]));
    
    DEBUG(printf("BOARD:\n"));
    DEBUG(printf("\n%c%c%c%c\n", board.board[1][1], board.board[1][2], board.board[1][3], board.board[1][4]));
    DEBUG(printf("%c%c%c%c\n", board.board[2][1], board.board[2][2], board.board[2][3], board.board[2][4]));
    DEBUG(printf("%c%c%c%c\n", board.board[3][1], board.board[3][2], board.board[3][3], board.board[3][4]));
    DEBUG(printf("%c%c%c%c\n\n", board.board[4][1], board.board[4][2], board.board[4][3], board.board[4][4]));

    int m;

    if(scanf("%d", &m));

    int score = 0;

    for(int w = 0; w < m; ++w)
    {
      if(scanf("%s", word));

      DEBUG(printf("WORD [%s]\n", word));

      const size_t len = strlen(word);

      DEBUG(printf("LEN = %d\n", len));

      int word_score = 0;

      if(len > 2)
      {        
        if(boggle(len, board))
        {
          switch(len)
          {
          case 0:
          case 1:
          case 2:
            break;
          case 3:
          case 4:
            word_score = 1;
            break;
          case 5:
            word_score = 2;
            break;
          case 6:
            word_score = 3;
            break;
          case 7:
            word_score = 5;
            break;
          default:
            word_score = 11;
          }        
        }
      }

      score += word_score;

      DEBUG(printf("WORD SCORE %d TOTAL %d\n", word_score, score));
    }
    printf("Score for Boggle game #%d: %d\n", g, score);
  }
   

  return 0;
}
