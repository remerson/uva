100! is a very very large number so this cannot be calculated directly without using big number support and
would be very slow anyway.

So instead we must use some mathematical insight to speed this up.

5! = 5 x 4 x 3 x 2 x 1

So determine the prime factors for each of 2, 3, 4 etc. once up front then these can be summed to produce the
factor counts for n!.

For each n, as the upper limit is only 100 this is small/fast to do.

So:

1) Calculate primes up to 100
2) Factorise each n 2 .. 100 and count the number of prime factors for each n by trial division.
3) Then for query n, add up the factor counts from (2) above and print these out.

There is some minor outputting formatting trivia to deal with as well.
