#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using std::bitset;

const size_t P_MAX = 1024;

const size_t B_MAX = P_MAX * 8;

char buffer[B_MAX];

int main()
{  
  int t;

  if(scanf("%d", &t));
  DEBUG(printf("TESTS = %d\n", t));

  int counts[P_MAX];

  for(int q = 0; q < t; ++q)
  {
    int p;

    if(scanf("%d\n", &p));

    DEBUG(printf("P = %d\n", p));

    int min_count = P_MAX;

    for(int i = 0; i < p; ++i)
      counts[i] = 0;

    for(int i = 0; i < p; ++i)
    {
      fgets(buffer, B_MAX, stdin);
      char *b = buffer;
      while(*b != '\n')
        if(*(b++) == ' ') ++counts[i];
      
      if(counts[i] < min_count) min_count = counts[i];      
    }

    bool printed = false;

    for(int i = 0; i < p; ++i)
    {
      if(counts[i] == min_count)
      {
        if(printed)
          printf(" %d", i+1);
        else
        {
          printf("%d", i+1);
          printed = true;
        }
      }
    }
    printf("\n"); 
  }

  return 0;
}
