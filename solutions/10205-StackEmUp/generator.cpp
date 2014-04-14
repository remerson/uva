#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>


#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int MAX_N = 100;
const int MAX_C = 52;

int main(int argc, char **argv)
{
  srand(unsigned(time(0)));

  const int t = atoi(argv[1]);
  
  cout << t << endl << endl;

  for(int i = 0; i < t; ++i)
  {
    const int n = rand() % 100;

    cout << n << endl;

    for(int j = 0; j < n; ++j)
    {
      vector<int> v;

      for(int k = 1; k <= MAX_C; ++k) v.push_back(k);

      random_shuffle(v.begin(), v.end());

      for(int k = 0; k < MAX_C; ++k)
      {
        if(k > 0) cout << " ";
        cout << v[k];
      }
      cout << endl;
    }

    const int m = rand() % 100;

    for(int j = 0; j < m; ++j)
    {
      cout << (rand() % n) + 1 << endl;
    }
    cout << endl;
  }
  
    
  return 0;
}
