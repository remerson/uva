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

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 32;

void scrub(char *s)
{
  char *u = s;

  while(*u)
  {
    *u = ::tolower(*u);
    ++u;
  }
  
  DEBUG(printf("scrubbed = [%s]\n", s));
}

int score(char *s)
{
  char *u = s;

  int v = 0;

  while(*u)
  {
    if(::islower(*u))
      v += *u - 'a' + 1;
    ++u;
  }

  DEBUG(printf("buffer = [%s] score = %d\n", s, v));

  return v;
}

int score(int s)
{
  if(s % 9 == 0)
    return 9;
  else
    return s % 9;

  //DEBUG(printf("score %d\n", s));
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  char first[B_MAX];
  char second[B_MAX];

  while(fgets(&first[0], B_MAX-1, stdin) == &first[0])
  {
    DEBUG(printf("first = [%s]\n", first));
    scrub(first);
    if(strlen(first) == 0)
      continue;

    fgets(&second[0], B_MAX - 1, stdin);
    //if(scanf("%[\n]", &second[0]));

    DEBUG(printf("second = [%s]\n", second));

    scrub(second);

    const int s1 = score(score(first));
    const int s2 = score(score(second));


    double ratio = (double) s1  / (double) s2;

    if(s1 > s2)
    {
      ratio = (double) s2 / (double) s1;
    }

    printf("%.2f %%\n", 100.0 * ratio);
  }

  return 0;
}
