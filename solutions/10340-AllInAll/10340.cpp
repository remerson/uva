#include <iostream>
#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 1024 * 1024;

int main()
{
  std::ios_base::sync_with_stdio(false);

  char buffer[B_MAX + 1];

  while(fgets(buffer, B_MAX, stdin))
  {
    char *s = &buffer[0];
    char *t = s;
    while(*t != ' ') ++t;
    ++t;
    while(*s != ' ')
    {
      if(*t == *s)
        ++s;
      ++t;
      if(*t == '\n') break;
    }    
    if(*s == ' ')
      printf("Yes\n");
    else
      printf("No\n");
  }
  
  return 0;
}
