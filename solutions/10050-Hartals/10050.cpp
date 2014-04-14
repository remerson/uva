#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_N = 4096;
const int MAX_P = 128;

int main()
{
  std::ios_base::sync_with_stdio(false);

  DEBUG(printf("Started\n"));

  bitset<MAX_N> holidays;

  for(int i = 6; i < MAX_N; i += 7)
  {
      holidays[i] = true;
      holidays[i+1] = true;
  }

  DEBUG(printf("Finished hols\n"));

  int t;

  if(scanf("%d", &t));

  DEBUG(printf("T = %d\n", t));

  for(int c = 0; c < t; ++c)
  {
    DEBUG(printf("C = %d\n", c));
    int n, p;
    if(scanf("%d", &n));
    DEBUG(printf("N = %d\n", n));
    unsigned hartals[MAX_P];
    if(scanf("%d", &p));
    DEBUG(printf("P = %d\n", p));
    for(int i = 0; i < p; ++i)
    {
      if(scanf("%u", &hartals[i]));
      DEBUG(printf("hartals[%d] = %d\n", i, hartals[i]));
    }
    
    bitset<MAX_N> days = holidays;

    unsigned count = 0;

    for(int i = 0; i < p; ++i)
    {
      DEBUG(printf("Carving hartals[%d] = %d\n", i, hartals[i]));
      for(int j = hartals[i]; j <= n; j+= hartals[i])
      {
        DEBUG(printf("Checking day %d\n", j));
        if(!days[j])
        {
          days[j] = true;
          ++count;
          DEBUG(printf("Marked day %d -> count = %d\n", j, count));
        }
      }
    }

    printf("%d\n", count);
  }

  return 0;
}
