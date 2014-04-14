This requires a small amount of intuition to rearrange the given equation into something more directly useful.

Essentially, this is complete search but constrained.

The initial value of x will always be k + 1 and from this you can rearrange:

1 / k = 1 / x  +  1 / y

To give the direct value of y (given x), that is:

y = (x * k) / (x - k)

So, starting with x = k + 1, check the corresponding value of y and see if the main equation holds. If it does,
then this is a valid solution, so store (and count) it. The value of y here will always satisfy (i.e. there is
at least one such x, y and x = k + 1).

Then try x = x + 1 and again find the new corresponding value of y and check if the main equation holds. In this,
the general case, the value of y may not hold. If not, then try the next x = x + 1 etc. or otherwise, if the
equation does hold, then store (and count it).

Counting up of x in this way continues until x == y. This is always the final pair.

At the end, write out the count and the value pairs stored.
