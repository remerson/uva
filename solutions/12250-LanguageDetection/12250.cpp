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

  const size_t B_MAX = 32;

  char buffer[B_MAX + 1];
  int c = 0;

  while(fgets(buffer, B_MAX, stdin))
  {
    if(buffer[0] == '#')
      break;

    DEBUG(printf("buffer [%s]\n", buffer));

    if(strncmp(buffer, "HELLO", 5) == 0)
      printf("Case %d: ENGLISH\n", ++c);
    else if(strncmp(buffer, "HOLA", 4) == 0)
      printf("Case %d: SPANISH\n", ++c);
    else if(strncmp(buffer, "HALLO", 5) == 0)
      printf("Case %d: GERMAN\n", ++c);
    else if(strncmp(buffer, "BONJOUR", 7) == 0)
      printf("Case %d: FRENCH\n", ++c);
    else if(strncmp(buffer, "CIAO", 4) == 0)
      printf("Case %d: ITALIAN\n", ++c);
    else if(strncmp(buffer, "ZDRAVSTVUJTE", 12) == 0)
      printf("Case %d: RUSSIAN\n", ++c);
    else
      printf("Case %d: UNKNOWN\n", ++c);

  }
  
  return 0;
}
