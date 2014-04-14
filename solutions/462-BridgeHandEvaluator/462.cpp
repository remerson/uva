#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const int C_MAX = 13;
const int S_MAX = 4;

using namespace std;

char face[C_MAX];
char suit[C_MAX];
int counts[S_MAX];
bool stopped[S_MAX];

int hash(char i)
{
  switch(i)
  {
  case 'S':
    return 0;
  case 'H':
    return 1;
  case 'D':
    return 2;
  case 'C':
    return 3;
  }
}

char reverse_hash(int i)
{
  switch(i)
  {
  case 0:
    return 'S';
  case 1:
    return 'H';
  case 2:
    return 'D';
  case 3:
    return 'C';
  }
}

int main()
{

  while(scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c\n", &face[0], &suit[0], &face[1], &suit[1], &face[2], &suit[2], &face[3], &suit[3], &face[4], &suit[4], &face[5], &suit[5], &face[6], &suit[6], &face[7], &suit[7], &face[8], &suit[8], &face[9], &suit[9], &face[10], &suit[10], &face[11], &suit[11], &face[12], &suit[12]) == 26)
  {
    int score = 0;

    for(size_t i = 0; i < S_MAX; ++i)
    {
      counts[i] = 0;
      stopped[i] = false;
    }

    for(size_t i = 0; i < C_MAX; ++i)
    {
      switch(face[i])
      {
      case 'A':
        score += 4;
        DEBUG(printf("1) A score = %d\n", score));
        break;
      case 'K':
        score += 3;
        DEBUG(printf("1) K score = %d\n", score));
        break;
      case 'Q':
        score += 2;
        DEBUG(printf("1) Q score = %d\n", score));
        break;
      case 'J':
        ++score;
        DEBUG(printf("1) J score = %d\n", score));
        break;
      }

      DEBUG(printf("1) suit[%c] = %d\n", suit[i], hash(suit[i])));
      suit[i] = hash(suit[i]);

      ++counts[suit[i]];

      DEBUG(printf("1) counts[%c] = %d\n", reverse_hash(suit[i]), counts[suit[i]]));
    }

    DEBUG(printf("END 1 score = %d\n", score));

    for(size_t i = 0; i < C_MAX; ++i)
    {
      switch(face[i])
      {
      case 'A':
        DEBUG(printf("2) A stopped %c\n", reverse_hash(suit[i])));
        stopped[suit[i]] = true;
        break;
      case 'K':
        DEBUG(printf("2) K count[%c] = %d\n", reverse_hash(suit[i]), counts[suit[i]]));
        if(counts[suit[i]] == 1) 
        {
          --score;
          DEBUG(printf("2) K score = %d\n", score));
        }
        if(counts[suit[i]] >= 2)
        {
          DEBUG(printf("2) K stopped %c\n", reverse_hash(suit[i])));
          stopped[suit[i]] = true;
        }
        break;
      case 'Q':
        DEBUG(printf("2) Q count[%c] = %d\n", reverse_hash(suit[i]), counts[suit[i]]));
        if(counts[suit[i]] <= 2)
        {
          --score;
          DEBUG(printf("2) Q score = %d\n", score));
        }
        if(counts[suit[i]] >= 3)
        {
          DEBUG(printf("2) Q stopped %c\n", reverse_hash(suit[i])));
          stopped[suit[i]] = true;
        }
        break;
      case 'J':
        DEBUG(printf("2) J count[%c] = %d\n", reverse_hash(suit[i]), counts[suit[i]]));
        if(counts[suit[i]] <= 3)
        {
          --score;
          DEBUG(printf("2) J score = %d\n", score));
        }
        break;
      }
    }

    DEBUG(printf("END 2 score = %d\n", score));

    if(score >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3])
    {
      printf("BID NO-TRUMP\n");
    }
    else
    {
      for(int i = 0; i < S_MAX; ++i)
      {
        if(counts[i] == 2) ++score;
        if(counts[i] == 1) score += 2;
        if(counts[i] == 0) score += 2;
      }

      DEBUG(printf("EXTRA score = %d\n", score));

      if(score >= 14)
      {
        int max_index = 0;
        int max_total = counts[0];

        DEBUG(printf("3) SET max_index = %c max_total = %d\n", reverse_hash(max_index), max_total));

        for(int i = 1; i < S_MAX; ++i)
        {
          DEBUG(printf("3) counts[%c] = %d max_total = %d\n", reverse_hash(i), counts[i], max_total));
          if(counts[i] > max_total)
          {
            max_total = counts[i];
            max_index = i;
            DEBUG(printf("3) SET max_index = %c max_total = %d\n", reverse_hash(max_index), max_total));
          }
        }

        printf("BID %c\n", reverse_hash(max_index));
      }
      else
      {
        printf("PASS\n"); // ?????
      }
    }
  }

  return 0;
}
