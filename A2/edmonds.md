# Question 4: Edmonds' Algorithm

## What Problem Does It Solve?

Edmonds' Algorithm solves
the **Minimum Spanning Arborescence** problem.


> Given a **directed** graph and a chosen root vertex, find the cheapest

> set of directed edges such that every other vertex can be reached from

> the root — with minimum total edge weight.

---


## Precise Problem Statement

**Given:**
- A weighted directed graph with V vertices and E edges
- A designated root vertex `r`

**Find:**
- A set of directed edges forming a tree rooted at `r`
- Where every vertex is reachable from `r`
- With the **minimum possible total weight**

**Complexity:** O(VE) with basic implementation, O(E log V) with priority queues.

---

## Key Idea in One Line

> At each vertex (except root), pick the **cheapest incoming edge**,

> then shrink any cycles that form and repeat — until a valid tree is built.