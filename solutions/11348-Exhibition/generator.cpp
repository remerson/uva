#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const unsigned k = atoi(argv[1]); // num test cases
  const unsigned n = atoi(argv[2]); // num
  const unsigned v = atoi(argv[3]); // max m
  const unsigned a = atoi(argv[4]); // max a

  cout << k << endl;

  for(unsigned i = 1; i <= k; ++i)
  {
    cout << n << endl;

    for(unsigned j = 0; j < n; ++j)
    {
      //const unsigned m = rand() % 50 + 1;
      const unsigned m = rand() % v + 1;

      cout << m;

      for(unsigned k = 0; k < m; ++k)
        cout << " " << rand() % a + 1;
      
      cout << endl;
    }
  }
  
  return 0;
}

