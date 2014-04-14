#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  int m, n;
  string a;
  int c;
  typedef map<string, int> CostMap;
  CostMap costs;

  cin >> m >> n;

  for(int i = 0; i < m; ++i)
  {
    cin >> a;
    cin >> c;

    costs.insert(CostMap::value_type(a, c));
  }

  c = 0;

  for(int i = 0; i < n; ++i)
  {
    cin >> a;

    while(a != ".")
    {
      istringstream iss(a);

      do
      {
        string x;
        iss >> x;
        CostMap::const_iterator it = costs.find(x);
        if(it != costs.end())
        {
          c += it->second;
        }
      } while(iss);

      cin >> a;
    }

    printf("%d\n", c);
    c = 0;
  }

  return 0;
}
