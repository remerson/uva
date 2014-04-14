#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 10000;
const int M_MAX = 10000;

const int L_MAX = 11;

const int B_MAX = 11 * N_MAX;

int first[N_MAX];
int second[M_MAX];

int main()
{
  int t, n, m;
  char buffer[B_MAX];

  if(scanf("%d\n", &t));

  DEBUG(printf("t = %d\n", t));

  for(int j = 0; j < t; ++j)
  {
    if(scanf("%d %d\n", &n, &m));

    DEBUG(printf("n = %d m = %d\n", n, m));

    int i = 0;

    if(fgets(&buffer[0], B_MAX, stdin));

    DEBUG(printf("BUFFER: %s\n", &buffer[0]));

    {
      char *p1 = &buffer[0];
      char *p2 = &buffer[0];
      
      while(true)
      {
        if(*p2 == '\n')
        {
          *p2 = '\0';
          first[i] = atoi(p1);
          DEBUG(printf("END %d p1 = [%c] p2 = [%c]\n", first[i], *p1, *p2));
          break;
        }
        else if(*p2 == ' ')
        {
          *p2 = '\0';
          first[i] = atoi(p1);
          DEBUG(printf("ADD %d 1 = [%c] p2 = [%c]\n", first[i], *p1, *p2));
          ++i;
          ++p2;
          p1 = p2;
        }
        else ++p2;
      }
    }

    sort(first, first + n);

    DEBUG(printf("FIRST:"));
    //for(int y = 0; y < n; ++y) DEBUG(printf(" %d", first[y]));
    DEBUG(printf("\n"));

    i = 0;

    if(fgets(&buffer[0], B_MAX, stdin));

    {
      char *p1 = &buffer[0];
      char *p2 = &buffer[0];
      
      while(true)
      {
        if(*p2 == '\n')
        {
          *p2 = '\0';
          second[i] = atoi(p1);
          DEBUG(printf("END %d p1 = [%c] p2 = [%c]\n", second[i], *p1, *p2));
          break;
        }
        else if(*p2 == ' ')
        {
          *p2 = '\0';
          second[i] = atoi(p1);
          DEBUG(printf("ADD %d 1 = [%c] p2 = [%c]\n", second[i], *p1, *p2));
          ++i;
          ++p2;
          p1 = p2;
        }
        else ++p2;
      }
    }

    // for(int i = 0; i < m; ++i) { if(scanf("%d", &second[i])); }
    sort(second, second + m);

    DEBUG(printf("SECOND:"));
    //for(int y = 0; y < m; ++y) DEBUG(printf(" %d", second[y]));
    DEBUG(printf("\n"));

    int *p1 = &first[0];
    int *p2 = &second[0];

    int ic = 0;

    const int *fn = first + n;
    const int *sm = second + m;

    while(p1 != fn && p2 != sm)
    {
      if(*p1 < *p2) ++p1;
      else if(*p2 < *p1) ++p2;
      else { ++ic; ++p1; ++p2; }
    }

    DEBUG(printf("ic = %d\n", ic));

    printf("%d\n", (n - ic) + (m - ic));;
  }

  return 0;
}
