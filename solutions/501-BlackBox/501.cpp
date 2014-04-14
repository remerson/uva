#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif


using namespace std;

const int MN_MAX = 30001;

int main()
{
  typedef deque<int> BlackBox;

  int mvals[MN_MAX];
  int nvals[MN_MAX];

  int m, n;
  int vt;

  cin >> vt;

  for(int t = 0; t < vt; ++t)
  {
    if (t > 0) cout << endl;

    cin >> m >> n;

    DEBUG(printf("m = %d n = %d\n", m, n));

    for(int i = 0; i < m; ++i) cin >> mvals[i];
    for(int i = 0; i < n; ++i) cin >> nvals[i];

    BlackBox box;
    BlackBox::const_iterator c = box.end();
    
    int x = 0;
    int y = 0;

    while(x < n)
    {
      if(nvals[x] == static_cast<int>(box.size()))
      {
        cout << box[x] << endl;
        ++x;
      }
      else
      {
        BlackBox::iterator it = lower_bound(box.begin(), box.end(), mvals[y]);

        box.insert(it, mvals[y]);
        ++y;
      }
    }
  }


  return 0;
}
