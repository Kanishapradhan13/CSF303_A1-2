# Question 3: Arbitrage Detection in Currency Exchange
---

## a) Modelling Currency Exchange as a Weighted Directed Graph

Think of each **currency as a vertex** (node) in a graph.

Think of each **exchange rate as a directed edge** between two currencies.

For example:
- USD → EUR at rate 0.9 means: draw an arrow from USD to EUR with weight 0.9
- EUR → GBP at rate 0.8 means: draw an arrow from EUR to GBP with weight 0.8
- GBP → USD at rate 1.4 means: draw an arrow from GBP to USD with weight 1.4

```
USD --0.9--> EUR --0.8--> GBP --1.4--> USD
```

If you start with $1 and follow this cycle:
```
$1 × 0.9 × 0.8 × 1.4 = $1.008
```
You end up with more money than you started — that's **arbitrage**.

So arbitrage = a **cycle in the graph where the product of edge weights > 1**.

---

## b) Logarithmic Transformation — Turning Multiplication into Addition

### The Problem

Shortest path algorithms work with **sums** (add up edge weights).
But exchange rates work with **products** (multiply rates together).

We can't directly use Bellman-Ford on products — it only adds.

### The Fix — Use Logarithms

There's a math trick: `log(a × b) = log(a) + log(b)`

Multiplying numbers becomes **adding their logs**. So if we store
`log(rate)` as the edge weight instead of the raw rate, we can use
addition-based shortest path algorithms normally.

### Flipping the Sign

We want to **detect when a product > 1**, because that means profit.

In log terms: `log(product) > 0` means profit.

But Bellman-Ford detects **negative cycles** (where sum < 0), not positive ones.

So we flip the sign — store `-log(rate)` as the edge weight instead.

Now:
- A profitable cycle (product > 1) becomes a **negative cycle** (sum of -log values < 0)
- Detecting arbitrage = detecting a negative cycle ✓


---

## c) Which Algorithm Detects Arbitrage, and Why?

### The Algorithm: Bellman-Ford

**Bellman-Ford** is used to detect arbitrage opportunities.


### How it Works in Practice

1. Convert all exchange rates to `-log(rate)` edge weights
2. Run Bellman-Ford from any source vertex
3. Do the V-th relaxation pass
4. If any edge can still be relaxed → **negative cycle exists → arbitrage opportunity found**

---

 