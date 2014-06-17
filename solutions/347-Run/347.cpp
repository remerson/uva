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

bitset<10> mask; // masked (unused) digits

const size_t MAX_B = 32;
char buffer[MAX_B]; // actual buffer chars
unsigned len;

void dump()
{
  DEBUG(printf(" digit: "));
  for(unsigned i = 0; i < len; ++i)
    DEBUG(printf("%c", buffer[i]));
  DEBUG(printf("\n"));
}

bool is_run()
{
  bitset<10> visited;
  int i = 0;
  int match = 0;

  while(true)
  {
    int v = buffer[i] - '0';

    DEBUG(printf("CHECK DIGIT %d buffer[%d] = %c visited[%d] = %c len = %d\n", i, i, buffer[i], i, (visited[v] ? 'Y' : 'N'), len));

    if(visited[v])
      break;
   
    visited[v] = true;
    ++match;

    i += (buffer[i] - '0');
    i = i % len;
    
  }

  DEBUG(printf("LEN count = %lu len = %d i = %d\n", visited.count(), len, i));
  
  //const bool valid = (visited.count() == len) && i == 0;
  const bool valid = (match == len) && i == 0;

  // if(valid)
  // {
  //   DEBUG(printf("VALID\n"));
  // }
  
  return valid;
}

void next_run()
{
  int i = len;
  bool carry = false;

  DEBUG(printf("NEXT RUN\n"));
  DEBUG(dump());

  do
  {
    --i;
    carry = false;

    int v = buffer[i] - '0';
    ++v;

    if(v > 9)
    {
      carry = true;
      v = 1;
      if(i == 0)
      {
	DEBUG("PREINC\n");
	DEBUG(dump());
	++len;
	for(int j = 0; j < len; ++j)
	  buffer[j] = '1';
	DEBUG("POSTINC\n");
	DEBUG(dump());
	return;
      }
    }
    buffer[i] = v + '0';

  } while(carry);

  DEBUG(printf("GENERATED\n"));
  DEBUG(dump());

}

int main()
{
  int t = 0;

  while(scanf("%s\n", &buffer[0]))
  {
    if(buffer[0] == '0')
      break;

    len = strlen(buffer);
    DEBUG(printf("buffer = [%s] len = %d\n", buffer, len));

    mask.reset();

    int v = len;

    while(v < 10)
    {
      mask[v] = true;
      v += len;
      DEBUG(printf("MASKED %d\n", v));
    }

    DEBUG(dump());
    
    while(!is_run())
    {
      next_run();
    }

    buffer[len] = '\0';

    printf("Case %d: %s\n", ++t, buffer); 
  }

  return 0;
}
