#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const size_t D_MAX = 1024;
const size_t W_MAX = 26;
const size_t B_MAX = 96;

// map hash -> word
// on insert, if collision then mark and discard.
// otherwise copy out and sort unmarked entries

struct Hash
{
  Hash(const string &word)
  {
    for(size_t i = 0; i < W_MAX; ++i)
      hash[i] = 0;

    for(size_t i = 0; i < word.length(); ++i)
      ++hash[tolower(word[i]) - 97];    
  }

  bool operator<(const Hash &other) const
  {
    for(size_t i = 0; i < W_MAX; ++i)
    {
      if(hash[i] == other.hash[i])
        continue;

      if(hash[i] < other.hash[i])
        return true;

      if(hash[i] > other.hash[i])
        return false;
    }
    return false;
  }

  size_t hash[W_MAX];
};

typedef struct
{
  string word;
  bool marked;

} Entry;

typedef map<Hash, Entry> Dictionary;

int main()
{
  char buffer[W_MAX];
  Dictionary dict;

  while(scanf(" \t\n%[^ \t\n]", buffer))
  {
    if(buffer[0] == '#') break;
    Entry entry;
    entry.word = string(buffer);
    entry.marked = false;

    Hash hash(entry.word);

    DEBUG(cout << "WORD = [" << entry.word << "]" << endl << "HASH ");

    for(size_t i = 0; i < W_MAX; ++i)
      DEBUG(cout << hash.hash[i]);
    DEBUG(cout << endl);

    const Dictionary::iterator it = dict.find(hash);

    if(it == dict.end())
    {
      DEBUG(cout << "NOT FOUND inserting" << endl);
      dict.insert(Dictionary::value_type(hash, entry));
    }
    else
    {
      DEBUG(cout << "FOUND marked" << endl);
      it->second.marked = true;
    }
  }

  typedef vector<string> WordsVector;

  WordsVector output;

  {
    Dictionary::const_iterator it = dict.begin();
    const Dictionary::const_iterator ie = dict.end();
    
    while(it != ie)
    {
      if(!it->second.marked)
      {
        DEBUG(cout << "WORD [" << it->second.word << "] not marked, adding" << endl);
        output.push_back(it->second.word);
      }
      ++it;
    }
    
    sort(output.begin(), output.end());
  }

  {
    WordsVector::const_iterator it = output.begin();
    const WordsVector::const_iterator ie = output.end();

    while(it != ie)
    {
      cout << *it << endl;
      ++it;
    }
  }

  return 0;
}
