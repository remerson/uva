#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <limits>

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

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  const int N_MAX = 2000;

  for(int a = 1; 4 * a < N_MAX; ++a)
    for(int b = a; a + (3 * b) < N_MAX; ++b)
      for(int c = b; a + b + (2 * c) < N_MAX; ++c)
      {
	// const double i = a / 100.0;
	// const double j = b / 100.0;
	// const double k = c / 100.0;

	//double sum = i + j + k;
	long long sum = a + b + c;
	//if(sum > N_MAX)
	//  continue;

	//double product = i * j * k;
	long long product = a * b * c;
	//if(product > N_MAX)
	//  continue;

	//const double scale = 1000000.0;

	const long long scale = 100 * 100 * 100;

	if(product <= scale)
	  continue;

	//const double l = sum / (product - 1.0);
	const long long d = (sum * scale) / (product - scale);

	//const double l = d / 100.0;

	// DEBUG(printf("CALCULATE %d %d %d %llu"
	// 	     " sum = %llu product = %llu\n",
	// 	     a, b, c, d, sum, product));
	
	if(d < c)
	  continue;

	if(d > N_MAX)
	  continue;

	// sum += l;

	// if(sum > N_MAX)
	//   continue;

	{
	  const double i = a / 100.0;
	  const double j = b / 100.0;
	  const double k = c / 100.0;
	  const double l = d / 100.0;

	  const double sum = i + j + k + l;

	  if(sum > 20.0)
	    continue;

	  const double product = i * j * k * l;

	  if(product > 20.0)
	    continue;

	  // DEBUG(printf("TRY %0.2f %0.2f %0.2f %0.2f"
	  // 	       " sum = %0.8f product = %0.8f\n",
	  // 	       i, j, k, l, sum, product));
	
	  if(fabs(sum - product) < 1e-9)
	  {
	     DEBUG(printf("SOLVED %0.2f %0.2f %0.2f %0.2f"
		       " sum = %0.8f product = %0.8f\n",
		       i, j, k, l, sum, product));
	    printf("%0.2f %0.2f %0.2f %0.2f\n", i, j, k, l);
	  }
	}
  }

  return 0;
}
