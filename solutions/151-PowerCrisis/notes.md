This is basically a Josephus style problem. Check each value of m in turn via complete search.

Station 1 is always the first to be struck off, regardless of the value of m and the count forward is done from there.

The search can be terminated earlier as soon as station p = 13 is struck off. Then, if there are no more stations left,
the value of m is found. Otherwise, move onto the next value of m.

The upper value search for m, I have conservatively reasoned is n(n + 1)/2 i.e. sigma n as the absolute worst
case, although I think it must be lower than this and initially thought 2n but the solution for n = 39 is 84 > 2n
so this does not cover all cases. I am not sure what the lower bound is and this would need more thought but sigma n
seems to work (although intuitively feels too high).
