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
#include <list>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

char MAX_C = 128;

struct Hand
{
  list<char> up;
  list<char> down;
};

void show_up(list<char> &up)
{
  for(auto it = up.rbegin(); it != up.rend(); ++it)
  {
    printf("%c", *it);
  }
  printf("\n");
}

void show_down(list<char> &down)
{
  for(auto it = down.begin(); it != down.end(); ++it)
  {
    printf("%c", *it);
  }
  printf("\n");
}

void dump(const char *name, Hand &hand)
{
  printf("%s UP: ", name);
  show_up(hand.up);
  printf("%s DOWN: ", name);
  show_down(hand.down);
}


Hand build()
{
  Hand player {};
  char buffer[128] = {0};
  if(scanf("%s\n", &buffer[0]));
  int l = strlen(buffer);
  for(int i = 0; i < l; ++i)
    player.down.push_back(buffer[i]);
  return player;
}

char flip(Hand &hand)
{
  if(hand.down.empty())
  {
    hand.down = hand.up; 
    hand.up.clear();
  }
  if(hand.down.empty())
  {
    DEBUG(printf("No card\n"));
    return 0;
  }
  char card = hand.down.front();
  hand.down.pop_front();
  hand.up.push_back(card);
  return card;
}

void transfer(Hand &from, Hand &to)
{
  to.up.splice(to.up.end(), from.up);
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int T;

  if(scanf("%d\n", &T));

  for(int t = 0; t < T; ++t)
  {
    if(t > 0)
    {
      printf("\n");
    }

    DEBUG(printf(">>>>>> BEGIN GAME %d\n", t));
    if(scanf("\n"));

    Hand jane = build();
    Hand john = build();

    int round = 0;
    while(++round <= 1000)
    {
      DEBUG(printf("====> BEGIN ROUND %d\n", round));
      DEBUG(dump("Jane", jane));
      DEBUG(dump("John", john));
      
      char a = flip(jane);
      char b = flip(john);

      DEBUG(printf("FLIP Jane has %c, John has %c\n", a, b));
  
      if(a == '\0')
      {
        printf("John wins.\n");
        break;
      }
      else if(b == '\0')
      {
        printf("Jane wins.\n");
        break;
      }
      else if(round == 1000)
      {
        printf("Keeps going and going ...\n");
        break;
      }
      else
      {
        if(a == b)
        {
          if((random()/141 % 2) == 0)
          {
            // jane wins
            transfer(john, jane);
            printf("Snap! for Jane: ");
            show_up(jane.up);
          }
          else
          {
            transfer(jane, john);
            printf("Snap! for John: ");
            show_up(john.up);
          }
        }
        else
        {
          DEBUG(printf("No snap :(\n"));
        }
      }
    }
  }
  
  return 0;
}
