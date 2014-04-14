#include <cstdio>
#include <cmath>
#include <queue>

#define foreach(X, Y) for(typeof(Y) X = 0; X < Y; ++X)

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const unsigned B_MAX = 64;

struct Query
{
  unsigned id;
  unsigned period;
  unsigned next;

  bool operator>(const Query &other) const
  {
    if(next == other.next) return id > other.id;
    return next > other.next;
  }
};

using namespace std;

int main()
{
  priority_queue<Query, deque<Query>, greater<Query> > argus;

  char buffer[B_MAX];

  while(true)
  {
    char *b = fgets(buffer, B_MAX - 1, stdin);

    if(*b == '#') break;

    Query q;
    sscanf(buffer, "Register %u %u", &q.id, &q.period);
    q.next = q.period;
    argus.push(q);
  }

  unsigned n;

  if(scanf("%u", &n));

  foreach(i, n)
  {
    Query q = argus.top();
    argus.pop();
    printf("%u\n", q.id);
    q.next += q.period;
    argus.push(q);
  }

  return 0;
}
