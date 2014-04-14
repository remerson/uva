#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

struct Compare
{
  Compare(int m) : m_(m) { }

  inline bool operator()(const int &lhs, const int &rhs) const
  {
    const int m_lhs = lhs % m_;
    const int m_rhs = rhs % m_;

    DEBUG(printf("lhs = %d rhs = %d m_lhs = %d m_rhs = %d\n", lhs, rhs, m_lhs, m_rhs));

    if(m_lhs == m_rhs)
    {
      const bool lhs_odd = lhs % 2;
      const bool lhs_even = !lhs_odd;
      const bool rhs_odd = rhs % 2;
      const bool rhs_even = !rhs_odd;

      if((lhs_odd && rhs_even) || (lhs_even && rhs_odd))
      {
        return lhs_odd;
      }

      if(lhs_odd && rhs_odd)
      {
        return lhs > rhs;
      }

      if(lhs_even && rhs_even)
      {
        return lhs < rhs;
      }
    }
    return m_lhs < m_rhs;
  }

  int m_;
};

const unsigned N_MAX = 16 * 1024;

int values[N_MAX];

int main()
{
  std::ios_base::sync_with_stdio(false);

  int n, m;

  while(scanf("%d %d", &n, &m))
  {
    if(n == 0 && m == 0) break;

    for(int i = 0; i < n; ++i)
      if(scanf("%d\n", &values[i])); 
    
    Compare comp(m);

    sort(values, values + n, comp);

    printf("%d %d\n", n, m);

    for(int i = 0; i < n; ++i)
      printf("%d\n", values[i]);
  }

  printf("0 0\n");

  return 0;
}
