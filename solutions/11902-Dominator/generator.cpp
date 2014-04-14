#include <cstdio>
#include <iostream>
#include <queue>
#include <bitset>
#include <cstdlib>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 100;

int main(int argc, char **argv)
{
  srand(unsigned(time(0)));

  const int t = atoi(argv[1]);

  cout << t << endl;
    
  for(int i = 0; i < t; ++i)
  {
    const int s = rand() % 12;

    cout << s << endl;

    for(int k = 0; k < s; ++k)
    {
      for(int j = 0; j < s; ++j)
      {
        if(j > 0) cout << " ";
        cout << (rand() % 10 == 0) ? "1" : "0"; // sparse
      }
      cout << endl;
    }
  }

  return 0;
}
