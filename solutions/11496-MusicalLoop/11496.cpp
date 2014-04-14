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


const unsigned N_MAX = 16 * 1024;

int values[N_MAX];

const unsigned B_MAX = N_MAX * 8;

char buffer[B_MAX];

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n;

  while(scanf("%d\n", &n) != EOF)
  {
    if(n == 0) break;

    DEBUG(printf("N = %d\n", n));

    char *b = fgets(buffer, B_MAX, stdin);

    DEBUG(printf("BUFFER [%s]\n", buffer));

    for(int i = 0; i < n; ++i)
      b = read_int(values[i], b);

    unsigned peaks = 0;

    for(int i = 0; i < n; ++i)
    {
      if(values[(i+1)%n] > values[i%n] && values[(i+1)%n] > values[(i+2)%n])
        ++peaks;
      else if(values[(i+1)%n] < values[i%n] && values[(i+1)%n] < values[(i+2)%n])
        ++peaks;
      DEBUG(printf("values[%d] = %d values[%d] = %d values[%d] = %d peaks = %u\n", i%n, values[i%n], (i+1)%n, values[(i+1)%n], (i+2)%n, values[(i+2)%n], peaks));
    }      
    
    printf("%u\n", peaks);

  }

  return 0;
}
