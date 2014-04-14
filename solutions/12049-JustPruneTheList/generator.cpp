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

int main(int argc, char **argv)
{
  const int t = atoi(argv[1]);
  const int n = atoi(argv[2]);
  const int m = atoi(argv[3]);

  cout << t << endl;

  for(int i = 0; i < t; ++i)
  {
    cout << n << " " << m << endl;

    const int k = (n + m);

    for(int j = 0; j < n; ++j) 
    {
      if(j > 0) cout << " ";
      cout << 20000000 + (rand() % (1 + m));
    }
    cout << endl;

    for(int j = 0; j < m; ++j) 
    {
      if(j > 0) cout << " ";
      cout << (20000900 - m) + (rand() % (1 + n));
    }
    cout << endl;
  }

  return 0;
}
