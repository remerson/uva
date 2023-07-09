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
  char buffer[512 * 1024] = {0};

  while(scanf("%s\n", &buffer[0]) != EOF)
  {
    char *b = &buffer[0];
    int len = 0;
    int start_len = 0;
    int max_len = 0;
    bool have_x = 0;
    while(*b != '\0')
    {
      if(*b == 'X')
      {
        max_len = max(len, max_len);
        len = 0;
        have_x = true;
      }
      if(*b == '.')
      {
        if(!have_x)
          ++start_len;
        ++len;
      }
      DEBUG(printf("b = %c len = %d max_len = %d\n", *b, len, max_len))
      ++b;
    }
    DEBUG(printf("END len = %d max_len = %d start_len = %d\n", len, max_len, start_len));
    max_len = max(len - 1, (max_len-1) / 2);
    max_len = max(start_len - 1, max_len);
    
    printf("%d\n", max_len);
  }

  return 0;
}
