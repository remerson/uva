#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int S_MAX = 1000000001;

  for(int i = 0; i < atoi(argv[1]); ++i)
  {
    cout << (rand() % S_MAX) + 1;
    cout << " ";
    cout << (rand() % S_MAX) + 1;
    cout << endl;
  }
  
  return 0;
}
