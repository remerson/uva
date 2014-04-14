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

const size_t MAX_N = 100010;

int v[MAX_N]; // values
int m[MAX_N]; // index into v of the smallest element ending LIS of length i
int p[MAX_N]; // parent information for LIS sequence

// Debug util
void dump(int n)
{
  printf("  index m[%d] =", n);
  for(int i = 1; i <= n; ++i)
    printf(" %d", m[i]);
  printf("\n");

  printf("  value m[%d] =", n);
  for(int i = 1; i <= n; ++i)
    printf(" %d", v[m[i]]);
  printf("\n");

}

void dump_lis(int len)
{
  int j = m[len];

  int s[MAX_N];

  for(int i = 0; i < len; ++i)
  {
    s[i] = v[j];
    j = p[j];
  }

  reverse(s, s + len);

  for(int i = 0; i < len; ++i)
    printf("%d\n", s[i]);
}


struct ValueCompare
{
  inline bool operator()(const int &a, const int &b) const
  {
    return v[a] < v[b];
  }
};

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t, n = 0; // count of number of values read

  if(scanf("%d\n", &t));

  DEBUG(printf("t = %d\n", t));

  const size_t B_MAX = 16;

  char buffer[B_MAX + 1];

  for(int s = 0; s < t; ++s)
  {
    n = 0;

    while(true)
    {
      if(!fgets(buffer, B_MAX, stdin) || buffer[0] == '\n')
        break;

      DEBUG(printf("buffer = [%s]\n", buffer));

      v[n++] = atoi(buffer);
    }
    
    //    --n;

    DEBUG(printf("N = %d\n", n));
    
    m[1] = 0;
    p[1] = 0;
    
    int len = 1; // length of the longest list found so far
    
    ValueCompare comp;
    
    for(size_t i = 1; i < n; ++i)
    {
      DEBUG(printf("i = %d considering v[%d] = %d m[%d] = %d\n", i, i, v[i], i, v[m[len]]));
      
      // New longest LIS, extend
      if(v[i] >= v[m[len]])
      {
        p[i] = m[len]; // Store parent
        m[++len] = i;
        DEBUG(printf("EXTEND m[%d] = %d\n", len, v[m[len]]));
      }
      else
      {
        // m+1 because ignore the 0th element (this is the trival empty LIS)
        int *it = upper_bound(m + 1, m + len, i, comp);
        DEBUG(printf("CHANGE %d -> %d\n", *it, i));
        *it = i;
        p[i] = *(it - 1); // parent is previous element of the newly inserted
      }
      DEBUG(dump(len));
    }
    
    if(s > 0)
      printf("\n");

    printf("Max hits: %d\n", len);
    
    dump_lis(len);
  }

  return 0;
}
