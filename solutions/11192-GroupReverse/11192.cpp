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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 255;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int g;

  while(scanf("%d", &g) == 1)
  {
    if(g == 0)
      break;
    

    char input[B_MAX + 1];

    if(fgets(input, B_MAX, stdin));

    DEBUG(printf("input = [%s]\n", input));

    char output[B_MAX + 1];

    size_t len = strlen(input);
    int b = 0;

    for(int i = 0; i < len; ++i)
      if(isupper(input[i]) || islower(input[i]) || isdigit(input[i]))
        output[b++] = input[i];

    output[b] = '\0';

    //size_t len = strlen(output);

    g = b / g;

    DEBUG(printf("g = %d len = %d\n", g, b));
    DEBUG(printf("output = %s\n", output));

    for(int i = 0; i < b; i += g)
    {
      reverse(&output[i], &output[i + g]);
    }

    printf("%s\n", output);


  }
  

  return 0;
}
