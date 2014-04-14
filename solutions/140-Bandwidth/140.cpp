#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cstring>


#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

const size_t N_MAX = 32;
const size_t V_MAX = 8;

const size_t B_MAX = N_MAX * N_MAX;

int adjacency[N_MAX][N_MAX];

char buffer[B_MAX];

using namespace std;

inline char *read_int(int &v, char *b)
{
  bool negative = false;
  v = 0;
  while(!isdigit(*b))
  {
    if(*b == '-')
      negative = true;
    ++b;
  }
  
  while(isdigit(*b)) 
    v = v * 10 + *(b++) - '0';
  if(negative) v *= -1;
  return b;
}

int main()
{
  while(true)
  {
    char *b = fgets(buffer, B_MAX - 1, stdin);
    if(*b == '#') break;

    DEBUG(printf("BUFFER [%s]\n", buffer));
    
    memset(adjacency, 0, sizeof(int) * N_MAX * N_MAX);

    bool mode = true;

    char m = 0, c;

    bool nodes_used[N_MAX] = {0};

    while(*b != '\n')
    {
      if(*b == ':') 
        mode = false;
      else if(*b == ';')
        mode = true;
      else if(mode)
      {
        m = *b;
        //DEBUG(printf("SET M = %c\n", m));
        m -= 64;
        nodes_used[m] = true;
      }
      else
      {
        c = *b;
        DEBUG(printf("SET %c -> %c\n", m+64, c));
        c -= 64;
        nodes_used[c] = true;
        adjacency[m][++adjacency[m][0]] = c;
        DEBUG(printf("adjacency[%d][%d] = %d\n", m, adjacency[m][0], c));
      }
      ++b;
    }

    int n = 0;
    char nodes[V_MAX];

    for(size_t i = 0; i < N_MAX; ++i)
      if(nodes_used[i]) nodes[n++] = i;

    char min_nodes[V_MAX] = {0};
    int min_bw = N_MAX;

    DEBUG(printf("START n = %d\n", n));

    do
    {
      int bw = 0;

      DEBUG(printf("NODES:"); for(int i = 0; i < n; ++i) printf(" %c", nodes[i] + 64); printf("\n"));

      for(int i = 0; i < n; ++i)
      {
        int current = nodes[i];
        for(int j = 1; j <= adjacency[current][0]; ++j)
        {
          int other = adjacency[current][j];
          int pos = -1;
          for(int k = 0; k < n && pos == -1; ++k) if(nodes[k] == other) pos = k;
          pos+=1;
          int distance = abs(i+1 - pos);
          
          DEBUG(printf("DIST %c -> %c = %d\n", 64+current, 64+nodes[pos-1], distance));

          bw = max(bw, distance);

          if(bw >= min_bw)
          {
            i = n;
            j = N_MAX;
          }
        }
      }

      DEBUG(printf("BW = %d MIN = %d\n", bw, min_bw));

      if(bw < min_bw)
      {
        memcpy(min_nodes, nodes, n * sizeof(char));
        DEBUG(printf("MIN NODES:"); for(int i = 0; i < n; ++i) printf(" %c", 64 + min_nodes[i]); printf("\n"));
        min_bw = bw;
      }

    } while(next_permutation(nodes, nodes + n));

    for(int i = 0; i < n; ++i)
      printf("%c ", min_nodes[i] + 64);
    printf("-> %d\n", min_bw);
  }

  return 0;
}
