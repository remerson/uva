#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <algorithm>

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


const unsigned NM_MAX = 16 * 1024;

const unsigned E_MAX = 1024;

struct Entry
{
  Entry() : r(0), c(0), v(0) { }

  int r;
  int c;
  int v;
};

const unsigned B_MAX = 128;

char buffer[B_MAX];

struct Compare
{
  inline bool operator()(const Entry &lhs, const Entry &rhs) const
  {
    if(lhs.c == rhs.c)
      return lhs.r < rhs.r;
    return lhs.c < rhs.c;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n, m;

  while(scanf("%d %d\n", &n, &m) != EOF)
  {
    DEBUG(printf("N = %d M = %d\n", n, m));
    unsigned colsize[NM_MAX] = {0};
    Entry entries[E_MAX];

    int s = 0;

    for(int r = 1; r <= n; ++r)
    {
      char *b = fgets(buffer, B_MAX, stdin);
      DEBUG(printf("BUFFER [%s]\n", buffer));
      int k;
      b = read_int(k, b);
      DEBUG(printf("K = %d\n", k));

      for(int j = 0; j < k; ++j)
      {
        entries[s + j].r = r;
        b = read_int(entries[s + j].c, b);
        ++colsize[entries[s + j].c];
      }

      b = fgets(buffer, B_MAX, stdin);

      for(int j = 0; j < k; ++j)
      {
        b = read_int(entries[s + j].v, b);
      }

      for(int j = 0; j < k; ++j)
      {
        DEBUG(printf("ADDED ENTRY %d %d/%d => %d\n", s + j, entries[s + j].r, entries[s + j].c, entries[s + j].v));
      }

      s += k;
    }

    Compare comp;

    sort(entries, entries +s , comp);

    printf("%d %d\n", m, n);

    int g = 0;

    for(int c = 1; c <= m; ++c)
    {
      if(colsize[c] == 0) printf("0\n\n");
      else
      {
        printf("%d", colsize[c]);
        for(int i = 0; i < colsize[c]; ++i)
        {
          printf(" %d", entries[g + i].r);
        }
        printf("\n");
        for(int i = 0; i < colsize[c]; ++i)
        {
          printf("%s%d", i > 0 ? " ": "", entries[g + i].v);
        } 
        printf("\n");
        g += colsize[c];
      }
    }
  }

  return 0;
}
