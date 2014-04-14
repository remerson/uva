#include <cstdio>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t B_MAX = 8;

int main()
{
  int n, l;

  if(scanf("%d\n", &n) == 1);

  char buffer[B_MAX];

  do
  {
    if(fgets(&buffer[0], B_MAX, stdin));

    l = strlen(&buffer[0]);

    if(l == 3 && strcmp(&buffer[0], "one") == 0 || 
       (buffer[0] == 'o' && buffer[1] == 'n') ||
       (buffer[0] == 'o' && buffer[2] == 'e') ||
       (buffer[1] == 'n' && buffer[2] == 'e'))
    {
      printf("1\n");
    }
    else if(l == 3 && strcmp(&buffer[0], "two") == 0 || 
            (buffer[0] == 't' && buffer[1] == 'w') ||
            (buffer[0] == 't' && buffer[2] == 'o') ||
            (buffer[1] == 'w' && buffer[2] == 'o'))
    {
      printf("2\n");
    }
    else if(l == 5 && strcmp(&buffer[0], "three") == 0 || 
            (buffer[0] == 't' && buffer[1] == 'h' && buffer[2] == 'r' && buffer[3] == 'e') ||
            (buffer[0] == 't' && buffer[1] == 'h' && buffer[2] == 'r' && buffer[4] == 'e') ||
            (buffer[0] == 't' && buffer[1] == 'h' && buffer[3] == 'e' && buffer[4] == 'e') ||
            (buffer[0] == 't' && buffer[2] == 'r' && buffer[3] == 'e' && buffer[4] == 'e') ||
            (buffer[1] == 'h' && buffer[2] == 'r' && buffer[3] == 'e' && buffer[4] == 'e'))
    {
      printf("3\n");
    }
  }
  while(--n > 0);


  return 0;
}
