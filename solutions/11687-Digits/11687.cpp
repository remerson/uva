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
  char buffer[2 * 1024 * 1024];

  while(scanf("%s\n", &buffer[0]))
  {
    if(!isdigit(buffer[0]))
      break;
    
    int previous = strlen(&buffer[0]);
    int current = previous;
    int reps = 1;

    if(! (previous == 1 && buffer[0] == '1'))
    {
      do
      {
        previous = current;
        char digits[128];
        sprintf(digits, "%d", previous);
        current = strlen(&digits[0]);
        ++reps;
      } while(current != previous);
    }
    printf("%d\n", reps);
  }

  return 0;
}

