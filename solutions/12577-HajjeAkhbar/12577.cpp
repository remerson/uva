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
  int c = 0;

  char buffer[256];

  while(scanf("%s\n", &buffer[0]))
  {
    if(buffer[0] == '*')
      break;

    if(strcmp(buffer, "Hajj") == 0)
    {
      printf("Case %d: Hajj-e-Akbar\n", ++c);
    }
    else
    {
      printf("Case %d: Hajj-e-Asghar\n", ++c);  
    }
  }

  return 0;
}
