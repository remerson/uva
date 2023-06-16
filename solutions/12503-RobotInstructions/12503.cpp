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

  int t;

  if(scanf("%d", &t));

  for(int q = 0; q < t; ++q)
  {
    DEBUG(printf("CASE %d =====================================\n", q));

    int n;

    if(scanf("%d\n", &n));

    DEBUG(printf("N = %d\n", n));

    constexpr int M_MAX = 128;

    int previous[M_MAX] = {0};

    char buffer[M_MAX+1] = {0};

    int pos = 0;
    int idx = 0;

    for(int i = 1; i <= n; ++i)
    {
      if(fgets(buffer, M_MAX, stdin));

      DEBUG(printf("buffer [%s]\n", buffer));

      switch(buffer[0])
      {
      case 'L':
	--pos;
	previous[i] = -1;
	break;
	
      case 'R':
	++pos;
	previous[i] = 1;
	break;

      case 'S':
	idx = atoi(&buffer[8]);
	pos += previous[idx];
	previous[i] = previous[idx];
	break;
      }

      DEBUG(printf("pos = %d idx = %d\n", pos, idx));
    }

    printf("%d\n", pos);
  }
  
  return 0;
}
