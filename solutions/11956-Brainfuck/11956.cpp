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

const int M_MAX = 100;
const int B_MAX = 1024 * 128;

int main()
{
  unsigned memory[M_MAX];
  char buffer[B_MAX];
  unsigned *p;
  char *b;
  int c;

  if(scanf("%d\n", &c));

  for(int t = 1; t <= c; ++t)
  {
    if(fgets(&buffer[0], B_MAX, stdin));
    memset(&memory[0], 0, sizeof(unsigned) * M_MAX);
    p = &memory[0];
    b = &buffer[0];

    while(*b != '\n')
    {
      switch(*b)
      {
      case '>':
        if(p == &memory[M_MAX - 1]) p = &memory[0];
        else ++p;
        break;
      case '<':
        if(p == &memory[0]) p = &memory[M_MAX - 1];
        else --p;
        break;
      case '+':
        if(*p == 255) *p = 0;
        else ++(*p);
        break;
      case '-':
        if(*p == 0) *p = 255;
        else --(*p);
        break;
      }
      ++b;
    }
    printf("Case %d:", t);
    for(int i = 0; i < M_MAX; ++i) printf(" %02X", memory[i]);
    printf("\n");
  }

  return 0;
}
