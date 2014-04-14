This is the Extended Euclidean Algorithm.

I'm having trouble with the ordering of a, b and the coefficents.

The problem description clear states that X < Y when outputting but the reference test cases from the OJ Board do not follow this (neither does the reference solutions I found). I am struggling to figure out how to do this ordering properly as it is not as straightforward as just X < Y.

In fact, if you take one of the problem cases, my algorithm is correct where A < B but not when B < A. Flipping the coeffients around doesn't help here either, so there is something more fundamentally wrong with the approach...

Needs a base case for when X (or Y) is zero - this should always be first.

Consider the case where one of X or Y or zero. In this case, the answer should be output in the form 0 + (X|Y) rather than (X|Y) + 0.
