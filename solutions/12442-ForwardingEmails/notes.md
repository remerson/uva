This one is quite tricky. Mainly because the constraints (N = 50000) mean that a linear algorithm is needed (rather than
the much-easier-to-code quadratic one).

For this I used an extension to Floyd's "Tortoise and Hare" cycle finding algorithm.

Floyd's algorithm is used to calculate the lengths of the paths from each index by finding any cycle from that index,
determining the cycle length and then (the extension part) marking off that length against all elements within the cycle.

In the case where the cycle may not be from the starting element, it is necessary to add the offset from that element
to the start of the cycle.

This is done efficiently because the "extension part" means the length of a cycle is computed and marked off only once.

Thus, this algorithm is O(lambda) where lambda is (Floyd's lambda i.e.) the length of the longest cycle. For this problem,
this can be at most 50000.

There are some other pathologic test cases that are worth venting too. For example, a deep chain with only a small cycle
right at the end.

Oh yes, and use optimised I/O :)



My algorithm is not very fast at all. Even adding an optimisation to mark visited nodes (which effectively only calculates
the cyclic paths once), this only gives a marginal (20% or so) increase in speed. Worryingly, removing the optimised I/O
and using scanf results in TLE.

I can't see how to make this run any faster. I've tried caching the cycle lengths but doesn't help in speeding up because
it's still necessary to calculate the m distance, so the initial cycle scan cannot be avoided. And it's in these cycle
scans that Floyd's spends most of its time.

My algorithm is linear, though.



Brian's sample input on the UVA forum is technically not quite correct because it contains an edge:

3210 3210

And the problem input description states u and v are distinct.

However, this doesn't really invalidate it as a test cast. If you were very strict in your interpretation of the 
input, your code could still get AC without stricty passing this sample. But in Brian's favour, I'd agree it is
reasonable for any sane solution to work properly even if u = v.
