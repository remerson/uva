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
#include <numeric>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

constexpr int S_MAX = 100010;

array<int, S_MAX> left_pos;
array<int, S_MAX> right_pos;

void dump(int s)
{
  cout << "L:";
  copy(begin(left_pos) + 1, begin(left_pos) + s + 1, ostream_iterator<int>(cout, " "));
  cout << "\n";
  cout << "R:";
  copy(begin(right_pos) + 1, begin(right_pos) + s + 1, ostream_iterator<int>(cout, " "));
  cout << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);

  while(true)
  {
    int b, s;

    cin >> s >> b;
    
    DEBUG(cout << "BEGIN S = " << s << " B = " << b << "\n");
    
    if(b == 0 && s == 0)
      break;
    
    iota(begin(left_pos) + 2, begin(left_pos) + s + 1, 1);
    iota(begin(right_pos) + 1, begin(right_pos) + s + 1, 2);

    left_pos[1] = 0;
    right_pos[s] = 0;

    DEBUG(dump(s));

    for(int i = 0; i < b; ++i)
    {
      int l, r;
      cin >> l >> r;
   
      DEBUG(printf("READ %d %d\n", l, r));

      int next_l = left_pos[l];
      int next_r = right_pos[r];

      DEBUG(printf("NEXT %d %d\n", next_l, next_r));

      right_pos[next_l] = next_r;
      left_pos[next_r] = next_l;

      if(next_r == 0 && next_l == 0)
	printf("* *\n");
      else if(next_r == 0)
	printf("%d *\n", next_l);
      else if(next_l == 0)
	printf("* %d\n", next_r);
      else
	printf("%d %d\n", next_l, next_r);

      DEBUG(dump(s));
    }

    printf("-\n");
  }

  return 0;
}
