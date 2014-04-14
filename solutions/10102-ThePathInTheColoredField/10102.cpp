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

using namespace std;

//const size_t MAX_N = 1024;
  
struct point
{
  point(int a, int b)
    : x(a), y(b) { }

  int x;
  int y;
};

int main()
{
  int n;

  while(cin >> n)
  {
    //cin >> n;
    //if(n == 0)
    //  break;
//    char buffer[4096];

    vector<point> start;
    vector<point> end;

    DEBUG(printf("N = %d\n", n));

    for(int i = 0; i < n; ++i)
    {
      int j = 0;
      while(j < n)
      {
	char c;
	cin >> c;
      //if(fgets(buffer, 4095, stdin))
      //{
      //DEBUG(printf("BUFFER [%s]\n", buffer));
      //int k = 0, j = 0;
      //while(buffer[k] != '\n')
      //{
	switch(c)
	{
	case '1':
	  DEBUG(printf("START (%d, %d)\n", j, i));
	  start.push_back(point(j, i));
	  ++j;
	  break;
	case '2':
	  ++j;
	  break;
	case '3':
	  DEBUG(printf("END (%d, %d)\n", j, i));
	  end.push_back(point(j, i));
	  ++j;
	  break;
	default:
	  break;
	};
      }
    }

    DEBUG(printf("num_start = %d num_end = %d\n", (int) start.size(), (int) end.size()));

    int global_max = 0;

    for(int i = 0; i < (int) start.size(); ++i)
    {
      int local_min = n * n;

      for(int j = 0; j < (int) end.size(); ++j)
      {
	const int dist = abs(end[j].x - start[i].x) + abs(end[j].y - start[i].y);
	DEBUG(printf("FROM start = %d (%d, %d) end = %d (%d, %d) dist = %d\n",  i, start[i].x, start[i].y, j, end[j].x, end[j].y, dist));
	local_min = min(local_min, dist);
      }

      DEBUG(printf("MAX start = %d (%d, %d) local_min = %d\n", i, start[i].x, start[i].y, local_min));
      
      global_max = max(global_max, local_min);

      DEBUG(printf("global_max = %d\n", global_max));
    }

    printf("%d\n", global_max);
  }

  return 0;
}
