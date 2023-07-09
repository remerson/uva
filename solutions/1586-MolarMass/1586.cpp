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

//using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  double weights[255] = {0.0};

  weights['C'] = 12.01;
  weights['H'] = 1.008;
  weights['O'] = 16.0;
  weights['N'] = 14.01;
  
  int T;

  if(scanf("%d\n", &T));

  for(int t = 0; t < T; ++t)
  {
    char buffer[128] = {0};

    if(scanf("%s\n", &buffer[0]));

    double total = 0.0;
    char element = 'X';
    int quantity = 0;
    bool have_qty {false};
    
    const int l = strlen(&buffer[0]);
    
    for(int i = 0; i < l; ++i)
    {
      if(isdigit(buffer[i]))
      {
        have_qty = true;
        if(quantity > 0)
          quantity *= 10;
        quantity += buffer[i] - '0';
      }
      else
      {
        if(!have_qty)
          quantity = 1;
        DEBUG(printf("ADD quantity = %d element = %c\n", quantity, element));
        total += quantity * weights[(int) element];
        DEBUG(printf("TOTAL = %f\n", total));
        quantity = 0;
        have_qty = false;
        element = buffer[i];
      }
    }

    if(!have_qty)
      quantity = 1;
    DEBUG(printf("ADD LAST quantity = %d element = %c\n", quantity, element));
    total += quantity * weights[(int) element];

    printf("%.3f\n", total);
  }
  
  return 0;
}
