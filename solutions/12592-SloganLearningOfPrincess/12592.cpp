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

const size_t S_MAX = 128;
const size_t N_MAX = 32;

char line1[N_MAX][S_MAX];
char line2[N_MAX][S_MAX];

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int n, q;

  if(scanf("%d\n", &n));

  DEBUG(printf("N = %d\n", n));

  for(int i = 0; i < n; ++i)
  {
    fgets(&line1[i][0], S_MAX, stdin);
    fgets(&line2[i][0], S_MAX, stdin);
    DEBUG(printf("%d line1[%s] line2[%s]\n", i, &line1[i][0], &line2[i][0]));
  }

  if(scanf("%d\n", &q));

  DEBUG(printf("Q = %d\n", q));

  char buffer[S_MAX];
  
  for(int i = 0; i < q; ++i)
  {
    fgets(buffer, S_MAX, stdin);
    DEBUG(printf("buffer [%s]\n", buffer));
    for(int j = 0; j < n; ++j)
      if(strncmp(buffer, &line1[j][0], S_MAX) == 0)
        printf("%s", &line2[j][0]);
  }

  return 0;
}
