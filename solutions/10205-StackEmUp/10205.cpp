#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int C_MAX = 52;
const int S_MAX = 100;

const char *card(const int p)
{

  switch(p)
  {
  case 0:
    return "2";
  case 1:
    return "3";
  case 2:
    return "4";
  case 3:
    return "5";
  case 4:
    return "6";
  case 5:
    return "7";
  case 6:
    return "8";
  case 7:
    return "9";
  case 8:
    return "10";
  case 9:
    return "Jack";
  case 10:
    return "Queen";
  case 11:
    return "King";
  case 12:
    return "Ace";
  }  
  return 0;
}

const char *suit(const int p)
{
  if(p < 13)
    return "Clubs";
  if(p < 26)
    return "Diamonds";
  if(p < 39)
    return "Hearts";
  return "Spades";
}

int main()
{
  int c;

  if(scanf("%d", &c));

  for(int t = 0; t < c; ++t)
  {
    char deck[C_MAX];
    char deck2[C_MAX];
    char shuffles[S_MAX][C_MAX];

    for(int i = 0; i < C_MAX; ++i) deck[i] = i;

    int n;

    if(scanf("%d", &n));

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d"
               "%d %d %d %d %d %d %d %d %d %d %d %d %d"
               "%d %d %d %d %d %d %d %d %d %d %d %d %d"
               "%d %d %d %d %d %d %d %d %d %d %d %d %d",
               &shuffles[i][0], &shuffles[i][1], &shuffles[i][2], &shuffles[i][3], &shuffles[i][4], &shuffles[i][5], &shuffles[i][6], &shuffles[i][7], &shuffles[i][8], &shuffles[i][9], &shuffles[i][10], &shuffles[i][11], &shuffles[i][12], //13
               &shuffles[i][13], &shuffles[i][14], &shuffles[i][15], &shuffles[i][16], &shuffles[i][17], &shuffles[i][18], &shuffles[i][19], &shuffles[i][20], &shuffles[i][21], &shuffles[i][22], &shuffles[i][23], &shuffles[i][24], &shuffles[i][25], //13
               &shuffles[i][26], &shuffles[i][27], &shuffles[i][28], &shuffles[i][29], &shuffles[i][30], &shuffles[i][31], &shuffles[i][32], &shuffles[i][33], &shuffles[i][34], &shuffles[i][35], &shuffles[i][36], &shuffles[i][37], &shuffles[i][38], //13
               &shuffles[i][39], &shuffles[i][40], &shuffles[i][41], &shuffles[i][42], &shuffles[i][43], &shuffles[i][44], &shuffles[i][45], &shuffles[i][46], &shuffles[i][47], &shuffles[i][48], &shuffles[i][49], &shuffles[i][50], &shuffles[i][51])); // 13
    }

    char buffer[31];

    fgets(buffer, 31, stdin); // chew off newline

    while(fgets(buffer, 31, stdin))
    {
      int pos = atoi(buffer);

      if(pos == 0) break;

      --pos;

      for(int j = 0; j < C_MAX; ++j)
      {
        const int i = shuffles[pos][j] - 1;
        deck2[j] = deck[i];
      }

      memcpy(deck, deck2, C_MAX * sizeof(char));
    }

    if(t > 0) printf("\n");

    for(int j = 0; j < C_MAX; ++j)
    {
      printf("%s of %s\n", card(deck[j]%13), suit(deck[j]));
    }
  }
    
  return 0;
}
