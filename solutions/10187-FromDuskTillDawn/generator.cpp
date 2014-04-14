#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>

using namespace std;

char random_char()
{
  const char charset[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
  const size_t max_index = (sizeof(charset) - 1);
  return charset[ rand() % max_index ];
}

std::string random_string( size_t length )
{
    std::string str(length,0);
    std::generate_n( str.begin(), length, random_char );
    return str;
}

const int MAX_CITIES = 100;

string cities[MAX_CITIES];

void generate_names()
{
  for(int i = 0; i < MAX_CITIES; ++i)
  {
    cities[i] = random_string(4);
  }
}

int main(int argc, char **argv)
{
  srand(time(0));

  generate_names();

  // num test cases
  const int t = atoi(argv[1]);
  // num edges
  const int r = atoi(argv[2]);
  // num cities
  const int c = atoi(argv[3]);

  cout << t << endl;

  for(int i = 0; i < t; ++i)
  {
    cout << r << endl;

    for(int j = 0; j < r; ++j)
    {
      cout << cities[rand() % c] << " ";
      cout << cities[rand() % c] << " ";
      cout << rand() % 24 + 1 << " ";
      cout << rand() % 24 + 1;
      cout << endl;
    }
    
    cout << cities[rand() % c] << " ";
    cout << cities[rand() % c];
    cout << endl;
  }    

  return 0;
}
