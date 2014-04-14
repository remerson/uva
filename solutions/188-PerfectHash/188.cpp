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

int score(const char *word)
{
  int v = 0;
  DEBUG(printf("SCORE [%s] = ", word));
  while(*word)
  {
    v *= 32;
    v += *word - 'a' + 1;
    ++word;
  }
  DEBUG(printf("%d\n", v));
  return v;
}

int main()
{
  const int MAX_B = 256;
  const int MAX_WORDS = 16;

  char buffer[MAX_B];
  char original[MAX_B];

  while(fgets(&buffer[0], MAX_B - 1, stdin) != NULL)
  {
    strcpy(original, buffer);

    int w[MAX_WORDS];
    int index = 0;

    char *start = &buffer[0];

    DEBUG(printf("READ buffer [%s]\n", &buffer[0]));

    bool finished = false;
    int min_score = 0;

    while(!finished)
    {
      while(*start < 'a' || *start > 'z')
      {
	if(*start == '\n')
	{
	  finished = true;
	  break;
	}
	++start;
      }

      if(finished)
	break;

      char *end = start;

      while(*end >= 'a' && *end <= 'z')
	++end;

      //++end;
      if(*end == '\n')
	finished = true;

      *end = '\0';

      w[index] = score(start);
      
      if(index == 0)
	min_score = w[index];
      else
	min_score = min(w[index], min_score);

      DEBUG(printf("w[%d] = %d\n", index, w[index]));
      ++index;

      start = end + 1;
    }
    
    const int n = index;
    DEBUG(printf("N = %d\n", n));

    int c = 0;
    int next = min_score;

    while(next != c)
    {
      c = next;
      DEBUG(printf("TEST C = %u\n", c));

      unsigned divisors[MAX_WORDS];
      unsigned modulos[MAX_WORDS];

      for(int i = 0; i < n; ++i)
      {
	divisors[i] = c / w[i];
	modulos[i] = divisors[i] % n;
	DEBUG(printf("w[%d] = %d divisors[%d] = %d modulos[%d] = %d\n", i, w[i], i, divisors[i], i, modulos[i]));
      }

      for(int i = 0; i < n; ++i)
      {
	for(int j = i + 1; j < n; ++j)
	{
	  if(w[i] != w[j])
	  {
	    if(modulos[i] == modulos[j])
	    {
	      const int candidate = min((divisors[i] + 1) * w[i], (divisors[j] + 1) * w[j]);
	      next = max(next, candidate);
	      DEBUG(printf("MISMATCH at i = %d j = %d next C = %d candidate = %d\n", i, j, next, candidate));
	    }
	  }
	}
      }
    }

    printf("%s%u\n\n", &original[0], c);
      
  }
  
  return 0;
}
