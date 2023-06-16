#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>

//#include <algorithm>
#include <set>
//#include <map>
#include <queue>
#include <iostream>
//#include <iterator>
//#include <bitset>

//#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int t;
  string line;

  const size_t MAX_LEN = 256;

  typedef vector<string> StringVector;

  StringVector bins[MAX_LEN];

  cin >> t;
  getline(cin, line);
  getline(cin, line);
  DEBUG(printf("READ T = %d (START): %s\n", t, line.c_str()));

  size_t min_len = MAX_LEN, max_len = 0;

  for(int q = 0; q < t; ++q)
  {
    DEBUG(printf("Q = %d\n", q));
    while(true)
    {

      DEBUG(printf("Calling getline\n"));
      getline(cin, line);
      
      DEBUG(printf("READ: %s\n", line.c_str()));
	
      if(line.empty())
      {
	DEBUG(printf("END OF TEST REACHED\n"));
	
	typedef set<string> StringSet;

	StringSet all;

	size_t x = min_len;
	size_t y = max_len;
	bool found = false;
	string match;

	while(x < MAX_LEN && y >= 0)
	{
	  for(size_t i = 0; i < bins[x].size() && !found; ++i)
	    for(size_t j = 0; j < bins[y].size() && !found; ++j)
	    {
	      match = bins[x][i] + bins[y][j];
	      DEBUG(printf("Check: %s\n", match.c_str()));
	      pair<StringSet::iterator,bool> check = all.insert(match);
	      found = !check.second;
	    }

	  if(found)
	    break;

	  ++x;
	  --y;
	}

	if(!found)
	{
	  if(min_len == max_len)
	    match = bins[min_len][0] + bins[min_len][1];
	  else
	    match = bins[min_len][0] + bins[max_len][0];
	}

	if(q > 0)
	  printf("\n");
	
	printf("%s\n", match.c_str());

	for(size_t i = 0; i < MAX_LEN; ++i)
	  bins[i].clear();

	min_len = MAX_LEN;
	max_len = 0;
	break;
      }
      else
      {
	min_len = min(min_len, line.length());
	max_len = max(max_len, line.length());
	bins[line.length()].push_back(line);
	DEBUG(printf("min = %u max = %u\n", min_len, max_len));
      }
    }
  }


  return 0;
}
