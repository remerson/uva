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
#include <unordered_set>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;


int to_int(const char *s)
{
  int v = 0;

  const char *c = s;

  while(*c)
  {
    v = v * 10 + (*c - '0');
    ++c;
  }

  return v;
}

int to_string(int v, char *buffer)
{
  int p = 14;

  do
  {
    buffer[p--] = v % 10 + '0';
    v /= 10;
  } while(v);

  DEBUG(printf("to_string p = %d buffer = [%s]\n", p, &buffer[0]));
  
  return ++p;
}



int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  char buffer[16] = {0};

  while(fgets(&buffer[0], 15, stdin))
  {
    int len = strlen(&buffer[0]);
    buffer[--len] = '\0';
    DEBUG(printf("buffer = [%s]\n", &buffer[0]));
    if(buffer[0] == '0' && len == 1)
      break;

    printf("Original number was %s\n", &buffer[0]);

    unordered_set<int> chains{};
    
    do
    {
      DEBUG(printf("buffer = [%s]\n", &buffer[0]))
      char count[10] = {0};
      for(int i = 0; i < len; ++i)
      {
        int index = buffer[i] - '0';
        ++count[index];
        DEBUG(printf("buffer[%d] = %c count[%d] = %d\n", i, buffer[i], index, count[index]));
      }
      char desc[16] = {0};
      int j = 0;
      for(int i = 9; i >= 0; --i)
      {
        int k = count[i];
        while(k)
        {
          desc[j++] = i + '0';
          --k;
        }
      }
      
      int desci = to_int(desc);
      DEBUG(printf("desc %s %d\n", desc, desci));

      char asc[16] = {0};
      j = 0;
      for(int i = 0; i <= 9; ++i)
      {
        int k = count[i];
        while(k)
        {
          asc[j++] = i + '0';
          --k;
        }
      }
      
      int asci = to_int(asc);
      DEBUG(printf("asc %s %d\n", asc, asci));

      
      int delta = desci - asci;
      
      printf("%d - %d = %d\n", desci, asci, delta);

      if(chains.find(delta) != chains.end())
      {
        printf("Chain length %d\n\n", static_cast<int>(chains.size()) + 1);
        break;
      }
      else
      {
        chains.insert(delta);
      }

      char buffer2[16] = {0};
      int p = to_string(delta, &buffer2[0]);
      //sprintf(&buffer[0], "%d", delta);
      strcpy(&buffer[0], &buffer2[p]);
      
      len = strlen(&buffer[0]);
    } while(1);
  }
      
  return 0;
}
