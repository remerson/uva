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

//typedef pair<int, bool> car; //  first->length, second->true/left, false/right

//typedef std::deque<car> arrival_order;

typedef std::deque<int> arrivals;

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
    int l, m;

    if(scanf("%d %d\n", &l, &m));

    l = l * 100;

    DEBUG(printf("L = %d M = %d\n", l, m));

    arrivals left;
    arrivals right;

    int v;
    char buffer[B_MAX + 1];

    for(int i = 0; i < m; ++i)
    {
      if(scanf("%d %s\n", &v, buffer));
      DEBUG(printf("READ v = %d buffer = [%s]\n", v, buffer));
      if(buffer[0] == 'l')
        left.push_back(v);
      else
        right.push_back(v);
    }

    bool side = LEFT_BANK;
    arrivals *current = &left;

    int crossings = 0;

    while(!left.empty() || !right.empty())
    {
      int load = 0;

      DEBUG(printf("%c current = %d\n", (side ? 'L' : 'R'), current->size()));

      while(!current->empty())
      {
        DEBUG(printf("check = %d load = %d l = %d\n", current->front(), load, l));
        if(load + current->front() <= l)
        {
          load += current->front();
          DEBUG(printf("add = %d load = %d\n", current->front(), load));
          current->pop_front();
        }
        else
          break;
      }

      ++crossings;

      DEBUG(printf("crossings = %d\n", crossings));

      if(side == LEFT_BANK)
      {
        side = RIGHT_BANK;
        current = &right;
      }
      else
      {
        side = LEFT_BANK;
        current = &left;
      }
    }

    printf("%d\n", crossings);
  }

  return 0;
}
