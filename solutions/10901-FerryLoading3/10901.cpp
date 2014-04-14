#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 64;

const int N_MAX = 16 * 1024;

typedef pair<int, bool> car; //  first->time, second->true/left, false/right

typedef std::deque<car> arrival_order;

const bool LEFT_BANK = true;
const bool RIGHT_BANK = false;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int c;

  if(scanf("%d\n", &c));

  DEBUG(printf("C = %d\n", c));

  for(int q = 0; q < c; ++q)
  {
    if(q > 0)
      printf("\n");
    int n, t, m;

    if(scanf("%d %d %d\n", &n, &t, &m));

    DEBUG(printf("N = %d T = %d M = %d\n", n, t, m));

    arrival_order ordering;

    int v;
    char buffer[B_MAX + 1];

    for(int i = 0; i < m; ++i)
    {
      if(scanf("%d %s\n", &v, buffer));
      DEBUG(printf("READ v = %d buffer = [%s]\n", v, buffer));
      if(buffer[0] == 'l')
        ordering.push_back(car(v, true));
      else
        ordering.push_back(car(v, false));
    }

    int now = 0;

    typedef deque<int> bank;

    bank left;
    bank right;
    bank ferry;

    bank *current = &left;
    bank *other = &right;
    bool side = LEFT_BANK;

    int times[N_MAX];

    int k = 0;

    while(!ordering.empty() || (left.size() > 0) || (right.size() > 0))
    {
      // Advance time up to "now"
      DEBUG(printf("ADVANCE   T = %d\n", now));
      while(!ordering.empty() && ordering.front().first <= now)
      {
        if(ordering.front().second)
          left.push_back(k);
        else
          right.push_back(k);
        ++k;
        ordering.pop_front();
      }

      // Wait at the current bank until a car arrives at either side
      if(left.empty() && right.empty())
      {
        if(ordering.empty())
          break;
        
        now = ordering.front().first;

        DEBUG(printf("WAIT    %s T = %d ferry = %d left = %d right = %d c = %d o = %d\n", (side ? "L" : "R"), now, ferry.size(), left.size(), right.size(), current->size(), other->size()));
        continue;
      }
   
      DEBUG(printf("LOAD    %s T = %d ferry = %d left = %d right = %d c = %d o = %d\n", (side ? "L" : "R"), now, ferry.size(), left.size(), right.size(), current->size(), other->size()));

      // Load
      while(!current->empty() && ferry.size() < n)
      {
        ferry.push_back(current->front());
        current->pop_front();
      }
      
      DEBUG(printf("LOADED  %s T = %d ferry = %d left = %d right = %d c = %d o = %d\n", (side ? "L" : "R"), now, ferry.size(), left.size(), right.size(), current->size(), other->size()));

      now += t;
      
      if(side == LEFT_BANK)
      {
        swap(current, other);
        side = RIGHT_BANK;  
      } 
      else
      {
        swap(current, other);
        side = LEFT_BANK;
      }
    
      DEBUG(printf("UNLOAD  %s T = %d ferry = %d left = %d right = %d c = %d o = %d\n", (side ? "L" : "R"), now, ferry.size(), left.size(), right.size(), current->size(), other->size()));

      // Unload
      while(ferry.size() > 0)
      {
        DEBUG(printf("TIMES %d -> %d\n", ferry.front(), now));
        times[ferry.front()] = now;
        ferry.pop_front();
      }

      DEBUG(printf("EMPTY   %s T = %d ferry = %d left = %d right = %d c = %d o = %d\n", (side ? "L" : "R"), now, ferry.size(), left.size(), right.size(), current->size(), other->size()));
    }

    for(int j = 0; j < m; ++j)
    {
      printf("%d\n", times[j]);
    }
  }

  return 0;
}
