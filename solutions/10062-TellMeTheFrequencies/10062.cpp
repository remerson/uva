#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

/////////////////////////////////////////////////////////////

typedef pair<char, unsigned short> CharCount;

struct CountComp
{
  bool operator()(const CharCount &lhs, const CharCount &rhs) const
  {
    if(lhs.second == rhs.second)
      return rhs.first < lhs.first;

    return lhs.second < rhs.second;
  }
};

int main()
{
  const size_t B_MAX = 2048;
  const size_t C_MAX = 128 - 32;

  unsigned t = 0;

  char buffer[B_MAX + 1];

  while(fgets(buffer, B_MAX, stdin) != 0)
  {
    //if(buffer[0] == '\n')
    //  break;

    DEBUG(printf("buffer [%s]\n", &buffer[0]));

    if(t > 0)
      printf("\n");
    ++t;

    CharCount frequency[C_MAX];

    for(size_t i = 0; i < C_MAX; ++i)
    {
      frequency[i].first = i + 32;
      frequency[i].second = 0;
    }

    const char *b = &buffer[0];

    while(*b != '\n')
    {
      ++frequency[*b - 32].second;
      ++b;
    }

    sort(frequency, frequency + C_MAX, CountComp());

    for(size_t i = 0; i < C_MAX; ++i)
    {
      if(frequency[i].second == 0)
        continue;

      printf("%d %hu\n", frequency[i].first, frequency[i].second);
    }

    
  }

  return 0;
}
