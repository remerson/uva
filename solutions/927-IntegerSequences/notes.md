I don't follow the sample I/O:

4 3 0 0 0 23

d = 25

a(n) = 4 + 3n + 0n2 + 0n3 + 0n4 +23n5 = 4 + 3n + 23n^5

For n = 1:

a(1) = 4 + 3 + 23 = 30

For d = 25 times.

For n = 2:

a(2) = 4 + 6 + 23*32 = 10 + 736 = 746

For 2d = 50 times.

For n = 3:

a(3) = 4 + 9 + 0 + 0 + 0 + 23*243 = 13 + 5589 = 5602

For 3d = 75 times.

So, the k = 100th element should be 5602 but the correct answer is given as 1866 (!?). 

What am I missing?


For:

1 0 1

This is:

a(n) = 1 + 0n + 1n^2 = 1 + n^2


For n = 1:

a(1) = 2

For d = 1 times.

For n = 2:

a(2) = 5;

For 2d = 2 times.

a(3) = 10;

For 3d = 3 times

So here the sequence is:

1,5,5,10,10,10

And k = 6th value is 10.

So again, where does the answer given of 6 come from? To me, it seems that it does not appear in the sequence at all.


I am clearly not understanding something very basic here!!




23n^4


n = 1

a(1) = 23


a(2) = 23*16 = 368

a(3) = 






I found the input format quite confusing for this problem.

It would be a lot easier to say:

"The first line contains: i the degree of the polynomial, followed by the constant value c0 and then i values matching the coefficients of
c1,c2,...,ci"

I found the "j = 0" part really confusing because j is not mentioned anywhere else in the problem description. Why not just say "c0"?




