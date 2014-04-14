#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

//typedef pair<int, int> job; // first -> time, second -> fine

struct job
{
  int time;
  int fine;
  int position;
};

bool compare(const job &l, const job &r)
{
  const int x = l.time * r.fine;
  const int y = r.time * l.fine;

  if(x > y)
    return false;
  else if(x < y)
    return true;
  else
    return l.position < r.position;
}

const size_t MAX_N = 16 * 1024;

job all[MAX_N];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t;

  if(scanf("%d\n", &t));

  DEBUG(printf("T = %d\n", t));

  for(int i = 0; i < t; ++i)
  {
    if(i > 0)
      printf("\n");
    int n;
    
    if(scanf("%d\n", &n));

    for(int j = 0; j < n; ++j)
    {
      if(scanf("%d %d\n", &all[j].time, &all[j].fine));
      all[j].position = j+1;
    }
    
    sort(all, all + n, compare);

    for(int j = 0; j < n; ++j)
      if(j > 0)
        printf(" %d", all[j].position);
      else
        printf("%d", all[j].position);
    printf("\n");
  }

  return 0;
}
