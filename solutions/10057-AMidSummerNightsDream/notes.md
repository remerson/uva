If you want to make it go very fast, it's not actually necessary to sort all the values because we
really only need the n / 2'th and n / 2 - 1'th values along with the counts of each value. This gives
the first value of the output and the other two output values are directly determined from this and
the counts.

The counts are trivial to determine and you would do this anyway if you were going to use a counting
sort.

Finding the two values for n / 2'th and n / 2 - 1'th is possible to do without sorting/storing the
whole array by using a modified counting sort that does not actually sort (!) but instead records these
two values at the points it would have written them out to the sorted array instead. i.e. when it
crosses the n / 2'th and n / 2 - 1'th points. Conveniently, as only these two values are needed, it
also has the advantage you can terminate the "sort" once you have them. So, the "sort" time is
only O(N / 2) - that is, you can "sort" an array in half linear time if you only need half the sorted 
array :)

So it's possible to compute the answer for 1M values but using only about 256k of memory as only the
counts need to be stored.

