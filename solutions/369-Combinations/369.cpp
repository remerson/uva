#include <cstdio>

using namespace std;


#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif


int main()
{
  // ALso look at "369 Combinations"
  int n, k;

  while(scanf("%d %d", &n, &k) != EOF)
  {
    if(n == 0 && k == 0) break;

    long long r = 1;

    DEBUG(printf("n = %d k = %d\n", n, k));

    int j = k;

    if(k > n - k) 
      k = n - k; // nCk = nC(n-k)

    for(long long i = 1; i <= k; ++i)
    {
      r *= n - i + 1;
      r /= i;
      DEBUG(printf("i = %lld num = %lld den = %lld r = %lld\n", i, n - i + 1, i, r));
    }

    printf("%d things taken %d at a time is %lld exactly.\n", n, j, r);

  }

  return 0;
}
