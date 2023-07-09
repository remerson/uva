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

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

//using namespace std;

struct Sheet
{
  int fl {0};
  int fr {0};
  int bl {0};
  int br {0};
};

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int n;

  while(scanf("%d\n", &n))
  {
    if(n == 0)
      break;

    printf("Printing order for %d pages:\n", n);

    int sheets = ceil(n / 4.0);

    DEBUG(printf("SHEETS = %d\n", sheets));

    std::vector<Sheet> all;
    all.resize(sheets);

    int i = 1;
    int j = ceil(n / 4.0) * 4;
    for(int s = 0; s < sheets; ++s)
    {
      if(i <= n)
        all[s].fr = i;
      if(j <= n && j > 0)
        all[s].fl = j;
      ++i;
      --j;
      if(i <= n)
        all[s].bl = i;
      if(j <= n && j > 0)
        all[s].br = j;
      ++i;
      --j;
    }
    
    for(int i = 0; i < sheets; ++i)
    {
      if(all[i].fl != 0 && all[i].fr != 0)
        printf("Sheet %d, front: %d, %d\n", i+1, all[i].fl, all[i].fr);
      else if(all[i].fl == 0 && all[i].fr != 0)
        printf("Sheet %d, front: Blank, %d\n", i+1, all[i].fr);
      else if(all[i].fl != 0 && all[i].fr == 0)
        printf("Sheet %d, front: %d, Blank\n", i+1, all[i].fl);
      if(all[i].bl != 0 && all[i].br != 0)
        printf("Sheet %d, back : %d, %d\n", i+1, all[i].bl, all[i].br);
      else if(all[i].bl == 0 && all[i].br != 0)
        printf("Sheet %d, back : Blank, %d\n", i+1, all[i].br);
      else if(all[i].bl != 0 && all[i].br == 0)
        printf("Sheet %d, back : %d, Blank\n", i+1, all[i].bl);
    }
  }

  return 0;
}
