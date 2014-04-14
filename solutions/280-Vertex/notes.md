The input form in an adjacency list.

For each row in the adjacency list, treat this as a counted array. So, the zero'th element contains the number of elements.

I then treated this as a BFS problem. My solution is not particularly fast, though.

The algorithm for BFS is slightly modified as the starting node should not be marked as visited unless it has an edge leading to it from a accessible node. So, roughly:

- Keep an array of visited nodes.
- Keep count of how many nodes have not been visited (i.e. starts as n).
- Keep a stack of pending nodes; push on the starting node.
- While the stack isn't empty:
-- If this node has edges, then for each edge:
--- If we've not visited the target node, mark it as visited and stack
--- Decrement the count of not visited nodes.

Then: 

- Print out the count of not visited nodes.
- Iterate through the array of visited nodes and print out those not visited.

This scored 0.248 vs the best of 0.01, so it approx. 25x slower than optimal.

Optimising the I/O to reduce the number of scanf calls would probably make this a bit faster but I suspect my algorithm would need major changes to meet the fastest time. Maybe try DFS and/or some memoisation for successive queries on the same graph.

Tried an optimised I/O solution but this was even slower (!) than calling scanf repeatedly.
