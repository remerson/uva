# UVa 188 Perfect Hash

   * http://uva.onlinejudge.org/external/1/188.html

## Categories

   * Complete Search
   * Hashing

## Approach

Simulate the search as per the problem description. There is an implicit
assumption that the words are unique. Most solutions work fine if the
words are unique but not if there are duplicated words. In this case, a
collision when the word is the same is fine but will cause a naive
algorithm to see a "global" collision, miss the real solution and keep
trying to ramp up C. This could mean WA or TLE.

## Hints

   * Check your scoring works properly and independently.
   * You definitely do *not* need unsigned. My solution is AC without it.
   * I think in the judge data, each input line only contains unique words
     although the problem description does not state this explicitly.

## Optimisations

   * None attempted.
