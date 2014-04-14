This is a straightforward graph traversal problem.

As the graph is a DAG, the correct solution can be obtained trivially by
choosing the edge with the largest learning value at each iteration.

Once a node is reached with no outbound edges, then the search can be
terminated.

As the given graph is guaranteed to be a DAG, it is not necessary to check
visitation explicitly.
