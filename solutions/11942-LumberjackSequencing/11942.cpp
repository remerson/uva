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

const int MAX_L = 10;

int main()
{
  int t;

  if(scanf("%d", &t));

  int v[MAX_L];

  printf("Lumberjacks:\n");

  for(int i = 0; i < t; ++i)
  {
    if(scanf("%d %d %d %d %d %d %d %d %d %d",
             &v[0],
             &v[1],
             &v[2],
             &v[3],
             &v[4],
             &v[5],
             &v[6],
             &v[7],
             &v[8],
             &v[9]));

    bool increasing = (v[0] < v[1]);
    bool ordered = true;
    
    for(int j = 1; j < (MAX_L - 1); ++j)
    {
      if(increasing)
      {
        if(v[j] > v[j+1])
        {
          ordered = false;
          break;
        }
      }
      else
      {
        if(v[j] < v[j+1])
        {
          ordered = false;
          break;
        }
      }
    }

    if(!ordered)
      printf("Unordered\n");
    else
      printf("Ordered\n");
  }
  

  return 0;
}
