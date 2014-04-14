#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 32;
const int S_MAX = 5;

const char *format = "%8s %-24s %s\n";

char scode(char c)
{
  char code = '0';
  
  switch(c)
    {
    case 'B':
    case 'P':
    case 'F':
    case 'V':
      code = '1';
    break;
    case 'C':
    case 'S':
    case 'K':
    case 'G':
    case 'J':
    case 'Q':
    case 'X':
    case 'Z':
      code = '2';
    break;
    case 'D':
    case 'T':
      code = '3';
    break;
    case 'L':
      code = '4';
      break;
    case 'M':
    case 'N':
      code = '5';
    break;
    case 'R':
      code = '6';
      break;
    default:
      break;
    }
  return code;
}
      
int main()
{
  char buffer[B_MAX];
  char soundex[S_MAX];

  printf(format, "", "NAME", "SOUNDEX CODE");

  while(fgets(&buffer[0], B_MAX, stdin) != 0)
  {
    soundex[0] = buffer[0];
    soundex[1] = '0';
    soundex[2] = '0';
    soundex[3] = '0';
    soundex[4] = '\0';

    int index = 1;
    char code = '0';
    int len = strlen(buffer);
    len--;
    buffer[len] = '\0';
    char last = scode(buffer[0]);

    for(int i = 1; i < len; ++i)
    {
      const char a = scode(buffer[i]);
      const char b = last;
      last = a;

      if(a == '0' || a == b) continue;

      soundex[index] = a;
      ++index;
      if(index > 3) break;
    }

    printf(format, "", &buffer[0], &soundex[0]);
  }

  printf("%19s%s\n", "", "END OF OUTPUT");

  return 0;
}
