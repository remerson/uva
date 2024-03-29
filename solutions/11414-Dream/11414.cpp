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

const size_t N_MAX = 128 * 256;

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
  
  int n;
  int v;

  int t;
  if(scanf("%d\n", &t));

  for(int q = 0; q < t; ++q)
  {
    char *b = fgets(buffer, B_MAX, stdin);
    b = read_int(n, b);
    if(n == 0)
    { 
      printf("Yes\n");
      continue;
    }

    DEBUG(printf("N = %d\n", n));

    unsigned short counts[N_MAX] = {0};
    long long sum = 0;

    for(int i = 0; i < n; ++i)
    {
      b = read_int(v, b);
      DEBUG(printf("READ v = %d\n", v));
      if(v < 0)
      {
        sum = 1;
        break;
      }
      if(v > (n - 1))
      {
        sum = 1;
        break;
      }
      ++counts[n - 1 - v];
      DEBUG(printf("COUNTS[%d] = %d\n", n - 1 - v, counts[n - 1 - v]));
      sum += v;
    }

    DEBUG(for(int i = 0; i < n; ++i) printf("COUNTS %d = %u\n", n - 1 - i, counts[i]));

    bool possible = false;

    DEBUG(printf("SUM = %lld\n", sum));

    if(sum % 2 == 0)
    {
      unsigned degrees[N_MAX] = {0};
      size_t next = 1;
      
      for(int i = 0; i < n; ++i)
      {
        DEBUG(printf("CS UNWIND counts[%d] = %d\n", i, counts[i]));
        if(counts[i] == 0) continue;
        else
        {
          for(size_t j = 0; j < counts[i]; ++j)
          {
            DEBUG(printf("TARGET degrees[%d] = %d\n", next, n - 1 - i));
            degrees[next++] = n - 1 - i;
          }
        }
      }
      
      possible = true;

      unsigned left_sum = 0;

      for(unsigned k = 1; k < (unsigned) n && possible; ++k)
      {
        left_sum += degrees[k];

        unsigned right_sum = 0;

        for(int i = k+1; i <= n; ++i)
          right_sum += std::min(degrees[i], k);

        right_sum += (k * (k - 1));

        DEBUG(printf("LEFT_SUM = %u RIGHT SUM = %u\n", left_sum, right_sum));

        if(left_sum > right_sum)
          possible = false;
      }
    }

    if(possible)
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
