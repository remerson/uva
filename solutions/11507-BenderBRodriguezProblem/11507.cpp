#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

// array<int, 3> bender(array<int, 3> v, string move)
// {
//   if(move == "No")
//     return v;
  
//   int sine = 1;
//   if(move[0] == '-')
//   {
//     DEBUG(printf("-ve "));
//     sine *= -1;
//   }
//   else
//   {
//     DEBUG(printf("+ve "));
//   }

//   array<array<int, 3>, 3> matrix;

//   if(move[1] == 'y')
//   {
//     DEBUG(printf("y rotation\n"));
//     // Rz
//     matrix = array<array<int, 3>, 3>{array<int, 3>{0, 1 * sine, 0}, array<int, 3>{sine, 0, 0}, array<int, 3>{0, 0, 1}};
//     //matrix = array<array<int, 3>, 3>{array<int, 3>{0, 0, sine}, array<int, 3>{0, 1, 0}, array<int, 3>{-1 * sine, 0, 0}};
//   }
//   else
//   {
//     DEBUG(printf("z rotation\n"));
//     // Ry
//     matrix = array<array<int, 3>, 3>{array<int, 3>{0, 0, sine}, array<int, 3>{0, 1, 0}, array<int, 3>{-1 * sine, 0, 0}};
//     //matrix = array<array<int, 3>, 3>{array<int, 3>{0, -1 * sine, 0}, array<int, 3>{sine, 0, 0}, array<int, 3>{0, 0, 1}};
//   }

//   array<int, 3> result = {0, 0, 0};

//   // for(int i = 0; i < 3; ++i)
//   //   result[i] += v[0] * matrix[i][0] + v[1] * matrix[i][1] + v[2] * matrix[i][2];
  
//   result[0] = v[0] * matrix[0][0] + v[1] * matrix[1][0] + v[2] * matrix[2][0];
//   result[1] = v[0] * matrix[0][1] + v[1] * matrix[1][1] + v[2] * matrix[2][1];
//   result[2] = v[0] * matrix[0][2] + v[1] * matrix[1][2] + v[2] * matrix[2][2];

//   return result;
// }

string bender(const string &pos, const string &move)
{
  if(move == "No") return pos;
  
  if(move == "+y")
  {
    if(pos == "+x") return "+y";
    if(pos == "-x") return "-y";
    if(pos == "+y") return "-x";
    if(pos == "-y") return "+x";
    return pos;
  }
  if(move == "-y")
  {
    if(pos == "+x") return "-y";
    if(pos == "-x") return "+y";
    if(pos == "+y") return "+x";
    if(pos == "-y") return "-x";
    return pos;
  }

  if(move == "+z")
  {
    if(pos == "+x") return "+z";
    if(pos == "-x") return "-z";
    if(pos == "+z") return "-x";
    if(pos == "-z") return "+x";
    return pos;
  }

  if(move == "-z")
  {
    if(pos == "+x") return "-z";
    if(pos == "-x") return "+z";
    if(pos == "+z") return "+x";
    if(pos == "-z") return "-x";
    return pos;
  }
  return "bad";
}

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  int L = 0;
  
  while(scanf("%d\n", &L) != EOF)
  {
    DEBUG(printf("L = %d\n", L));
    char buffer[8] = {0};

    string pos = "+x";
    
    if(L == 0)
      break;
    
    while(--L)
    {
      if(scanf("%c%c%c", &buffer[0], &buffer[1], &buffer[2]));
      buffer[2] = '\0';
      DEBUG(printf("buffer = [%s]\n", &buffer[0]));
      string move = string(&buffer[0]);
    
      DEBUG(printf("BEFORE pos = %s move = %s\n", pos.c_str(), move.c_str()));

      pos = bender(pos, move);

      DEBUG(printf("AFTER pos = %s move = %s\n", pos.c_str(), move.c_str()));
    }

    printf("%s\n", pos.c_str());
  }
       

  return 0;
}
