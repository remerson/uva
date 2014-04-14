#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_N = 64;

int main()
{
  char buffer[MAX_N] = {0};

  while(fgets(buffer, MAX_N, stdin))
  {
    if(buffer[0] == '#') break;
    size_t len = strlen(buffer);
    buffer[len - 1] = '\0';
    --len;
    if(next_permutation(buffer, buffer + len))
    {
      printf("%s\n", buffer);
    }
    else
    {
      printf("No Successor\n");
    }
  }
  

  return 0;
}

