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
  const size_t B_MAX = 128;
  char buffer[B_MAX];

  while(true)
  {
    if(fgets(buffer, B_MAX, stdin) == NULL)
      break;

    int digit;
    int s1 = 0;
    int s2 = 0;
    int count = 0;

    char *start = &buffer[0];

    DEBUG(printf("buffer = [%s]\n", buffer));

    while(isspace(*start))
      ++start;

    char *end = &buffer[strlen(buffer)-1];
    //*end = '\0';
    //--end;

    DEBUG(printf("END = %d\n", *end));

    while(isspace(*end))
    {
      DEBUG(printf("(space) END = %d\n", *end));
      --end;
    }

    DEBUG(printf("(NOT SPACE) END = %d\n", *end));
    ++end;
    *end = '\0';

    char *b = start;

    while(b != end)
    {
      DEBUG(printf("b = %c\n", *b));
      if(isdigit(*b) || *b == 'X')
      {
        if(*b == 'X')
        {
          if(count == 9)
            digit = 10;
          else
          {
            count = 11;
            break;
          }
        }
        else
          digit = *b - '0';
        
        s1 += digit;
        s2 += s1;
        DEBUG(printf("count = %d digit = %d s1 = %d s2 = %d\n", count, digit, s1, s2));
        ++count;
        ++b;
      }
      else if(*b == '-')
        ++b;
      else
      {
        count = 0;
        break;
      }
    }

    if(count == 10 && ((s2 % 11) == 0))
      printf("%s is correct.\n", start);
    else
      printf("%s is incorrect.\n", start);

    
  }
  
  

  return 0;
}
