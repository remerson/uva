#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>

using namespace std;

const int MAX_V = 10010;

inline void generate(const int max_s, const int max_v)
{
  int s = (rand() % max_s) + 1;

  while(s > max_v)
    s = (rand() % max_s) + 1;

  cout << s;

  std::bitset<MAX_V> generated;

  for(int i = 0; i < s; ++i)
  {
    int v = (rand() % max_v) + 1;

    while(generated.test(v))
      v = (rand() % max_v) + 1;

    generated.set(v);

    cout << " " << v;
  }

  cout << endl;
}

int main(int argc, char **argv)
{
  srand(time(0));

  const int t = atoi(argv[1]);
  const int max_s = atoi(argv[2]);
  const int max_v = atoi(argv[3]);

  cout << t << endl;

  for(int r = 0; r < t; ++r)
  {
    generate(max_s, max_v);
    generate(max_s, max_v);
    generate(max_s, max_v);
  }
  
  return 0;
}
