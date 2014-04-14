#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);

  cout << t << endl;

  for(int i = 0; i < t; ++i)
  {
    const int s = 20000;

    cout << s << endl;

    const int N_MAX = 1000;
    
    for(int j = 0; j < (s - 1); ++j)
    {
      int r;

      do
      {
        r = (N_MAX / 900) - (rand() % N_MAX);
        
      } while(r == 0);

      cout << r << endl;
    }
  }

  return 0;
}
