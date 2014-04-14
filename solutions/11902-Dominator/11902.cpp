#include <cstdio>
#include <iostream>
#include <queue>
#include <bitset>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 128;
const int B_MAX = 512;

const int S_MAX = N_MAX * N_MAX;

int adjacency[N_MAX][N_MAX];
bool reachable[N_MAX];

int n;

void dump()
{
  printf("DUMP N = %d\n", n);

  for(int i = 0; i < n; ++i)
  {
    printf("%d:", i);

    if(adjacency[i][0] == 0) printf(" E");
    else
    for(int j = 1; j <= adjacency[i][0]; ++j)
    {
      printf(" %d", adjacency[i][j]);
    }
    printf("\n");
  }
}

void dump_reachable(int ignore)
{
  printf("REACHABLE IGNORE %d", ignore);
  for(int i = 0; i < n; ++i) printf(" %c", reachable[i] ? 'Y' : 'N');
  printf("\n");
}

// Perform (iterative) DFS and set reachable[] but ignore the given node.
void dfs(int ignore)
{
  DEBUG(printf("START DFS %d\n", ignore));

  for(int i = 0; i < n; ++i) reachable[i] = false;

  int pending[S_MAX]; // stack

  pending[0] = 1;
  pending[1] = 0;

  reachable[0] = true; // implicit

  while(pending[0] > 0)
  {
    int node = pending[pending[0]--];
    DEBUG(printf("NODE %d\n", node));
    for(int i = 1; i <= adjacency[node][0]; ++i)
    {
      int next = adjacency[node][i];
      DEBUG(printf("node = %d reachable[%d] = %c ignore = %d\n", node, next, reachable[next] ? 'Y' : 'N', ignore));
      if(!reachable[next] && next != ignore)
      {
        DEBUG(printf("REACHABLE %d\n", next));
        reachable[next] = true;
        pending[++pending[0]] = next;
      }
    }
  }
  DEBUG(dump_reachable(ignore));
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int t;
  char buffer[B_MAX];

  if(scanf("%d\n", &t) == 1);

  for(int q = 1; q <= t; ++q)
  {
    bool reachable_initial[N_MAX];
    char dominates[2 * N_MAX + 1][2 * N_MAX + 1];

    if(scanf("%d\n", &n) == 1);

    for(int i = 0; i < n; ++i) 
    {
      adjacency[i][0] = 0;
      reachable_initial[i] = false;
    }

    for(int i = 0; i < n; ++i)
    {
      fgets(&buffer[0], B_MAX, stdin);

      char *current = &buffer[0];

      int node = 0;

      while(*current != '\n')
      {
        switch(*current)
        {
        case ' ':
          ++node;
          break;
        case '1':
          adjacency[i][++adjacency[i][0]] = node;
          break;
        }
        ++current;
      }
    }

    DEBUG(dump());

    // Initialise
    for(int i = 0; i <= 2 * n; ++i)
      for(int j = 0; j <= 2 * n; ++j) 
        dominates[i][j] = '|';

    // Calculate initial reachability before testing removal of any nodes
    dfs(-1);

    // Save in reachable_initial
    // 0 is a special case
    for(int j = 0; j < n; ++j) 
    {
      reachable_initial[j] = reachable[j];
      dominates[0][2 * j + 1] = reachable_initial[j] ? 'Y' : 'N';
    }

    dominates[0][2 * n + 1] = '\n';

    // Compute DFS with given node removed and test reachability.
    for(int i = 1; i < n; ++i)
    {
      dfs(i);
      for(int j = 0; j < n; ++j)
        dominates[i][2 * j + 1] = (reachable_initial[j] && !reachable[j]) ? 'Y' : 'N';
      dominates[i][2 * n + 1] = '\n';
    }
    
    // Output
    char banner[B_MAX];
    int i = 0;
    banner[i++] = '+';
    while(i < (2 * n)) banner[i++] = '-';
    banner[i++] = '+';
    banner[i++] = '\n';

    printf("Case %d:\n", q);
    fflush(stdout);

    for(int k = 0; k < n; ++k)
    {
      write(1, banner, i);
      write(1, &dominates[k][0], 2 * n + 2);
    }
    write(1, banner, i);
  }

  return 0;
}
