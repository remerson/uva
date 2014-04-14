#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int C_MAX = 32;
const int T_MAX = 128;

char translate[T_MAX] = {0};


int main()
{
  translate['A'] = '2';
  translate['B'] = '2';
  translate['C'] = '2';
  
  translate['D'] = '3';
  translate['E'] = '3';
  translate['F'] = '3';
  
  translate['G'] = '4';
  translate['H'] = '4';
  translate['I'] = '4';
  
  translate['J'] = '5';
  translate['K'] = '5';
  translate['L'] = '5';
  
  translate['M'] = '6';
  translate['N'] = '6';
  translate['O'] = '6';

  translate['P'] = '7';
  translate['Q'] = '7';
  translate['R'] = '7';
  translate['S'] = '7';

  translate['T'] = '8';
  translate['U'] = '8';
  translate['V'] = '8';

  translate['W'] = '9';
  translate['X'] = '9';
  translate['Y'] = '9';
  translate['Z'] = '9';

  char buffer[C_MAX + 1];

  while(fgets(buffer, C_MAX,stdin))
  {
    const int len = strlen(buffer);

    for(int i = 0; i < len; ++i)
    {
      if(translate[buffer[i]])
        buffer[i] = translate[buffer[i]];
    }

    write(1, &buffer[0], len);
  }

  return 0;
}
