#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif



using namespace std;

int n;

const int MAX_N = 16;
const int MAX_L = 16;

char names[MAX_N][MAX_L];

int find_index(char *name)
{
   for(int i = 0; i < n; ++i)
     if(strcmp(&names[i][0], name) == 0)
       return i;

   return -1;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t = 0;
  int sums[MAX_N];

  while(scanf("%d", &n) == 1)
  {
    if(n <= 0)
      break;

    DEBUG(printf("N = %d\n", n));

    for(int i = 0; i < n; ++i)
    {
      if(scanf("%s", &names[i][0]));
      sums[i] = 0;
      DEBUG(printf("names[%d] = [%s]\n", i, &names[i][0]))
    }

    for(int i = 0; i < n; ++i)
    {
      char source[MAX_L];
      int v, m;
      
      if(scanf("%s %d %d", &source[0], &v, &m));
       
      DEBUG(printf("source = [%s] v = %d m = %d\n", &source[0], v, m));

      if(m > 0)
      {
        const int split = v / m;
        const int remain = v - (m * split);
        
        DEBUG(printf("split = %d remain = %d\n", split, remain));
        
        const int source_index = find_index(source);

        DEBUG(if(source_index == -1) printf("ERROR!!!! BAD SOURCE INDEX!\n"));
        
        sums[source_index] -= v;
        sums[source_index] += remain;
        DEBUG(printf("sums[%s] = %d\n", source, sums[source_index]));
        
        for(int j = 0; j < m; ++j)
        {
          char target[MAX_L];
          
          if(scanf("%s", &target[0]));
          
          const int target_index = find_index(target);
          
          DEBUG(printf("target = %s index = %d\n", &target[0], target_index));
          
          sums[target_index] += split;
          
          DEBUG(printf("sums[%s] = %d\n", target, sums[target_index]));
        }      
      }
    }

    if(t > 0)
      printf("\n");
    ++t;
    for(int i = 0; i < n; ++i)
      printf("%s %d\n", &names[i][0], sums[i]);
  }

  return 0;
}
  
