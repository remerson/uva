This problem is straightforward from an algorithm perspective but contains
several edge cases and extra conditions that are easy to get caught out
with.

Any test case with 0 is invalid. This is because the problem description
clearly states "There are not zero values."

Test cases are:

- No bicycling on the entire route. i.e. no positive maximal sum of niceness.
- No bus riding on the entire route.
- Two segments with equal maximal niceness (longest length).
- Two segments with equal maximal niceness (equal length).
- Maximum length starting or ending at the first or last stop (check proper
  initialisation of your algorithm).



