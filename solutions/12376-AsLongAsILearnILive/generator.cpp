#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <list>
#include <set>

using namespace std;

// Boosted from:
// http://stackoverflow.com/questions/12790337/generating-a-random-dag

#define MIN_PER_RANK 1 /* Nodes/Rank: How 'fat' the DAG should be.  */
#define MAX_PER_RANK 3
#define MIN_RANKS 20   /* Ranks: How 'tall' the DAG should be.  */
#define MAX_RANKS 30
#define PERCENT 80     /* Chance of having an Edge.  */

int main(int argc, char **argv)
{
  int i, j, k,nodes = 0,prev_nodes = 0;

  srand(time(0));

  const int max_t = atoi(argv[1]);
  
  cout << max_t << endl;

  //const int max_n = 100;
  //  const int max_m = max_n * (max_n - 1) / 2;

  typedef pair<int, int> EdgePair;

  typedef std::list<EdgePair> EdgeList;


  for(int s = 0; s < max_t; ++s)
  {
    EdgeList edges;
    cout << endl;
    nodes = 0;

    const int ranks = MIN_RANKS
      + (rand () % (MAX_RANKS - MIN_RANKS + 1));
    
    //  printf ("digraph {\n");
    for (i = 0; i < ranks; i++)
    {
      /* New nodes of 'higher' rank than all nodes generated till now.  */
      int new_nodes = MIN_PER_RANK
                      + (rand () % (MAX_PER_RANK - MIN_PER_RANK + 1));

      /* Edges from old nodes ('nodes') to new ones ('new_nodes').  */
      for (j = prev_nodes; j < nodes; j++)
        for (k = 0; k < new_nodes; k++)
          if ( (rand () % 100) < PERCENT)
          {
            edges.push_back(make_pair(j, k + nodes));
          }
            //cout << j << " " << k + nodes << endl;
      //            printf ("%d %d\n", j, k + nodes); /* An Edge.  */

      prev_nodes = nodes;
      nodes += new_nodes; /* Accumulate into old node set.  */
    }

    cout << nodes << " " << edges.size() << endl;

    cout << 0;

    set<int> generated;

    for(i = 1; i < nodes; ++i)
    {
      int v = rand() % 1000 + 1;
      while(generated.find(v) != generated.end())
        v = rand() % 1000 + 1;

      cout << " " << v;

      generated.insert(v);
    }
    cout << endl;

    EdgeList::const_iterator edge = edges.begin();

    for(i = 0; i < edges.size(); ++i)
    {
      cout << edge->first << " " << edge->second << endl;
      ++edge;
    }
  }
  
  return 0;
}
