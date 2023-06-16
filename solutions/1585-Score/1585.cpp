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
  int T;
  size_t MAX_LEN = 128;
  char buffer[MAX_LEN];

  if(scanf("%d\n", &T));

  for(int t = 0; t < T; ++t)
  {
    if(scanf("%s\n", &buffer[0]));
    int i = 0;
    int l = 0;
    int total = 0;
    while(buffer[i] != '\0')
    {
      if(buffer[i] == 'X')
      {
        total += l * (l + 1) / 2;
        l = 0;
      }
      else
      {
        ++l;
      }
      DEBUG(printf("buffer[%d] = %c l = %d total = %d\n", i, buffer[i], l, total));
      ++i;
    }
    total += l * (l + 1) / 2;
    
    printf("%d\n", total);
  }
  
  return 0;
}
