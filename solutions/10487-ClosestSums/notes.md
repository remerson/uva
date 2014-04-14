As detailed in this thread, the judge input contains only unique numbers.

So, cases of x + x for any given x do not need to be considered and the answer
in this case is ambiguous even for an AC solution.

However, there is another small issue. E.g.

4
7
4
10
3
1
12
0

In this case:

7 + 4 = 11

But also:

10 + 3 = 13

However, the problem description is unambigious here because it states:

"Inputs will be such that no ties will occur."

