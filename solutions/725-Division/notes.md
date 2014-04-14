Division
You need to spot a trick (or two) here to get the search space down to something more manageable.
Assume we want to solve A / B = D subject to the constraint, given D.
Then the minimal value for B is 01234 and the corresponding maximal value for A is obviously 98765. Solving for the maximum corresponding value of A, given D gives 98765 / B = D so the maximal value of B is 98765 / D. 
This helps reduce the search space as the value of D increases. So, initially if D = 2 then only half the values need to be searched. If D = 3,  only one third etc.
So, iterate through all the possible values of B from 1234 to (98765 / D). Trivially calculate the corresponding value of A. At this point, I created a histogram of A and B and ensure that the lexigraphical constraint is met (i.e. only one of the numbers 1-9) used. If the constraint is met, then we have a matching pair, so print it out. This will generate all possible pairs comfortably within the time limit.
