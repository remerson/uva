## UVa 1047 Zones

   * http://uva.onlinejudge.org/external/10/1047.html

## Categories

   * Complete Search
   * Bit Manipulation
   * Combinations
   * [Gosper's Hack]
   * [Hamming Distance]

## Approach

This is a (sophisticated) complete search problem. Try all combinations of 
choosing R towers from the set of N (at most 20). 

There are two main parts to this problem:

1. Efficiently generating all combinations.
2. Efficiently calculating the coverage of each combination to determine
   the overall maximum.

To determine all bitwise combinations, use [Gosper's Hack]. This yields the
R combinations as a bitmask. To calculate the cost, add the towers for
the combination and subtract the overlapping/intersection values for the
combination (i.e. Hamming distance of the intersection and current
combination). This is relatively fast and straightforward to code. Work
through the examples on paper to understand why/how this works if in
doubt (I did, it was useful).

## Hints

   * Ensure your intersection works correctly.
   * No particularly trick/edge case input.

## Optimisation

The detail I go into below describes how to further optimise this for very
low execution times.

Most of this I figured out from analysis and benchmarking with valgrind
(cachegrind).

As the problem limits are small (max N = 20, T = 10), I/O optimisation is
of limited use. It is still worthwhile but the gains are pretty small. 

There are other areas of the algorithm that need to be tweaked.

To calculate the coverage cost of each combination, there are two
sub-parts (a) finding the total coverage of each tower (relatively easy,
but can be done in at least 3 ways) and then (b) subtracting the overlapping
coverage areas for the combination (harder).

The simplest (but slowest) way of determining the total cost is to check
each of the N bits in the current combination one-by-one and add up the
costs of all set bits (i.e. the towers for this combination). This results
in O(N) bitwise operations/checks and O(R) additions. If you were coding
in a contest, this is what you'd do because (a) it's very quick/easy to
understand and code and (b) it is fast enough to hit the time limit.

However, a more efficient method is to use a modified Hamming distance
algorithm (which will also be needed later) with [De Bruijn] lookup to
directly extract the tower indices from the current combination. This only
picks out the indices that are present and ignores those that don't.

A even more efficient approach is to realise that each combination only
differs from the previous by the addition of some elements and the removal
of others (often only 1 element).  Therefore, maintain a running total
instead of recalculating all towers for every combination. Determine the
elements which have been added from the previous combination (XOR, de Bruijin
to efficiently extract the array index and Modified Wenger-Hamming) and
add these tower values to the running total. Similarly, determine the 
elements which have been removed and subject these towers using the same 
method. This is O(A + S) where A + S < R.

For calculating the overlaps, assume that the overlapping towers are
bitwise encoded. Apply a linear scan of all intersections - this is feasible
because T <= 10, so is (very) small. Comparing one-by-one the intersection 
(bitwise-&) of the current combination gives the intersecting set of towers. 
The Hamming distance of this value gives the number of towers actually matched,
call this M (i.e. number of elements intersected). There must be at least 2 
(i.e. M > 1) matches for the value to apply and the number of matches (up to R) 
is relevant. The total to subtract should be M-1 (to exclude the "starting" 
tower). So, if 2 towers are matched then 1 * V should be subtracted. If 3 
towers are matched, then 2 * V should be subtracted and so forth (where V is 
the overlap coverage amount for that intersection).

I did not consider some ordering of the overlaps and instead just naively
linearly processed each one. Probably with some more sophisticated structuring,
it would be possible to get this down to only recalculating the overlaps of
the elements that changed from the previous combination (akin to the same
approach of calculating the single towers above).

As only 20-bits are used, a modified Hamming distance algorithm can be applied.
Precompute a 10-bit lookup table (I used the classic Wenger-Hamming algorithm).
Then when computing the Hamming distance of the overlap intersection, split
the 20-bit word into two 10-bit bytes and use the lookup table on each byte.
This more efficient that the regular Hamming algorithm by about 25% or so. It
trades two cache hits and a shift/& for several shifts, subtractions, additions
and a (relatively) high branch predict miss rate (about 14% or so). Again, in
a contest the regular Wenger-Hamming is plenty fast enough and trivial to code.

[Gosper's Hack]: https://en.wikipedia.org/wiki/Combinatorial_number_system
[Hamming Distance]: https://en.wikipedia.org/wiki/Hamming_distance
[De Bruijn]: http://supertech.csail.mit.edu/papers/debruijn.pdf
