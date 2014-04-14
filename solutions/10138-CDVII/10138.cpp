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

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t MAX_T = 24;
const size_t B_MAX = 512;
const size_t P_MAX = 32;

struct Record
{
  char action; // "enter" => n  or "exit" => x
  int hour; // entry hour
  int distance;
};

typedef map<int, Record> TimeRecordMap;

typedef map<string, TimeRecordMap> PlateRecordMap;


inline int calculate_time(int day, int hour, int minute)
{
  return minute + (hour * 60) + (day * 24 * 60);
}


int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif
  
  int n;

  if(scanf("%d\n", &n));

  DEBUG(printf("n = %d\n", n));
  
  char buffer[B_MAX + 1];

  int month, day, hour, minute, distance;

  for(int t = 0; t < n; ++t)
  {
    if(t > 0) printf("\n");

    int tariffs[MAX_T];
    
    for(size_t i = 0; i < MAX_T; ++i)
      if(scanf("%d", &tariffs[i]));


    PlateRecordMap records;

    char read_plate[P_MAX];
    char read_action[P_MAX];

    fgets(buffer, B_MAX, stdin);

    while(fgets(buffer, B_MAX, stdin))
    {
      DEBUG(printf("buffer [%s]\n", buffer));

      if(buffer[0] == '\n')
        break;

      if(sscanf(buffer, "%s %d:%d:%d:%d %s %d\n", &read_plate[0], &month, &day, &hour, &minute, &read_action[0], &distance) == 7)
      {
        const string plate(read_plate);

        DEBUG(printf("READ %s %d:%d:%d:%d %s %d\n", plate.c_str(), month, day, hour, minute, read_action, distance));

        PlateRecordMap::iterator it = records.find(plate);
        
        if(it == records.end())
          it = records.insert(PlateRecordMap::value_type(plate, TimeRecordMap())).first;

        Record rec;

        rec.action = read_action[1];
        rec.distance = distance;
        rec.hour = hour;

        it->second.insert(TimeRecordMap::value_type(calculate_time(day, hour, minute), rec));
      }
    }

    PlateRecordMap::iterator it = records.begin();
    const PlateRecordMap::iterator ie = records.end();
    
    while(it != ie)
      {
        double fare = 0.0;
        
        
        TimeRecordMap::iterator current = it->second.begin();

        while(current != it->second.end())
        {
          // enter
          if(current->second.action == 'n')
          {
            TimeRecordMap::iterator next = current;
            ++next;

            if(next->second.action == 'x')
            {
              // match found
              const double d = fabs(next->second.distance - current->second.distance);

              const double cost = d * tariffs[current->second.hour] / 100.0;

              fare += cost + 1.0;
            }
          }
          
          ++current;
        }

        // account charge
        if(fare > 0.0)
        {
          fare += 2.0;
          printf("%s $%.2f\n", it->first.c_str(), fare);
        }

        ++it;
        }
    
      

  }

  return 0;
}
