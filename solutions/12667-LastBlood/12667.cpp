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

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int N, T, M;

  const int MAX_P = 32;
  const int MAX_T = 128;

  if(scanf("%d %d %d\n", &N, &T, &M));

  // time, team
  pair<int, int> last[MAX_P];

  for(int i = 0; i < MAX_P; ++i)
    last[i] = pair<int, int>(-1, -1);
  
  bool solved[MAX_T][MAX_P] = {0};
  
  for(int l = 0; l < M; ++l)
  {
    char p;
    int s, t;
    char verdict[8] = {0};

    if(scanf("%d %d %c %s\n", &s, &t, &p, &verdict[0]));

    DEBUG(printf("READ %d %d %c %s\n", s, t, p, verdict));

    DEBUG(printf("SOLVED %c\n", (solved[t][p - 'A'] ? 'T' : 'F')));

    
    
    if(strcmp(verdict, "Yes") == 0 && !solved[t][p - 'A'])
    {
      solved[t][p - 'A'] = 1;

      DEBUG(printf("LAST %c %d %d\n", p, last[p - 'A'].first, last[p - 'A'].second));
      if(last[p - 'A'].first <= s)
      {
        last[p - 'A'].first = s;
        last[p - 'A'].second = t;
        DEBUG(printf("UPDATE %c %d %d\n", p, last[p - 'A'].first, last[p - 'A'].second));
      }
    }
  }

  for(int p = 0; p < N; ++p)
  {
    if(last[p].first == -1)
      printf("%c - -\n", 'A' + p);
    else
      printf("%c %d %d\n", 'A' + p, last[p].first, last[p].second);
  }
  
  

  return 0;
}
