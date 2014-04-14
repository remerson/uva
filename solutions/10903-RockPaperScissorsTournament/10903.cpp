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

const size_t N_MAX = 128;

const size_t W_MAX = 16;

unsigned short wins[N_MAX];
unsigned short losses[N_MAX];

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n, k;
  char word1[W_MAX];
  char word2[W_MAX];
  
  int a, b;
  bool first = true;

  while(scanf("%d", &n))
  {
    if(n == 0) break;

    if(scanf("%d", &k));

    for(int i = 1; i <= n; ++i)
    {
      wins[i] = 0;
      losses[i] = 0;
    }

    const int g = k * n * (n - 1) / 2;

    for(int i = 0; i < g; ++i)
    {
      if(scanf("%d %s %d %s", &a, word1, &b, word2));

      if(word1[0] == word2[0]) continue;

      // p r
      // r s
      // s p
      if(word1[0] == 'p')
      {
        if(word2[0] == 'r') ++wins[a], ++losses[b];
        else ++wins[b], ++losses[a];
      }

      if(word1[0] == 'r')
      {
        if(word2[0] == 's') ++wins[a], ++losses[b];
        else ++wins[b], ++losses[a];
      }

      if(word1[0] == 's')
      {
        if(word2[0] == 'p') ++wins[a], ++losses[b];
        else ++wins[b], ++losses[a];
      }
    }

    if(!first) printf("\n");
    first = false;

    for(int i = 1; i <= n; ++i)
    {
      DEBUG(printf("wins[%d] = %d losses[%d] = %d\n", i, wins[i], i, losses[i]));
      const int total = wins[i] + losses[i];
      if(total > 0)
        printf("%0.3f\n", static_cast<double>(wins[i]) / (static_cast<double>(total)));
      else
        printf("-\n");
    }
  }

  return 0;
}
