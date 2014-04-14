#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#include <list>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

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


const unsigned N_MAX = 1024 * 1024;

const unsigned B_MAX = 1024 * 8;

char buffer[B_MAX];
short team[N_MAX];
int idx[N_MAX];

int main()
{
  std::ios_base::sync_with_stdio(false);

  int t, d = 0;

  while(scanf("%d\n", &t))
  {
    DEBUG(printf("T = %d\n", t));
    if(t == 0) break;

    memset(team, 0, sizeof(short) * N_MAX);
    

    for(int i = 0; i < t; ++i)
    {
      char *b = fgets(buffer, B_MAX, stdin);
      DEBUG(printf("buffer [%s]\n", buffer));
      int n, x;
      
      b = read_int(n, b);
      DEBUG(printf("READ N = %d\n", n));
      
      for(int j = 1; j <= n; ++j)
      {
        b = read_int(x, b);
        team[x] = i;
        DEBUG(printf("SET team[%d] = %d\n", x, team[x]));
      }
    }

    typedef deque<int> TeamQueue;

    TeamQueue q;
    memset(idx, -1, sizeof(int) * t);

    printf("Scenario #%d\n", ++d);
    while(true)
    {
      DEBUG(printf("==========================\n"));
      DEBUG(printf("QUEUE:"); for(int p = 0; p < q.size(); ++p) printf(" %d", q[p]); printf("\n"));
      DEBUG(printf("IDX:"); for(int p = 0; p < t; ++p) printf(" %d", idx[p]); printf("\n"));

      char *b = fgets(buffer, B_MAX, stdin);

      if(*b == 'S') break;
      else if(*b == 'E')
      {
        int x;
        b = read_int(x, b);
        
        DEBUG(printf("ENQUEUE %d\n", x));

        if(idx[team[x]] == -1)
        {
          q.push_back(x);
          idx[team[x]] = q.size() - 1;
        }
        else
        {
          ++idx[team[x]];
          q.insert(q.begin() + idx[team[x]], x);
          for(int i = 0; i < t; ++i)
          {
            if(i != team[x] && idx[i] >= idx[team[x]])
            {
              ++idx[i];
            }
          }
        }
      }
      else if(*b == 'D')
      {
        DEBUG(printf("DEQUEUE %d\n", q.size()));
        printf("%d\n", q.front());
        q.pop_front();
        for(int i = 0; i < t; ++i)
        {
          --idx[i];
          if(idx[i] < 0) idx[i] = -1;
        }
      }

    }
    printf("\n");
  }

  return 0;
}
