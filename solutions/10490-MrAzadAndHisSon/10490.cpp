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
  //  std::ios_base::sync_with_stdio(false);
#endif
  
  int n;

  while(scanf("%d", &n))
  {
    if(n == 0)
      break;

    unsigned long long perfect = 0;
    bool prime = false;

    switch(n)
    {
    case 2:
      perfect = 6;
      break;
    case 3:
      perfect = 28;
      break;
    case 5:
      perfect = 496;
      break;
    case 7:
      perfect = 8128;
      break;
    case 11:
      prime = true;
      break;
    case 13:
      perfect = 33550336;
      break;
    case 17:
      perfect = 8589869056;
      break;
    case 19:
      perfect = 137438691328;
      break;
    case 23:
      prime = true;
      break;
    case 29:
      prime = true;
      break;
    case 31:
      perfect = 2305843008139952128;
      break;
    }

    if(perfect > 0)
      printf("Perfect: %llu!\n", perfect);
    else if(prime)
      printf("Given number is prime. But, NO perfect number is available.\n");
    else
      printf("Given number is NOT prime! NO perfect number is available.\n");

  }


  return 0;
}
