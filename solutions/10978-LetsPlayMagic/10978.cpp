#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

string to_card(int c)
{
  string s = "XX";

  if(c > 0)
    s[1] = 'S';
  if(c > 1 * 13)
  {
    s[1] = 'D';
    c -= 1 * 13;
  }
  if(c > 1 * 13)
  {
    s[1] = 'C';
    c -= 1 * 13;
  }
  if(c > 1 * 13)
  {
    s[1] = 'H';
    c -= 1 * 13;
  }

  switch(c)
  {
  case 1:
    s[0] = 'A';
    break;
  case 10:
    s[0] = 'T';
    break;
  case 11:
    s[0] = 'J';
    break;
  case 12:
    s[0] = 'Q';
    break;
  case 13:
    s[0] = 'K';
    break;
  default:
    s[0] = '0' + c;
    break;
  }

  //DEBUG(printf("TO CARD %d => %s\n", c, s.c_str()));
  return s;
}

int from_card(const char *c)
{
  int base = 0;

  switch(c[1])
  {
  case 'S':
    break;
    

  case 'D':
    base = 1 * 13;
    break;

  case 'C':
    base = 2 * 13;
    break;

  case 'H':
    base = 3 * 13;
    break;

  }

  switch(c[0])
  {
  case 'A':
    base += 1;
    break;
  case 'T':
    base += 10;
    break;
  case 'J':
    base += 11;
    break;
  case 'Q':
    base += 12;
    break;
  case 'K':
    base += 13;
    break;
  }
    
  if(isdigit(c[0]))
  {
    base += c[0] - '0';
  }

  DEBUG(printf("FROM CARD %s => %d\n", c, base));
  
  return base;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int n;

  while(scanf("%d\n", &n) != EOF)
  {
    if(!n)
      break;

    char card[3] = {0};
    char word[32] = {0};

    int lengths[64] = {0};

    int cards[64] = {0};
    
    for(int i = 0; i < n; ++i)
    {
      if(scanf("%s %s\n", &card[0], &word[0]));

      cards[i] = from_card(&card[0]);
      lengths[i] = strlen(word);
      DEBUG(printf("READ CARD %d = %d LEN %d = %d\n", i, cards[i], i, lengths[i]));
    }

    int order[64] = {0};
    int index = 0;
    
    for(int i = 0; i < n; ++i)
    {
      int j = lengths[i];

      do
      {
        ++index;
        if(index == n)
            index = 0;
        
        if(order[index] == 0)
        {
          --j;
        }
        
      } while(j);
      
      order[index] = cards[i];
      DEBUG(printf("SET order[%d] = %s\n", index, to_card(cards[i]).c_str()));
    }

    if(n == 1)
      printf("%s\n", to_card(order[0]).c_str());
    else if(n == 2)
      printf("%s %s\n", to_card(order[1]).c_str(), to_card(order[0]).c_str());
    else
    {
      int start = 1;
      int done = false;
      
      printf("%s", to_card(order[start]).c_str());
      ++start;
      if(start >= n)
        done = true;
      
      while(!done)
      {
        if(start == n)
        {
          start = 0;
          done = true;
        }
        printf(" %s", to_card(order[start]).c_str());
        ++start;
      }
      printf("\n");
    }
  }

  return 0;
}
