This is quite tricky and my solution is not great.

This goes down the path of attempting to find the LCM via successive GCD guesses.

An initial guess is chosen by looking at b = GCD(a, c) / c which gives a possible starting
value for b. This can then be solved by testing increasing muliples of b until LCM(a, b)
equals c. But this is slow and expensive (in terms of GCD calculations which dominate
this method). The first solution (solution.cpp) uses this approach but will probably give
TLE because of excessive GCD calculations.

The actual solution using this approach usually lies at the b'th iteration
(i.e. where b = GCD(a, c) / c) ) but not if there is a shared factor, in which case the
solution lies at a higher multiple of b. So, the approach of chosing an initial b as
(effectively) b squared cuts out a lot of obviously wrong answers and in many cases will
directly converge on the answer. In the case where it does not, chosing muliples of b
squared obviously cuts out a lot of excess GCD calculations although still can require
quite a few GCD calculations to converge (although typically a few times less than the
pure brute force approach). This is in solution3.cpp. This can do 100k input size in
about 3 seconds, so is slow but (hopefully) will pass the time limit of 5 seconds. The
drawback to this "power scanning" approach is that the GCD calculations get progressively
slower as the powers rise, so if there are very deep factors, then TLE is still a potential
problem... in fact, not even potentially - it is, and this solution received TLE.

Although I've not studied it in great depth, I think the reference solution uses direct
factorisation, which is about an order of magnitude faster than my approach (about 300ms
on the same input).

This solution counts the number of each prime factor of a and c to work out what the
intersection (common) factors are - this directly determines the value of b.

So, this direct factorisation approach is needed.


OK... so my solution7.cpp implements directly factoring to find b.

There are several (performance) enhancements worthy of note:

- I think when sieving, it's only necessary to go up to sqrt(10^7) ~= 3200 because each
  n (a, b or c) only has at most one (prime) factor > sqrt(n). This cuts down on the sieve
  generation time a lot.

- Powers of 2 are treated as a special case when factoring out. Use shifting for these
  instead of % * / gives a modest performance boost.

- Input buffered reader.

- Output buffered writer.

The buffered I/O (particularly output) needs quite a lot of memory (1.5Mb or so), so this
is at risk of MLE but I think the whole program comfortably fits inside 16Mb total.