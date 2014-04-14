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

bool is_palindrome(char *c)
{
  char *u = c;
  char *v = c;

  while(*v != '\0')
    ++v;

  --v;
  
  while(u < v)
  {
    if(*u != *v)
      return false;
    ++u;
    --v;
  }
  return true;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const size_t B_MAX = 4096;

  char buffer[B_MAX + 1];

  while(fgets(buffer, B_MAX, stdin))
  {
    if(strncmp(buffer, "DONE", 4) == 0)
      break;
    
    DEBUG(printf("buffer = [%s]\n", buffer));

    char clean[B_MAX + 1];

    char *b = &buffer[0];
    char *c = &clean[0];

    while(*b != '\0')
    {
      if(isupper(*b) || islower(*b))
      {
        *c = tolower(*b);
        ++c;
      }
      ++b;
    }

    *c = '\0';

    DEBUG(printf("clean = [%s]\n", clean));

    if(is_palindrome(&clean[0]))
      printf("You won't be eaten!\n");
    else
      printf("Uh oh..\n");

    
  }

  return 0;
}
