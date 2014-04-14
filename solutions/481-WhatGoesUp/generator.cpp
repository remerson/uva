#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int n = atoi(argv[1]);

  for (int i = 0; i < n; ++i)
    cout << rand() - (INT_MAX / 2) << endl;
  
  return 0;
}
