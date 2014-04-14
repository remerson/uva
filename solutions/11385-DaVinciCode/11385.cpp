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

const int MAX_F = 46;
const int B_MAX = 512;

int fib[MAX_F];

void generate_fib()
{
  fib[0] = 1;
  fib[1] = 1;
  fib[2] = 2;

  for(int i = 3; i < MAX_F; ++i)
  {
    fib[i] = fib[i-1] + fib[i-2];
    DEBUG(printf("GENFIB %d -> %d\n", i, fib[i]));
  }
}

int find_fib(int f)
{
  for(int i = 1; i < MAX_F; ++i)
    if(fib[i] == f) 
      return i;
  //DEBUG(printf("ERROR!!! f = %d not found!!!\n", f));
  return 0;
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  generate_fib();

  int t;

  if(scanf("%d", &t));

  for(int s = 0; s < t; ++s)
  {
    int n;
    int positions[MAX_F] = {0};
    bitset<MAX_F> found;
    int max_p = 0;

    if(scanf("%d", &n));
    DEBUG(printf("N = %d\n", n));

    for(int i = 0; i < n; ++i)
    {
      int f;
      scanf("%d", &f);
      const int p = find_fib(f);
      positions[p] = i;
      max_p = max(p, max_p);
      found.set(p);
      DEBUG(printf("POS %d -> %d\n", p, positions[p]));
    }

    DEBUG(printf("max_p = %d\n", max_p));

    //sort(positions, positions + n);

    //    DEBUG(for(int i = 0; i < n; ++i) printf("SORTED POS %d -> %d\n", i, positions[i]);)
    
    char buffer[B_MAX];
    fgets(buffer, B_MAX, stdin);
    fgets(buffer, B_MAX, stdin);
    
    DEBUG(printf("BUFFER [%s]\n", buffer));

    const size_t l = strlen(buffer);

    char upper_only[B_MAX];
    int k = 0;

    for(size_t i = 0; i < l; ++i)
      if(isupper(buffer[i]))
        upper_only[k++] = buffer[i];
    upper_only[k++] = '\0';

    DEBUG(printf("UPPER_ONLY [%s]\n", upper_only));

    char output[B_MAX];
    int next = 0;

    for(int i = 1; i <= max_p; ++i)
    {
      if(found.test(i))
        output[next++] = upper_only[positions[i]];
      else
        output[next++] = ' ';
    }
    output[next++] = '\0';

    printf("%s\n", output);

  }

  return 0;
}
