See also:

http://stackoverflow.com/questions/4938833/find-longest-increasing-sequence

http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming

This is the O(n log n) variant.


The array m is maintained that stores indices into v.

This array m is also kept sorted (increasing) by values of v (even though it stores indices, 
so this requires a custom comparator functor).

The purpose of m[i] is to store the index into v of the smallest element of v that ends a
subsequence of length i. It is important to note that m is NOT the LIS itself in this case.

So m can be built up iteratively by looping over the values of v[1..n] as follows:

1) If the value of v[i] > the value of the previous m index v[m[i]] then extend the sequence 
by 1 element, so:

m[++len] = i;

This is because a i (and v[i]) can extend the previous maximum LIS.

2) Otherwise, the value of v[i] is not greater than the previous maximum m index, so this
means instead it is necessary to update m to update the appropriate element to be i.

The element to be chosen needs to be the value in m that is the smallest value greater than
v[i]. In practice, this means std::upper_bound() because m is kept sorted. This is where
the O(log n) complexity part comes from.

This means the algorithm "greedily" always takes the smallest v[i] whereever possible and
inserts into m. This maintains the invariant of m - that m[i] (sequence of length i) contains
the smallest such v[m[i]].


This gives the maximum LIS length but does not yield the LIS itself because m only stores
the (index to the) smallest ending element of the actual LIS. So, a little bit more work
is needed to recover the actual LIS sequence.

Because m[n] contains the index of the smallest element ending the LIS of length n, there
is a starting point to recover the full LIS by storing the parent information of each m[i]
and then traversing this backwards to find the (reversed) LIS.

The array p[i] maintains the parent (previous LIS element) for m[i].

