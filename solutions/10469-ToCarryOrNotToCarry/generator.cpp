#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(0));

  for(int i = 0; i < atoi(argv[1]); ++i)
    printf("%u %u\n", rand(), rand());
  
  return 0;
}
