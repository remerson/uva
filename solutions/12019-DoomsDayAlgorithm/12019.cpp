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

int day_since(int m1, int d1)
{
  // Jan 10th => Monday, so Jan 1st => Sat
  int d = 0;

  --m1;

  DEBUG(printf("m1 = %d\n", m1));

  switch(m1)
  {
  case 12:
    d += 31;
  case 11:
    d += 30;
  case 10:
    d += 31;
  case 9:
    d += 30;
  case 8:
    d += 31;
  case 7:
    d += 31;
  case 6:
    d += 30;
  case 5:
    d += 31;
  case 4:
    d += 30;
  case 3:
    d += 31;
  case 2:
    d += 28;
  case 1:
    d += 31;
  }

  DEBUG(printf("d = %d\n", d));

  d += d1;

  DEBUG(printf("d = %d d1 = %d\n", d, d1));

  return d;
}  

int main()
{
  int n, m,d;

  if(scanf("%d\n", &n));

  for(int i = 0; i < n; ++i)
  {
    if(scanf("%d %d\n", &m, &d) == 2);
  
    int k = day_since(m, d) + 4;

    DEBUG(printf("Days since %d %d = %d\n", m, d, k));

    k = fabs(k % 7);

    DEBUG(printf("k = %d\n", k));

    switch(k)
    {
    case 0:
      printf("Monday\n");
      break;
    case 1:
      printf("Tuesday\n");
      break;
    case 2:
      printf("Wednesday\n");
      break;
    case 3:
      printf("Thursday\n");
      break;
    case 4:
      printf("Friday\n");
      break;
    case 5:
      printf("Saturday\n");
      break;
    case 6:
      printf("Sunday\n");
      break;
    } 
  }

  return 0;
}
