#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const char POSITIVE = '+';
const char NEGATIVE = '-';
const char FAILED = '*';
const char NOTCOMPLETE = '?';

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const int B_MAX = 32;

  char buffer[B_MAX + 1];
  char output[B_MAX + 1]; 

  while(fgets(buffer, B_MAX, stdin))
  {
    const size_t l = strlen(buffer) - 1;
    size_t next = 0;
    char last = '9';

    DEBUG(printf("BUFFER [%s] len = %d\n", buffer, l));

    for(size_t i = 0; i < l; ++i)
    {
      char score = '0';

      switch(buffer[i])
      {
      case 'A':
        break;
      case 'B':
        score = '1';
        break;
      case 'C':
        score = '2';
        break;
      case 'D':
        score = '3';
        break;
      case 'E':
        break;
      case 'F':
        score = '1';
        break;
      case 'G':
        score = '2';
        break;
      case 'H':
        break;
      case 'I':
        break;
      case 'J':
        score = '2';
        break;
      case 'K':
        score = '2';
        break;
      case 'L':
        score = '4';
        break;
      case 'M':
        score = '5';
        break;
      case 'N':
        score = '5';
        break;
      case 'O':
        break;
      case 'P':
        score = '1';
        break;
      case 'Q':
        score = '2';
        break;
      case 'R':
        score = '6';
        break;
      case 'S':
        score = '2';
        break;
      case 'T':
        score = '3';
        break;
      case 'U':
        break;
      case 'V':
        score = '1';
        break;
      case 'W':
        break;
      case 'X':
        score = '2';
        break;
      case 'Y':
        break;
      case 'Z':
        score = '2';
        break;
      }
    
      if(score != last)
      {
        last = score;
        if(score != '0')
          output[next++] = score;
      }
    }

    output[next++] = '\0';
    
    printf("%s\n", output);
  }
}
