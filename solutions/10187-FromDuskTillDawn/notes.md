# UVa 10187 From Dusk Till Dawn

   * http://uva.onlinejudge.org/external/101/10187.html

## Categories

   * Graph
   * SSSP (BFS)
   * Non-Classical

## Approach

Use nested BFS. Use an outer BFS queue that tracks Vladimir's progress
per day (storing city and day). Then use an inner BFS queue to track
which cities are reachable "today" by paying attention to the travel
times given (storing city and time). If the destination city is reached
then record the (global) minimum number of days required to reach it. The
destination may never reached.

## Hints

   * Discard any input edges that depart before 18 or arrive after 6.
   * The sample input is simplistic.
   * The source and destination city may not be in any of the routes given.
   * Multiple routes between the source and destination city may exist. Choose
     the minimum (in days).
   * It is possible to collapse the weighted routes graph into an unweighted
     graph or use a modified Djikstra on the weighted graph (I chose the former). 
   * Routes stored as adjacency list.

## Optimisations

   * None attempted.
