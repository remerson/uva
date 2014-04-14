#include <iostream>
#include <cstdio>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const char POSITIVE = '+';
const char NEGATIVE = '-';
const char FAILED = '*';
const char NOTCOMPLETE = '?';

const unsigned BINS = 6;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int bins[BINS + 1];

  while(scanf("%d %d %d %d %d %d\n", &bins[1], &bins[2], &bins[3], &bins[4], &bins[5], &bins[6]) == 6)
  {
    if(bins[1] == 0 && bins[2] == 0 && bins[3] == 0 && bins[4] == 0 && bins[5] == 0 && bins[6] == 0)
      break;

    int packets = bins[6];
    bins[6] = 0;

    DEBUG(printf("6) packets = %d BINS %d %d %d %d %d %d\n", packets, bins[1], bins[2], bins[3], bins[4], bins[5], bins[6]));

    // For each [5] there is 11[1] space left
    if(bins[5] > 0)
    {
      const int spare = bins[5] * 11;
      const int used = min(bins[1], spare);
      const int remain = spare - used;
      bins[1] -= used;
      DEBUG(printf("spare = %d used = %d remain = %d\n", spare, used, remain));
    }

    packets += bins[5];
    bins[5] = 0;

    DEBUG(printf("5) packets = %d BINS %d %d %d %d %d %d\n", packets, bins[1], bins[2], bins[3], bins[4], bins[5], bins[6]));

    // For each [4] there is 5[2] space OR 4[1] per [2] not used.
    if(bins[4] > 0)
    {
      const int spare = bins[4] * 5;
      const int used = min(bins[2], spare);
      const int remain = spare - used;
      DEBUG(printf("spare = %d used = %d remain = %d\n", spare, used, remain));
      bins[2] -= used;
      if(remain > 0) // Each [2] not used can be used for up to 4[1]
      {
        const int spare = 4 * remain;
        const int used = min(bins[1], spare);
        const int remain = spare - used;
        bins[1] -= used;
      }
    }

    packets += bins[4];
    bins[4] = 0;

    DEBUG(printf("4) packets = %d BINS %d %d %d %d %d %d\n", packets, bins[1], bins[2], bins[3], bins[4], bins[5], bins[6]));
    
    if(bins[3] > 0)
    {
      packets += bins[3] / 4;

      //const int remain = 4 - (bins[3] % 4);

      if(bins[3] % 4 != 0)
      {
        const int remain = 4 - (bins[3] % 4);
        ++packets;
        int fit = 1;

        switch(remain)
          {
          case 1:
            fit = 1;
            break;
          case 2:
            fit = 3;
            break;
          case 3:
            fit = 5;
            break;
          }

        // For each [3] there is 1[2] space OR 4[1] per [2] not used.
        // OR if there are 2[3] there is 3[2] space
        {
          const int spare = fit;
          const int used = min(bins[2], spare);
          int remain = spare - used;
          bins[2] -= used;
          remain = (fit - used) * 4 + 7;
          DEBUG(printf("fit = %d spare = %d used = %d remain = %d\n", fit, spare, used, remain));
          if(remain > 0) // Each [2] not used can be used for up to 4[1]
          {
            
            const int spare = remain;
            const int used = min(bins[1], spare);
            const int remain = spare - used;
            bins[1] -= used;
          }
        }
      }

      bins[3] = 0;
    }

    DEBUG(printf("3) packets = %d BINS %d %d %d %d %d %d\n", packets, bins[1], bins[2], bins[3], bins[4], bins[5], bins[6]));

    if(bins[2] > 0)
    {
      packets += bins[2] / 9;

      // Plus one packet to hold < 4 [3] (plus some other stuff)
      if(bins[2] % 9 != 0)
      {
        ++packets;
        
        const int remain = 9 - (bins[2] % 9);
        if(remain > 0) // Each [2] not used can be used for up to 4[1]
        {
          const int spare = 4 * remain;
          const int used = min(bins[1], spare);
          const int remain = spare - used;
          bins[1] -= used;
        }
      }

      bins[2] = 0;
    }

    DEBUG(printf("2) packets = %d BINS %d %d %d %d %d %d\n", packets, bins[1], bins[2], bins[3], bins[4], bins[5], bins[6]));

    if(bins[1] > 0)
    {
      packets += bins[1] / 36;

      // Plus one packet to hold < 36 [1]
      ++packets;

      bins[1] = 0;
    }

    DEBUG(printf("1) packets = %d BINS %d %d %d %d %d %d\n", packets, bins[1], bins[2], bins[3], bins[4], bins[5], bins[6]));

    printf("%d\n", packets);
    
    
  }

  return 0;
}
