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
#include <string>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int B_MAX = 128;

int main()
{
  //  std::ios_base::sync_with_stdio(false);

  int t;

  if(scanf("%d", &t));

  DEBUG(printf("T = %d\n", t));

  for(int c = 0; c < t; ++c)
  {
    int n, m;

    if(scanf("%d\n", &n));

    DEBUG(printf("N = %d\n", n));

    typedef map<string, string> CandidatePartyMap;

    CandidatePartyMap candidateParties;

    char buffer[B_MAX];

    for(int i = 0; i < n; ++i)
    {
      fgets(buffer, B_MAX, stdin);
      const string candidate(buffer);
      fgets(buffer, B_MAX, stdin);
      const string party(buffer);
      DEBUG(printf("ADD candidate [%s] party [%s]\n", candidate.c_str(), party.c_str()));
      candidateParties.insert(CandidatePartyMap::value_type(candidate, party));
    }

    if(scanf("%d\n", &m));

    DEBUG(printf("M = %d\n", m));

    typedef map<string, int> VotesMap;

    VotesMap votes;

    {
      CandidatePartyMap::const_iterator it = candidateParties.begin();
      const CandidatePartyMap::const_iterator ie = candidateParties.end();
      
      while(it != ie) { votes.insert(VotesMap::value_type(it->first, 0)); ++it; }
    }

    for(int i = 0; i < m; ++i)
    {
      fgets(buffer, B_MAX, stdin);
      const string candidate(buffer);
      
      VotesMap::iterator it = votes.find(candidate);
      if(it != votes.end()) 
      {
        it->second++;
        DEBUG(printf("VOTES %s = %d\n", it->first.c_str(), it->second));
      }
    }

    DEBUG(if(votes.size() < 2) printf("BAD NEWS!\n"));

    {
      typedef multimap<int, string, greater<int> > ScoreMap;

      ScoreMap scores;

      {
        VotesMap::const_iterator it = votes.begin();
        const VotesMap::const_iterator ie = votes.end();
        
        while(it != ie) 
        {
          scores.insert(ScoreMap::value_type(it->second, candidateParties.find(it->first)->second));
          DEBUG(printf("SCORED TOTAL %d => %s %s\n", it->second, it->first.c_str(), candidateParties.find(it->first)->second.c_str()));
          ++it;
        }
      }

      
      ScoreMap::const_iterator check = scores.begin();
      ++check;
      ScoreMap::const_iterator highest = scores.begin();
    
      DEBUG(if(check == scores.end() || scores.size() == 1) printf("BAD NEWS!!!\n"));

      DEBUG(printf("HIGHEST [%s] => %d CHECK [%s] => %d\n",
                   highest->second.c_str(),
                   highest->first,
                   check->second.c_str(),
                   check->first));
                   
      if(c != 0) printf("\n");

      if(highest->first == check->first)
        printf("tie\n");
      else
        printf("%s", highest->second.c_str());
    }

  }

  return 0;
}
