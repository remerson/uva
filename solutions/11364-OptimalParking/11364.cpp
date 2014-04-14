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


const unsigned N_MAX = 128;

const unsigned B_MAX = N_MAX * 8;

char buffer[B_MAX];

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n;

  if(scanf("%d\n", &n));

  DEBUG(printf("N = %d\n", n));

  for(int q = 0; q < n; ++q)
  {
    int m;

    if(scanf("%d\n", &m));

    DEBUG(printf("M = %d\n", m));

    char *b = fgets(buffer, B_MAX, stdin);

    DEBUG(printf("BUFFER [%s]\n", buffer));

    int low = N_MAX, high = 0, x = 0;

    for(int i = 0; i < m; ++i)
    {
      b = read_int(x, b);
      if(x < low) low = x;
      if(x > high) high = x;
    }

    printf("%d\n", (high - low) * 2);
  }

  return 0;
}
