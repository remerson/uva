#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 1024;
const int W_MAX = 32;

int values[N_MAX];
int depths[N_MAX];

bool path[W_MAX][N_MAX];
int cached[W_MAX][N_MAX];

int w;

int cost(int item)
{
  return 3 * w * depths[item];
}

int dive(int item, int limit)
{
  if(item == 0 || limit == 0) return 0;

  if(cached[item][limit] == -1)
  {
    DEBUG(printf("MISS i = %d l = %d k = %d\n", item, limit, key));

    int result = 0;
    
    if (cost(item) > limit)
    { 
      result = dive(item - 1, limit);
      path[item][limit] = false;
      //DEBUG(printf("item = %d IGNORED cost = %d > limit = %d path[%d][%d] = %s\n", item, cost, limit, item, result, path[item][result] ? "T" : "F"));
    }
    else
    {
      const int a = dive(item - 1, limit);
      const int b = dive(item - 1, limit - cost(item)) + values[item];
      
      if(b > a)
      {
        result = b;
        path[item][limit] = true;
        //DEBUG(printf("item = %d CHOSEN b = %d a = %d cost = %d path[%d][%d] = %s\n", item, b, a, cost, item, result, path[item][result] ? "T" : "F"));
      }
      else
      {
        result = a;
        path[item][limit] = false;
        //DEBUG(printf("item = %d IGNORED a = %d b = %d cost = %d path[%d][%d] = %s\n", item, a, b, cost, item, result, path[item][result] ? "T" : "F"));
      }
    }
    cached[item][limit] = result;
  }
  else
  {
    DEBUG(printf("HIT i = %d l = %d k = %d\n", item, limit, key)); 
  }
  return cached[item][limit];
}

int main()
{
  int tank;
  int items;
  bool first = true;

  while(scanf("%d %d %d", &tank, &w, &items) != EOF)
  {
    if(!first) printf("\n");
    first = false;

    memset(values, -1, N_MAX * sizeof(int));
    memset(depths, -1, N_MAX * sizeof(int));
    memset(cached, -1, N_MAX * W_MAX * sizeof(int));
    
    DEBUG(printf("tank = %d w = %d items = %d\n", tank, w, items));
    
    for(int i = 1; i <= items; ++i) 
      if(scanf("%d %d", &depths[i], &values[i]));
    
    const int total = dive(items, tank);
    
    int num = 0;
    int k = tank;
    
    bool chosen[W_MAX] = {0};
    
    for(int i = items; i >= 1; --i)
    {
      if(path[i][k])
      {
            ++num;
            chosen[i] = true;
            k -= cost(i);
      }
    }

    printf("%d\n%d\n", total, num);
    
    for(int i = 1; i <= items; ++i)
    {
      if(chosen[i]) printf("%d %d\n", depths[i], values[i]);
    }
  }

  return 0;
}
