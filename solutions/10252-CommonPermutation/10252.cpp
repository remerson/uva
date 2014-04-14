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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const size_t LEN_MAX = 1024;

  char a[LEN_MAX + 1];
  char b[LEN_MAX + 1];

  while(fgets(a, LEN_MAX, stdin))
  {
    fgets(b, LEN_MAX, stdin);
    DEBUG(printf("a = [%s]\n", a));
    DEBUG(printf("b = [%s]\n", b));

    const size_t C_MAX = 255;

    unsigned short a_count[C_MAX] = {0};
    unsigned short b_count[C_MAX] = {0};

    {
      const char *u = a;

      while(*u && *u != '\n')
      {
        ++a_count[tolower(*u)];
        ++u;
      }
    }
    
    {
      const char *u = b;

      while(*u && *u != '\n')
      {
        ++b_count[tolower(*u)];
        ++u;
      }
    }

    for(size_t i = 'a'; i <= 'z'; ++i)
    {
      const unsigned short m = min(a_count[i], b_count[i]);
      if(m > 0)
        for(size_t j = 0; j < m; ++j)
          printf("%c", i);
    }
    printf("\n");
  }

  return 0;
}
