#include <cstdio>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t N_MAX = 100;

int squares[N_MAX] = {0};

int feynman(int n)
{
  if(n == 1) return 1;

  if(squares[n] == 0) squares[n] = n * n + feynman(n - 1);

  return squares[n];
}

int main()
{
  int n;

  while(scanf("%d", &n) == 1)
  {
    if(n == 0) break;

    int f = 0;

    //printf("%d\n", feynman(n));
    for(int i = n; i >= 1; --i)
    {
      if(squares[i] == 0) squares[i] = i * i;
      f += squares[i];
      //f += i * i;
    }

    printf("%d\n", f);
  }

  return 0;
}
