#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <map>
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

typedef multimap<int, string> StringMap;

int main()
{
  int tests;

  cin >> tests;


  for(int t = 1; t <= tests; ++t)
  {
    StringMap values;

    for(int i = 0; i < 10; ++i)
    {
      string s;
      int r;
      
      cin >> s >> r;

      DEBUG(cout << "s = [" << s << "] r= " << r << endl);

      values.insert(StringMap::value_type(r, s));
    }

    cout << "Case #" << t << ":" << endl;

    StringMap::const_iterator it = values.end();
    --it;

    int k = it->first;

    DEBUG(cout << "k = " << k << endl);

    it = values.begin();

    while(it != values.end())
    {
      if(k == it->first) cout << it->second << endl;
      ++it;
    }
  }

  return 0;
}
