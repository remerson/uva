#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const unsigned t = atoi(argv[1]); // num test cases
  const unsigned b = atoi(argv[2]); // upper bound for flakes
  const unsigned r = atoi(argv[3]); // range/collision limiter

  cout << t << endl;

  for(unsigned i = 1; i <= t; ++i)
  {
    //    const unsigned c = rand() % b + 1;

    const unsigned c = b;

    cout << c << endl;

    for(unsigned j = 0; j < c; ++j)
      cout << rand() % r << endl;
  }
  
  return 0;
}

