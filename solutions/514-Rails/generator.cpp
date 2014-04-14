#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <vector>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const unsigned N_MAX = 100;
const unsigned M_MAX = 100;

int main(int argc, char **argv)
{
  srand(unsigned(time(0)));

  const int k = atoi(argv[1]);

  for(int i = 0; i < k; ++i)
  {
    const unsigned n = (rand() % N_MAX) + 1;
    const unsigned m = (rand() % M_MAX) + 1;

    cout << n << endl;

    std::vector<int> values;

    for(int j = 1; j <= n; ++j) values.push_back(j);

    for(int j = 1; j <= m; ++j)
    {
      for(int x = 1; x <= m; ++x)
        next_permutation(values.begin(), values.end());

      for(int x = 0; x < n; ++x)
        cout << values[x] << " ";

      cout << endl;
    }

    cout << "0" << endl;
  }

  cout << "0" << endl;
 
  return 0;
}
