# Question 5: String Matching Algorithms

## a) KMP — LPS Array for "ABABCABAB"

### What is the LPS array?

LPS stands for **Longest Proper Prefix which is also a Suffix**.

For each position in the pattern, it stores the length of the longest
part of the string (up to that point) that is both a prefix AND a suffix.

This tells KMP "how far to jump back" after a mismatch — avoiding
re-checking characters we already matched.

### Computing LPS for "ABABCABAB"

Pattern index:  `0  1  2  3  4  5  6  7  8`
Pattern chars:  `A  B  A  B  C  A  B  A  B`

| Index | Char | Longest prefix = suffix so far | LPS value |
|-------|------|-------------------------------|-----------|
| 0 | A | "" (no proper prefix possible) | 0 |
| 1 | B | no match | 0 |
| 2 | A | "A" matches prefix "A" | 1 |
| 3 | B | "AB" matches prefix "AB" | 2 |
| 4 | C | no match, reset | 0 |
| 5 | A | "A" matches prefix "A" | 1 |
| 6 | B | "AB" matches prefix "AB" | 2 |
| 7 | A | "ABA" matches prefix "ABA" | 3 |
| 8 | B | "ABAB" matches prefix "ABAB" | 4 |

### Final LPS Array

```
Pattern :  A  B  A  B  C  A  B  A  B
Index   :  0  1  2  3  4  5  6  7  8
LPS     :  0  0  1  2  0  1  2  3  4
```


---

## b) Rabin-Karp — Hash Collisions and Complexity

### How does Rabin-Karp work (in one line)?

Instead of comparing the pattern character by character, it computes a
**hash** (a number) for the pattern and slides a window across the text,
comparing hashes. Only when hashes match does it do a real character
comparison.

### What is a hash collision?

A hash collision is when **two different strings produce the same hash number**.

For example, the pattern "AB" might hash to 42, and some unrelated
substring "XY" in the text also hashes to 42. The hashes match but the
strings don't — this is a **false positive**.

### How are collisions handled?

When a hash match is found, Rabin-Karp does a **character-by-character
verification** of the actual strings to confirm it's a real match and not
a false positive.

A good hash function (large prime modulus) keeps collisions rare, so
this extra check almost never triggers.

### Time Complexity

| Case | Complexity | Why |
|------|-----------|-----|
| Average | O(N + M) | Hash comparisons are O(1), collisions are rare |
| Worst | O(N × M) | Every window causes a false positive, triggering full character check each time |

The worst case is rare in practice — it only happens with a very bad hash
function or a specially crafted adversarial input.

---

