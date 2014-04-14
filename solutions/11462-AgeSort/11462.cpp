#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <cctype>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

inline char *read_unsigned(unsigned &v, char *b)
{
  while(!isdigit(*b)) ++b;
  v = 0;
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  return b;
}


const size_t MAX_N = 128;
const size_t B_MAX = 8192;

int main()
{
  unsigned n;

  while(scanf("%u\n", &n))
  {
    if(n == 0) break;

    unsigned ages[MAX_N] = {0};
    unsigned v;

    for(unsigned i = 0; i < n; ++i)
    {
      if(scanf("%u", &v));
      ++ages[v];
    }

    bool first = true;
    for(unsigned i = 1; i < MAX_N; ++i)
    {
      if(ages[i] > 0)
      {
        for(unsigned j = 0; j < ages[i]; ++j)
        {
          printf("%s%u", first ? "" : " ", i);
          first = false;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
