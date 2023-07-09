#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

//using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int n;
  while(scanf("%d", &n) != EOF)
  {
    getchar();
    if(n == 0)
      break;
    char buffer[1024*1024] = {0};
    if(fgets(&buffer[0], 1024*1024, stdin));
//    if(scanf("%s\n", &buffer[0]));

    DEBUG(printf("SHIFT = %d BUFFER [%s]\n", n, &buffer[0]));
    
    int l = strlen(buffer);
    for(int i = 0; i < l; ++i)
    {
      if(buffer[i] >= 'a' && buffer[i] <= 'z')
      {
        buffer[i] = 'a' + ((buffer[i] + n - 'a') % 26);
        if(buffer[i] < 'a')
          buffer[i] += 26;
      }
      if(buffer[i] >= 'A' && buffer[i] <= 'Z')
      {
        buffer[i] = 'A' + ((buffer[i] + n - 'A') % 26);
        if(buffer[i] < 'A')
          buffer[i] += 26;
      }
    }
    printf("%s", &buffer[0]);
  }

  return 0;
}
