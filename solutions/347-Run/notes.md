# UVa 347 Run

   * http://uva.onlinejudge.org/external/3/347.html

## Categories

   * Complete search.

## Approach

Direct simulation using bitset. Check whether the given string is a run,
if not, then increment to find the next possible candidate and repeat
this check until the nearest runaround number is found. 

## Hints

   * Each digit can appear only once in a run.
   * For a given run of length n, any digit d s.t. d mod n = 0 cannot
     form part of a run (because it would introduce a direct trivial cycle).

## Optimisations

   * None attempted.
