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
  
  const size_t N_MAX = 255;

  int values[N_MAX] = {0};

  values[' '] = 1;
  values['a'] = 1;
  values['b'] = 2;
  values['c'] = 3;
  values['d'] = 1;
  values['e'] = 2;
  values['f'] = 3;
  values['g'] = 1;
  values['h'] = 2;
  values['i'] = 3;
  values['j'] = 1;
  values['k'] = 2;
  values['l'] = 3;
  values['m'] = 1;
  values['n'] = 2;
  values['o'] = 3;
  values['p'] = 1;
  values['q'] = 2;
  values['r'] = 3;
  values['s'] = 4;
  values['t'] = 1;
  values['u'] = 2;
  values['v'] = 3;
  values['w'] = 1;
  values['x'] = 2;
  values['y'] = 3;
  values['z'] = 4;
  
  char buffer[255];

  int t;

  //if(scanf("%d\n", &t));
  cin >> t;

  DEBUG(printf("T = %d\n", t));

  string buf;
  getline(cin, buf);

  for(int i = 1; i <= t; ++i)
  {
    //if(fgets(&buffer[0], 254, stdin));
    string buffer;

    //while(buffer.size() == 0)
      getline(cin, buffer);

    

    //char *b = &buffer[0];

    int v = 0;

    //DEBUG(printf("i = %d buffer [%s]\n", i, &buffer[0]));
    DEBUG(printf("buffer = [%s]\n", buffer.c_str()));

    for(int j = 0; j < buffer.size(); ++j)
    {
      v += values[buffer[j]];
      
    }

    printf("Case #%d: %d\n", i, v);
  }
    
  
  

  return 0;
}
