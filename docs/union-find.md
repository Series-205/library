---
title: Union-Find
documentation_of: ../data-structure/union-find.cpp
---

## 説明

集合を扱うデータ構造

- `unite(x, y)`: 集合 `x` と `y` を併合する。未併合か否かを `bool` 値で返す。
- `find(x)`: 要素 `x` が属する集合を求める。
- `size(x)`: 要素 `x` が属する集合の要素数を求める。
- `same(x, y)`: 要素 `x,y` が同じ集合に属するか判定する。
