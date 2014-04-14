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

  const int B_MAX = 4096;

  char buffer[B_MAX + 1] = {0};

  int n;

  if(scanf("%d\n", &n));
  
  for(int i = 0; i < n; ++i)
  {
    fgets(buffer, B_MAX, stdin);
    const size_t l = strlen(buffer) - 1;
    
    char result = '\n';

    DEBUG(printf("BUFFER [%s] len = %d\n", buffer, l));
    
    if(l == 1 && (buffer[0] == '1' || buffer[0] == '4'))
      result = POSITIVE;
    if(l == 2 && buffer[0] == '7' && buffer[1] == '8')
      result = POSITIVE;
    if(l >= 2 && buffer[l-1] == '5' && buffer[l-2] == '3')
      result = NEGATIVE;
    else if(l >= 2 && buffer[0] == '9' && buffer[l-1] == '4')
      result = FAILED;
    else if(l >= 3 && buffer[0] == '1' && buffer[1] == '9' && buffer[2] == '0')
      result = NOTCOMPLETE;

    if(result != '\n')
      printf("%c\n", result);
  }
}
