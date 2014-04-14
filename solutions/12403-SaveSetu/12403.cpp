#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

namespace io
{
  inline char *read_unsigned(unsigned &v, char *b)
  {
    while(!isdigit(*b)) ++b;
    v = 0;

    while(isdigit(*b)) 
      v = v * 10 + *(b++) - '0';
    return b;
  }

  unsigned len;

  inline char *write_unsigned(unsigned i, char *b)
  {
    char const digit[] = "0123456789";
    char* p = b;
    
    int shifter = i;
    do{ //Move to where representation ends
      ++p;
      shifter = shifter/10;
    }while(shifter);
    char *e = p;
    ++e;
    *p = '\n';
    do{ //Move back, inserting digits as u go
      *--p = digit[i%10];
      i = i/10;
    }while(i);
    len += e - b;
    return e;
  }

}

const unsigned B_MAX = 64;

const unsigned OUT_MAX = 64 * 128;

using namespace io;

int main()
{
  char buffer[B_MAX];
  char output[OUT_MAX];

  char *out = output;

  unsigned t;
  unsigned total = 0;
  unsigned v;
  len = 0;

  char *b = fgets(buffer, B_MAX - 1, stdin);

  b = read_unsigned(t, b);

  for(int i = 0; i < t; ++i)
  {
    char *b = fgets(buffer, B_MAX - 1, stdin);

    if(*b == 'r')
    {
      out = write_unsigned(total, out);
    }
    else
    {
      b = read_unsigned(v, b);
      total += v;
    }
  }

  write(1, output, len); 

  return 0;
}
