This is a simple greedy problem that can be solved by sorting. It is not necessary to calculate the minimal fine amount.

Read the job data in and store 3 values for each job:

-	Time
-	Fine
-	Position (1-indexed)

Write a custom compare function that checks whether one job is less than an another (to define an ordering).

When comparing two jobs x and y, x should come before y if the fine per unit time of x is greater than y. This approach will minimise the accrued fine because it ensures that the most costly jobs (fine cost per unit of time) are always ordered first. If a more costly job appears later, then it cannot be optimal because it could be moved forward to reduce the amount of fine paid overall.

That is:

Fine(x) / Time(x) > Fine(y) / Time(y)

This can be rearranged to avoid division (and hence double values) as:

Fine(x) * Time(y) > Fine(y) * Time(x)

Obviously if:

Fine(x) * Time(y) < Fine(y) * Time(x)

Then the ordering is inverted. If there is equality then the problem statement says the ordering should be dictated by position instead.

Sort the values using this custom comparison function and print the (position) result.
