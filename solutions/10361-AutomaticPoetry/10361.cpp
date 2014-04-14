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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  const int B_MAX = 128;
  
  int t;

  if(scanf("%d\n", &t));

  for(int s = 0; s < t; ++s)
  {
    char first[B_MAX];
    char second[B_MAX];
    if(fgets(&first[0], B_MAX, stdin));
    if(fgets(&second[0], B_MAX, stdin));

    DEBUG(printf("first = [%s] second = [%s]\n", first, second));

    char *s1 = &first[0];
    char *s2 = &first[0];
    char *s3 = &first[0];
    char *s4 = &first[0];
    char *s5 = &first[0];

    while(*s2 != '<')
      ++s2;

    *s2 = '\0';
    ++s2;

    DEBUG(printf("s1 = [%s]\n", s1));
    
    s3 = s2;

    while(*s3 != '>')
      ++s3;

    *s3 = '\0';
    ++s3;

    DEBUG(printf("s2 = [%s]\n", s2));

    s4 = s3;

    while(*s4 != '<')
      ++s4;

    *s4 = '\0';
    ++s4;

    DEBUG(printf("s3 = [%s]\n", s3));

    s5 = s4;

    while(*s5 != '>')
      ++s5;
    
    *s5 = '\0';
    ++s5;

    DEBUG(printf("s4 = [%s]\n", s4));

    char *s6 = s5;

    while(*s6 != '\n')
      ++s6;
    *s6 = '\0';

    DEBUG(printf("s5 = [%s]\n", s5));

    char *u = &second[0];

    while(*u)
    {
      if(*u == '.' && *(u+1) == '.' && *(u+2) == '.' && *(u+3) == '\n')
      {
        *u = '\0';
        printf("%s%s%s%s%s\n", s1, s2, s3, s4, s5);
        printf("%s%s%s%s%s\n", &second[0], s4, s3, s2, s5);
        break;
      }
      ++u;
    }

  }
  

  return 0;
}
