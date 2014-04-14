#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int n = atoi(argv[1]);
  const int m = atoi(argv[2]);
  
  for(int i = 0; i < n; ++i)
  {
    cout << m << endl;

    for(int j = 0; j < m; ++j)
      cout << 1000 - (rand() % 1999) + 1 << endl;
  }

  return 0;
}
