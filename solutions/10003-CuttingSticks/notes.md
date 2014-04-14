Cutting Sticks

The key trick here is forming the recurrance relation solution and framing how this solution works properly.
We have an array containing the cut points to made. Implicitly this is also extended out at the bottom to 0 and at at the top, up to length. E.g. points:
0 25 50 75 100
So there are 5 points in total.
Assume always we are choosing two indices in this array to cut between - L and R. Remember that L and R are indices into this points array. So, when starting out, the initial cut is between 0 and 100, then later on, some choices might be to cut between 25 and 100 or 50 and 75. This is cutting process is what we want to enumerate.
So, we will start with cutting the range from 0 to 100 and then recursively enumerate all sub-divided cuts inside the interval to determine the overall minimal cost. Something like this:
left = 0, right = 100
a)	L				R
	0 	25 	50 	75 	100
b)	L	*			R
	0 	25 	50 	75 	100
c)	L		*		R
	0 	25 	50 	75 	100
d)	L			*	R
	0 	25 	50 	75 	100
Each time, we want to calculate the cost for L, R plus the minimal cost between L and the asterisk *. More conventionally, this is for-loop, running from each element L to (R-1).
This is a top-down approach - we start with the largest interval and then define how to cost the smaller contained intervals.
This is helping to give an abstract formulation of how we the DP will work, particularly what each state is an how to build each state. There are two values here that determine the state (i.e. cost): the L and R cut points made.
Our base case here is when L and R are adjacent. Then both of the desired cuts have already been made and the cost will be zero. Hence, cost(left, left + 1) = 0
To obtain the global minimum, it is necessary to enumerate all L, R combinations. This is quadratic.
Finally, now that the state has been formulated, we must not forget the important "magic trick" of DP - use memoization for each cost[L, R] calculated.
We end up with something like this:
1) if(L + 1 == R) then cost[L, R] = 0
2) Otherwise, cost[L, R] = min(cost[L, R], (points[R] - points[L]) + cut(L, i) + cut(i, R)) across all i, L < i < R
3) Ensure cost[L, R] is memoized
The global minimum resides in cost[0, N].
