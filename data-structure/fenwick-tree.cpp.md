---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DLS-2-B.test.cpp
    title: test/AOJ-DLS-2-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/fenwick-tree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename T>\nclass FenwickTree {\nprivate:\n\
    \    int _n;\n    vector<T> data;\n\n    T sum(int r) {\n        T s = 0;\n  \
    \      while(r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n\
    \        }\n        return s;\n    }\n\npublic:\n    FenwickTree() = default;\n\
    \    FenwickTree(int n) : _n(n), data(n) {}\n\n    void add(int p, T x) {\n  \
    \      assert(0 <= p && p < _n);\n        p++;\n        while(p <= _n) {\n   \
    \         data[p - 1] += x;\n            p += p & -p;\n        }\n    }\n\n  \
    \  T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n     \
    \   return sum(r) - sum(l);\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\nclass FenwickTree {\nprivate:\n    int _n;\n    vector<T> data;\n\
    \n    T sum(int r) {\n        T s = 0;\n        while(r > 0) {\n            s\
    \ += data[r - 1];\n            r -= r & -r;\n        }\n        return s;\n  \
    \  }\n\npublic:\n    FenwickTree() = default;\n    FenwickTree(int n) : _n(n),\
    \ data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n\
    \        p++;\n        while(p <= _n) {\n            data[p - 1] += x;\n     \
    \       p += p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick-tree.cpp
  requiredBy: []
  timestamp: '2021-04-05 18:55:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-DLS-2-B.test.cpp
documentation_of: data-structure/fenwick-tree.cpp
layout: document
title: Fenwick-Tree
---

## 説明

長さ $N$ の配列を管理するデータ構造

- `FenwickTree(n)`: 長さ $n$、全要素 $0$ で初期化
- `add(p, x)`: `a[p] += x` を行う
- `sum(l, r)`: `a[l] + a[l + 1] + ... + a[r - 1]` を返す

## 計算量

- `FenwickTree(n)`: $O(n)$
- クエリ: $O(\log n)$