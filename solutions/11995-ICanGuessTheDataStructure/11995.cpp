#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>

#define foreach(X, Y) for(typeof(Y) X = 0; X < Y; ++X)

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
  unsigned n;

  while(scanf("%u", &n) != EOF)
  {
    DEBUG(printf("N = %u\n", n));
    stack<unsigned> s;
    queue<unsigned> q;
    priority_queue<unsigned> pq;

    bool is_stack = true;
    bool is_queue = true;
    bool is_priorityqueue = true;

    unsigned op, x;

    foreach(i, n)
    {
      if(scanf("%u %u", &op, &x));
      DEBUG(printf("OP %u x = %u\n", op, x));
      if(op == 1)
      {
        s.push(x);
        q.push(x);
        pq.push(x);
      }
      else
      {
        if(s.empty() || s.top() != x) 
          is_stack = false;
        else s.pop();

        if(q.empty() || q.front() != x) 
          is_queue = false;
        else q.pop();

        if(pq.empty() || pq.top() != x) 
          is_priorityqueue = false;
        else pq.pop();
      }
    }

    if(is_stack && !is_queue && !is_priorityqueue)
      printf("stack\n");
    else if(is_queue && !is_stack && !is_priorityqueue)
      printf("queue\n");
    else if(is_priorityqueue && !is_stack && !is_queue)
      printf("priority queue\n");
    else if(!is_stack && !is_queue && !is_priorityqueue)
      printf("impossible\n");
    else
      printf("not sure\n");
  }

  return 0;
}
