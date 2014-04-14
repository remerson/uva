#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const int MAX_F = 46;
const int B_MAX = 512;

int fib[MAX_F];

void generate_fib()
{
  fib[0] = 1;
  fib[1] = 1;
  fib[2] = 2;

  for(int i = 3; i < MAX_F; ++i)
  {
    fib[i] = fib[i-1] + fib[i-2];
    //    DEBUG(printf("GENFIB %d -> %d\n", i, fib[i]));
  }
}

int find_fib(int f)
{
  for(int i = 1; i < MAX_F; ++i)
    if(fib[i] == f) 
      return i;
  //DEBUG(printf("ERROR!!! f = %d not found!!!\n", f));
  return 0;
}


int main(int argc, char **argv)
{
  const char *plain = argv[1];
  const char *encoded = argv[2];

  generate_fib();

  

  
  return 0;
}
