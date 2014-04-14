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

const size_t N_MAX = 128;

const size_t B_MAX = 6 * N_MAX;

char buffer[B_MAX];

inline char *read_int(int &v, char *b)
{ 
  bool negative = false;
  v = 0;
  while(!isdigit(*b))
  {
    if(*b == '-')
      negative = true;
    ++b;
  }
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  if(negative) v *= -1;
  return b;
}

int main()
{
  int t;

  if(scanf("%d", &t));

  for(int w = 0; w < t; ++w)
  {  
    int n, s, q;
    if(scanf("%d %d %d\n", &n, &s, &q));
    DEBUG(printf("N = %d S = %d Q = %d\n", n, s, q));
    std::queue<int> stations[N_MAX];
    for(int i = 1; i <= n; ++i)
    {
      int c;
      char *b = fgets(buffer, B_MAX - 1, stdin);
      b = read_int(c, b);
      DEBUG(printf("read c = %d\n", c));
      for(int j = 0; j < c; ++j)
      {
        int v;
        b = read_int(v, b);
        DEBUG(printf("STATION %d QUEUE %d\n", i, v));
        stations[i].push(v);
      }
    }

    int current = 1;
    int time = -2;
    int cargo[N_MAX];
    cargo[0] = 0;

    bool run = false;
    for(int i = 1; i <= n; ++i) run |= stations[i].size();

    while(run)
    {
      time += 2;
      current %= (n + 1);
      if(current == 0) current = 1;

      DEBUG(printf("TIME = %d STATION %d (%d waiting) CARGO %d:", time, current, stations[current].size(), cargo[0]));
      DEBUG(for(int p = 1; p <= cargo[0]; ++p) printf(" %d", cargo[p]); printf("\n"));

      while(cargo[0] > 0)
      {
        if(cargo[cargo[0]] == current)
        {
          DEBUG(printf("UNLOAD %d\n", cargo[cargo[0]]));
          --cargo[0];
          ++time;
        }
        else if(stations[current].size() < q)
        {
          stations[current].push(cargo[cargo[0]]);
          DEBUG(printf("QUEUE %d (%d waiting)\n", cargo[cargo[0]], stations[current].size()));
          --cargo[0];
          ++time;
        }
        else break;
      }

      while(cargo[0] < s)
      {
        if(!stations[current].empty())
        {
          cargo[++cargo[0]] = stations[current].front();
          DEBUG(printf("LOAD %d (%d loaded)\n", stations[current].front(), cargo[0]));
          stations[current].pop();
          ++time;
        }
        else break;
      }

      run = (cargo[0] > 0);
      for(int i = 1; i <= n; ++i) run |= stations[i].size();

      ++current;
    }

    printf("%d\n", time);

  }

  return 0;
}
