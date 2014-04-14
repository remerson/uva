#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cmath>


#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  int k;

  deque<int> values;

  while(true)
  {
    cin >> k;

    if(!cin.good()) break;

    deque<int>::iterator it = lower_bound(values.begin(), values.end(), k);

    values.insert(it, k);

    DEBUG(cout << "DEBUG: ");
    DEBUG(copy(values.begin(), values.end(), ostream_iterator<int>(cout, " ")));
    DEBUG(cout << endl);
    
    const int s = values.size();

    if(s % 2 == 0)
      cout << (values[s / 2] + values[(s / 2) - 1]) / 2 << endl;
    else
      cout << values[s / 2] << endl;
  }

  return 0;
}
