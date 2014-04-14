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

const int C_MAX = 52;

char face[C_MAX];
char suit[C_MAX];

int main()
{
  int t;

  if(scanf("%d\n", &t));
  
  for(int i = 1; i <= t; ++i)
  {
    if(scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c\n",
             &face[0], &suit[0],
             &face[1], &suit[1],
             &face[2], &suit[2],
             &face[3], &suit[3],
             &face[4], &suit[4],
             &face[5], &suit[5],
             &face[6], &suit[6],
             &face[7], &suit[7],
             &face[8], &suit[8],
             &face[9], &suit[9],
             &face[10], &suit[10],
             &face[11], &suit[11],
             &face[12], &suit[12],

             &face[13], &suit[13],
             &face[14], &suit[14],
             &face[15], &suit[15],
             &face[16], &suit[16],
             &face[17], &suit[17],
             &face[18], &suit[18],
             &face[19], &suit[19],
             &face[20], &suit[20],
             &face[21], &suit[21],
             &face[22], &suit[22],
             &face[23], &suit[23],
             &face[24], &suit[24],
             &face[25], &suit[25],

             &face[26], &suit[26],
             &face[27], &suit[27],
             &face[28], &suit[28],
             &face[29], &suit[29],
             &face[30], &suit[30],
             &face[31], &suit[31],
             &face[32], &suit[32],
             &face[33], &suit[33],
             &face[34], &suit[34],
             &face[35], &suit[35],
             &face[36], &suit[36],
             &face[37], &suit[37],
             &face[38], &suit[38],

             &face[39], &suit[39],
             &face[40], &suit[40],
             &face[41], &suit[41],
             &face[42], &suit[42],
             &face[43], &suit[43],
             &face[44], &suit[44],
             &face[45], &suit[45],
             &face[46], &suit[46],
             &face[47], &suit[47],
             &face[48], &suit[48],
             &face[49], &suit[49],
             &face[50], &suit[50],
             &face[51], &suit[51]));

    printf("Case %d: %c%c\n", i, face[32], suit[32]);
  }

  return 0;
}
