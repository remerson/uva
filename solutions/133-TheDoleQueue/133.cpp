#include <cstdio>

#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

#ifndef ONLINE_JUDGE
#define LIVE(X) 
#else
#define LIVE(X) { X; }
#endif


using namespace std;

const size_t N_MAX = 32;

bitset<N_MAX> chosen;

void forward(size_t &x, const size_t n)
{
  DEBUG(printf("BEFORE forward %lu\n", x));
  if(x == n-1)
    x = 0;
  else
    ++x;

  if(chosen[x])
    forward(x, n);

  DEBUG(printf("AFTER forward %lu\n", x));
  
}

// Move x clockwise k steps 
void clockwise(size_t &x, size_t k, const size_t n)
{
  while(k)
  {
    forward(x, n);
    --k;
  }
}

void backward(size_t &x, const size_t n)
{
  if(x == 0)
    x = n - 1;
  else
    --x;

  if(chosen[x])
    backward(x, n);
}

// Move x anticlockwise k steps 
void anticlockwise(size_t &x, const size_t k, const size_t n)
{
  for(size_t i = 0; i < k; ++i)
  {
    // while(chosen[x])
    //   backward(x, n);

    backward(x, n);
  }
}


int main()
{
  int n, k, m;

  while(scanf("%d %d %d", &n, &k, &m) == 3)
  {
    DEBUG(printf("n = %d k = %d m = %d\n",n, k, m));

    if(n == 0 || k == 0 || m == 0)
      break;

    --k; --m;

    chosen.reset();

    size_t x = 0;
    size_t y = n-1;

    bool first = true;

    while(true)
    {
      clockwise(x, k, n);
      anticlockwise(y, m, n);
      DEBUG(printf("x = %lu y = %lu\n", x, y));
      //      printf("%d %d\n", x+1, y+1);
      if(!first)
        printf(",");
      printf("%3lu", x+1);
      if(y != x)
        printf("%3lu", y+1);
      first = false;
        
      chosen[x] = true;
      chosen[y] = true;
      if(chosen.count() == static_cast<size_t>(n))
      {
        printf("\n");
        break;
      }
      forward(x, n);
      backward(y, n);
      DEBUG(for(size_t i = 0; i < n; ++i) printf(" %lu", i));
      DEBUG(printf("\n"); for(size_t i = 0; i < n; ++i) printf(" %d", chosen[i] ? 1 : 0));
      DEBUG(printf("\n"));
      DEBUG(printf("count = %d\n", chosen.count()));
    }
  }

  return 0;
}
