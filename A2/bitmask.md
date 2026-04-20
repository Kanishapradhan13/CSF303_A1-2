# Question 1: Bitmasking

## Sample Input / Output

```
4
3 1 4 2
3

Count: 4
```

Subsets with sum divisible by 3: `{}`, `{3}`, `{1,2}`, `{3,1,2}` → sums 0, 3, 3, 6.

---

## Analysis

### The Bitmask Idea

With N elements, there are 2^N possible subsets. A **bitmask** is just an
integer where each bit represents whether an element is included (1) or
not (0).

For example with N=3, the mask `101` in binary means "take element 0 and
element 2, skip element 1."

We loop from `mask = 0` (empty set) to `mask = 2^N - 1` (full set),
covering every possible subset exactly once.

### Complexity

| Type | Value |
|------|-------|
| Time | O(2^N × N) |
| Space | O(N) |

N ≤ 20 means at most 2^20 × 20 ≈ 20 million operations — fast enough.

### Key Line Explained

```cpp
if (mask & (1 << i))
```

`1 << i` creates a number with only the i-th bit ON.
`mask & (1 << i)` checks if that bit is ON in the current mask.
If yes, element i is part of this subset.

### Corner Cases

| Case | Handled? |
|------|---------|
| Empty subset (mask = 0) | Sum = 0, counted if K divides 0 |
| N = 1 | Works fine, 2 subsets checked |
| All elements divisible by K | All non-empty subsets counted |