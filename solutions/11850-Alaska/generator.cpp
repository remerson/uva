#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int n = atoi(argv[1]);

  const int maxf = atoi(argv[1]);

  for(int i = 0; i < n; ++i)
  {
    const int r = rand() % maxf + 1;
    cout << r << endl;
    for(int j = 0; j < r; ++j)
      cout << rand() % 1422 + 1 << endl;
  }

  cout << 0 << endl;

  return 0;
}
