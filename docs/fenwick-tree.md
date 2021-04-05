---
title: Fenwick-Tree
documentation_of: ../data-structure/fenwick-tree.cpp
---

## 説明

長さ $N$ の配列を管理するデータ構造

- `FenwickTree(n)`: 長さ $n$、全要素 $0$ で初期化
- `add(p, x)`: `a[p] += x` を行う
- `sum(l, r)`: `a[l] + a[l + 1] + ... + a[r - 1]` を返す

## 計算量

- `FenwickTree(n)`: $O(n)$
- クエリ: $O(\log n)$