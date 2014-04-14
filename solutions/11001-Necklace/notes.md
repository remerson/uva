Assume you have vt = u and v0 = v

Then the maximum point occurs at n = ceil (u / v) / 2

So calculate at this point (n, d0) and the point preceeding it (n-1,d1).

If d1 == d0 then there is no solution, otherwise the solution is the n value
corresponding to the max of (d0, d1).
