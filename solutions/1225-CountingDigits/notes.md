For each number 1..N break this down into digits. E.g. 1234 becomes

1 2 3 4

Keep a global track of counts of digits so far.

0 1 2 3 4 5 6 7 8 9 0

For each number 1..N break this down into digits. E.g. for 1234, increment the appropriate flags:

1 2 3 4

=>

0 1 1 1 1 0 0 0 0 0 0 

And sum all the flags for each digit 1..N to get the total bin count for N. This essentially mimics the manual process.
