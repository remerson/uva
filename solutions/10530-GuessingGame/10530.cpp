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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const int N_MAX = 11;

  int v;
  bitset<N_MAX> lower;
  bitset<N_MAX> higher;
  char buffer[32] = {0};

  while(true)
  {
    if(scanf("%d\n", &v));

    if(v == 0)
      break;

    if(fgets(&buffer[0], 31, stdin));
    
    DEBUG(printf("BUFFER [%s]\n", &buffer[0]));

    if(buffer[4] == 'h')
      higher[v] = true;
    else if(buffer[4] == 'l')
      lower[v] = true;
    else
    {
      bool honest = true;

      for(size_t i = 1; i <= 10; ++i)
      {
        if(higher[i] && i <= v)
        {
          honest = false;
          break;
        }

        if(lower[i] && i >= v)
        {
          honest = false;
          break;
        }
      }

      lower.reset();
      higher.reset();

      if(honest)
        printf("Stan may be honest\n");
      else
        printf("Stan is dishonest\n");
    }
    
      
  }

  return 0;
}
