#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t P_MAX = 128;
const size_t T_MAX = 128;

const size_t B_MAX = 256;

typedef bitset<T_MAX> Trees;

bool compare(const Trees &lhs, const Trees &rhs)
{
  return lhs.to_string() < rhs.to_string();
}

int main()
{
  int s;

  if(scanf("%d\n", &s));

  DEBUG(printf("S = %d\n", s));

  for(int q = 0; q < s; ++q)
  {
    int p, t;

    if(scanf("%d %d\n", &p, &t));

    DEBUG(printf("P = %d T = %d\n", p, t));

    Trees all[P_MAX];

    char buffer[B_MAX];

    while(fgets(buffer, B_MAX, stdin))
    {
      if(buffer[0] == '\n') break;
      int a, b;
      if(sscanf(buffer, "%d %d", &a, &b));
      DEBUG(printf("PERSON %d TREE %d\n", a, b));
      all[a].set(b);
    }

    sort(all, all + p, compare);

    int opinions = 0;

    std::string match = all[1].to_string();

    for(int i = 2; i <= p; ++i)
    {
      DEBUG(printf("OPINION %d = %s\n", i, all[i].to_string().c_str()));
      if(all[i].to_string() != match)
      {
        opinions++;
        match = all[i].to_string();
      }
    }

    if(q > 0) printf("\n");
    printf("%d\n", opinions);
  }

  return 0;
}
