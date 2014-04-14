#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int n;

  while(scanf("%d\n", &n))
  {
    if(n == 0) break;

    int v = n;

    typedef list<int> cards;

    cards deck;
    cards discarded;

    for(int i = 1; i <= n; ++i)
      deck.push_back(i);

    while(v > 1)
    {
      discarded.push_back(deck.front());
      deck.pop_front();
      deck.push_back(deck.front());
      deck.pop_front();
      --v;
    }

    cards::const_iterator it = discarded.begin();
    const cards::const_iterator ie = discarded.end();

    printf("Discarded cards:");

    // First card, at least one
    if(it != ie)
    {
      printf(" %d", *it);
    }

    ++it;

    while(it != ie)
    {
      printf(", %d", *it);
      ++it;
    }

    printf("\nRemaining card: %d\n", *(deck.begin()));
  }

  return 0;
}
