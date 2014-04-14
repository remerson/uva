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

  int t, total = 0;

  cin >> t;

  for(int k = 0; k < t; ++k)
  {
    double length, width, depth, weight;

    cin >> length >> width >> depth >> weight;

    const double dimension = length + width + depth;

    if(((length <= 56.0 && width <= 45.0 && depth <= 25.0) || dimension <= 125.0) && weight <= 7.0)
    {
      cout << 1 << endl;
      ++total;
    }
    else
      cout << 0 << endl;
  }
  cout << total << endl;
  return 0;
}
