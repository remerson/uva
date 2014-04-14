#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const unsigned MAX_K = 128;

int main()
{
  unsigned n;

  if(scanf("%u\n", &n));

  DEBUG(printf("N = %u\n", n));

  for(unsigned t = 0; t < n; ++t)
  {
    unsigned k, w;
    

    if(scanf("%u %u\n", &k, &w));

    DEBUG(printf("K = %u W = %u\n", k, w));

    char word1[MAX_K];
    char word2[MAX_K];

    fgets(word1, MAX_K - 1, stdin);
    unsigned min_len = k;

    while(w > 1)
    {
      fgets(word2, MAX_K - 1, stdin);
      
      DEBUG(printf("word1 = [%s] word2 = [%s]\n", word1, word2));

      unsigned match_len = k;

      for(; match_len > 0; --match_len)
      {
        DEBUG(printf("try len = %u\n", match_len));
        bool matched = true;
        char *w1 = &word1[k - match_len];
        char *w2 = &word2[0];
        for(unsigned i = 0; i < match_len; ++i)
        {
          DEBUG(printf("w1 = %c w2 = %c\n", *w1, *w2));
          if(*w1 != *w2)
          {
            matched = false;
            break;
          }
          ++w1;
          ++w2;
        }
        if(matched)
          break;

      }

      DEBUG(printf("match_len = %u\n", match_len));

      min_len += k - match_len;

      DEBUG(printf("min_len = %u\n", min_len));

      strncpy(word1, word2, k);
      --w;
    }

    printf("%u\n", min_len);
  }

  return 0;
}
