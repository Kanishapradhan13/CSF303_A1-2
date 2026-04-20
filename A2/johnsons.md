# Question 2: Johnson's Algorithm

---

## a) Why is Johnson's faster than Floyd-Warshall for sparse graphs?

First,what does "sparse" mean:
- **Dense graph** = lots of edges (roads connecting almost every city to every other city)
- **Sparse graph** = few edges (most cities only connect to a couple of neighbours)

| Algorithm | Time Complexity |
|-----------|----------------|
| Floyd-Warshall | O(V³) |
| Johnson's | O(V² log V + VE) |


Floyd-Warshall blindly checks *every vertex against every other vertex*,
V³ times. It doesn't care if your graph has 10 edges or 10,000 edges —
it always does the same amount of work.

Johnson's Algorithm runs **Dijkstra once per vertex**. Dijkstra is smart
about sparse graphs — it only looks at edges that actually exist. So if
your graph has very few edges (small E), the VE part stays small and the
whole thing is much faster than V³.

Floyd-Warshall is like checking every seat in a stadium to find your friend. Johnson's is like only checking the seats
that have people in them.

---

## b) What is edge reweighting, and why is Bellman-Ford used?

### The Problem

Johnson's Algorithm wants to run Dijkstra — but Dijkstra **breaks with
negative edge weights**. So we need to get rid of the negative weights
without changing which path is actually the shortest.

### The Fix — Edge Reweighting

We add a new fake vertex `q` to the graph and connect it to every other
vertex with an edge of weight **0**.

Then we run **Bellman-Ford** from `q` to find the shortest distance from
`q` to every vertex. Call this value `h[v]` for each vertex `v`.

Now we **reweight** every edge `(u → v, weight w)` using this formula:

```
new_weight(u, v) = w + h[u] - h[v]
```

This formula **guarantees all new weights are non-negative** — safe for
Dijkstra — while keeping the relative ordering of paths the same, so the
shortest path doesn't change.

### Why Bellman-Ford specifically?

Because the graph might have **negative edge weights**. Dijkstra can't
handle those, but Bellman-Ford can. So we use Bellman-Ford just once at
the start to compute the `h[]` values safely.

Also, if Bellman-Ford detects a **negative cycle**, we stop immediately —
Johnson's Algorithm can't work on graphs with negative cycles, same as
Floyd-Warshall.
