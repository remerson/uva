This is a difficult problem.

There can be multiple disjoint subgraphs. So, need to find bipartite partition for each connected component.

My solution is very inefficient I think.

1) When loading in the edges, ensure you load these symmetrically (i.e. 1->2 => 2->1 even if not explicit).
2) Run DFS from all nodes and try to colour.
3) Also track the connected components of the graph while doing DFS.
4) If after DFS for node i, we have coloured the connected component for i, then check if it is bipartite. If so, add the largest colourable set to the output (i.e. max(red, black) otherwise if not bipartite then add nothing.

Originally I code this using an adjacency list which will give TLE if the graph is fully connected (N = 200). Switing to a matrix makes more sense (as symmetric) but is generally slower. This could be improved (a bit) by compressing into a bitset instead of 2D array of bool (I haven't done this) but I'm still way way off the pace. I'd guess there is much more efficient algorithm here using disjoint sets/union find (that runs in probably N A(N) rather than N^3 that my algo does).