This can be solved (very fast) using disjoint sets. I suspect this is the reason for the discrepancy on the Top 20 for this problem i.e. > position 10 are taking about 0.5 secs whereas the top 5 or so higher ranks are 4x faster (or more). These higher rankings are most likely using the disjoint sets approach with some high speed I/O.

Only union cities of maximum PPA value. If a higher PPA value is encountered while processing an edge, then reset disjoint sets and start again. Although the problem statement alludes to the average PPA value in the province, the province with the highest average PPA will be the one that only includes the maximal PPA value in the input because the province can be as small as only 2 cities, irrespective of the size of the empire.

This results in a single disjoint set (of only the maximal PPA values). From here, find the cardinality of each connected component. The answer is the largest such cardinality value. So, you need a slightly modified disjoint sets that also keeps the cardinality of each connected component.

Note that the maximal PPA value can be negative as the problem statement says: "the PPA of that road (fits in a signed 32 bit variable)"

It is not necessary to worry about initialising the current maximum PPA with an arbitrary negative value because m >= 1 so there will always be a given initial m value to initialise the maximum PPA with.

The value of m is also high (1M) so I/O (input) optimisation will be of benefit here (pathlogical case could give an input file size of about ~16Mb!).

There were three optimisations I tried:

1) Optimised input handling in a few ways. Mainly this meant putting a size based branch in to avoid a lot of unnecessary bounds checking logic if the remaining buffer size is large enough (over 16 bytes). This has the effect of avoiding calls to advance() which even though inlined, still was adding a branch. This had a big impact (about 3x speed up).

2) Stripped down disjoints set implementation to avoid branching in unite() (apart from the parent() calls which are unavoidable). Initially, the implementation was counting maximal cardinality of each connected component here which is unnecessary and slow. Instead the maximum cardinality check is done at the end (and instead bounded only by N rather than potentially M as is the case with unite() and as N << M this seemed like a good idea). This is done in two N loop passes and is a little bit inefficient. This gave a small speed up but not as much as I hoped. Maybe 5-10%.

3) Optimistic data set size handling. Only the routes needed for the maximal PPA value are handled during input and those which are not used are discarded as soon as they are read. This makes quite a big differrence is some cases but less so in others.
