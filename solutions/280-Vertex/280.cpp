#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const int MAX_N = 128;
const int B_MAX = 4096;

using namespace std;

int adjacency[MAX_N][MAX_N];
bool visited[MAX_N];
int pending[MAX_N];

int main()
{
  int n;
  int a, b;
  int x, y;

  int i, j, k; // Loop variables

  int v;

  char buffer[B_MAX];

  while(scanf("%d", &n) == 1)
  {
    DEBUG(printf("n = %d\n", n));
    if(n == 0) break;

    for(i = 1; i <= n; ++i) adjacency[i][0] = 0;
    
    do
    {
      if(scanf("%d", &a) == 1 && a == 0) break;

      while(scanf("%d", &b) == 1 && b != 0)
      {
        DEBUG(printf("%d -> %d\n", a, b));
        adjacency[a][++adjacency[a][0]] = b;
      }
    } while(true);

    if(scanf("%d", &x) == 1);

    DEBUG(printf("x = %d\n", x));

    for(i = 0; i < x; ++i)
    {
      if(scanf("%d", &y) == 1)
      {
        DEBUG(printf("START y = %d\n", y));

        v = n;

        for(j = 1; j <= n; ++j) visited[j] = false;
    
        pending[0] = 1;
        pending[1] = y;
        
        while(pending[0] != 0)
        {
          y = pending[pending[0]];
          pending[0]--;
          DEBUG(printf("NODE %d pending = %d\n", y, pending[0]));
          
          if(adjacency[y][0] > 0)
          {
            DEBUG(printf("RANGE %d nodes to queue\n", adjacency[y][0])); 
            for(k = 1; k <= adjacency[y][0]; ++k)
            {
              if(!visited[adjacency[y][k]])
              {
                DEBUG(printf("VISIT %d\n", adjacency[y][k]));
                visited[adjacency[y][k]] = true;
                --v;
                pending[++pending[0]] = adjacency[y][k];
                DEBUG(printf("QUEUE %d pending = %d\n", adjacency[y][k], pending[0]));
              }
            }
          }
        }
      
        printf("%d", v);

        for(k = 1; k <= n; ++k)
          if(!visited[k]) printf(" %d", k);
        printf("\n");
      }
    }
  }

  return 0;
}
