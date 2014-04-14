#include <iostream>
#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_N = 128 * 1024;
const size_t MAX_K = 128 * 1024;
const size_t B_MAX = 5 * MAX_N;

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

#define LSOne(S) (S & (-S))

class fenwick
{
public:

  explicit fenwick(const size_t n)
    : n_(n)
  {
    for(size_t i = 1; i <= n; ++i)
      tree_[i] = 0;
  }

  inline int rsq(int b)
  {
    int sum = 0;
    for(; b; b -= LSOne(b))
      sum += tree_[b];
    return sum;
  }

  inline int rsq(int a, int b)
  {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
  }

  inline void adjust(int k, int v)
  {
    for(; k <= n_; k += LSOne(k))
       tree_[k] += v;
  }

  // inline int rsq(int a, int b)
//   {
//     if(a == 0)
//     {
//       int sum = 0;
//       for(; b >= 0; b = (b & (b + 1)) - 1)
//         sum += tree_[b];
//       return sum;
//     }
//     else
//     {
//       return rsq(0, b) - rsq(0, a - 1);
//     }
//   }

//   inline void adjust(int k, int v)
//   {
//     for(; k <= n_; k |= k + 1)
//       tree_[k] += v;
//   }

  inline void increment(int a)
  {
    adjust(a, 1);
  }

  inline void decrement(int a)
  {
    adjust(a, -1);
  }

private:

  int tree_[MAX_N];
  int n_;
};

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n, k;

  while(scanf("%d %d\n", &n, &k) == 2)
  {
    DEBUG(printf("============ N = %d K = %d\n", n, k));

    fenwick zeroes(n);
    fenwick negatives(n);

    int values[MAX_K];
    char output[MAX_K];

    char buffer[B_MAX];

    char *b = fgets(buffer, B_MAX - 1, stdin);

    for(size_t i = 1; i <= size_t(n); ++i)
    {
      //scanf("%d", &values[i]);
      b = read_int(values[i], b);
      DEBUG(printf("READ V = %d\n", values[i]));
      if(values[i] == 0)
        zeroes.increment(i);
      else if(values[i] < 0)
        negatives.increment(i);

      DEBUG(printf("  0 SUM(1, %d) = %d\n", i, zeroes.rsq(1, i)));
      DEBUG(printf("-ve SUM(1, %d) = %d\n", i, negatives.rsq(1, i)));
    }

    int r = 0;

    DEBUG(printf("----------\n"));

    for(size_t j = 0; j < size_t(k); ++j)
    {
      int a, b;
      char c;

      scanf("\n");

      scanf("%c %d %d", &c, &a, &b);

      DEBUG(printf("READ %c a = %d b = %d\n", c, a, b));

      if(c == 'C')
      {
//         // Unadjust old value
//         if(values[a] == 0)
//           zeroes.decrement(a);
//         else if(values[a] < 0)
//           negatives.decrement(a);

//         // Adjust new value
//         if(b == 0)
//           zeroes.increment(a);
//         else if(b < 0)
//           negatives.increment(a);

        if(b >= 0 && values[a] < 0) 
          negatives.decrement(a);

        if(b < 0 && values[a] >= 0)
          negatives.increment(a);

        if(b == 0 && values[a] != 0)
          zeroes.increment(a);

        if(b != 0 && values[a] == 0)
          zeroes.decrement(a);

        values[a] = b;
      }
      else if(c == 'P')
      {
        DEBUG(printf("  0 SUM(%d, %d) = %d\n", a, b, zeroes.rsq(a, b)));
        DEBUG(printf("-ve SUM(%d, %d) = %d\n", a, b, negatives.rsq(a, b)));

        if(zeroes.rsq(a, b))
          output[r] = '0';
        else if(negatives.rsq(a, b) & 1)
          output[r] = '-';
        else
          output[r] = '+';

        DEBUG(printf("RESULT %c\n", output[r]));
        ++r;
      }
    }

    output[r] = '\0';
    printf("%s\n", output);
  }

  return 0;
}
