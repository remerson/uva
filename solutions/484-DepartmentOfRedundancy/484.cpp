#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <deque>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  typedef map<int, int> CountMap;
  typedef deque<int> ValueDeque;
 
  CountMap counts;
  ValueDeque values;
  int v;

  CountMap::iterator it                 ;

  while(cin.good())
  {
    cin >> v;

    if(!cin.good()) break;

    it = counts.find(v);

    if(it == counts.end())
    {
      it = counts.insert(CountMap::value_type(v, 0)).first;
      values.push_back(v);
    }

    it->second++;
  }

  {
    ValueDeque::const_iterator it = values.begin();

    while(it != values.end())
    {
      cout << *it << " " << counts.find(*it)->second << endl;
      ++it;
    }
  }

  return 0;
}
