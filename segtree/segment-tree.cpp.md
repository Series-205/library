---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DLS-2-A.test.cpp
    title: test/AOJ-DLS-2-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segtree/segment-tree.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// \u30E2\u30CE\u30A4\u30C9, \u6F14\u7B97, \u5358\u4F4D\u5143\
    \ntemplate <typename S, S (*op)(S, S), S (*e)()>\nclass SegmentTree {\nprivate:\n\
    \    int _n, sz;\n    vector<S> data;\n\n    void calc(int k) { data[k] = op(data[k\
    \ << 1], data[k << 1 | 1]); }\n\npublic:\n    SegmentTree() = default;\n    explicit\
    \ SegmentTree(int n) : SegmentTree(vector<S>(n, e())) {}\n    explicit SegmentTree(const\
    \ vector<S>& v) : _n(v.size()) {\n        sz = 1;\n        while(sz < _n) sz <<=\
    \ 1;\n        data.assign(sz << 1, e());\n        for(int i = 0; i < _n; i++)\
    \ data[sz + i] = v[i];\n        for(int i = sz - 1; i >= 1; i--) calc(i);\n  \
    \  }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n      \
    \  p += sz;\n        data[p] = x;\n        while(p >>= 1) calc(p);\n    }\n\n\
    \    S get(int p) {\n        assert(0 <= p && p < _n);\n        return data[p\
    \ + sz];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <= _n);\n        S sl = e(), sr = e();\n        l += sz;\n        r +=\
    \ sz;\n        while(l < r) {\n            if(l & 1) sl = op(sl, data[l++]);\n\
    \            if(r & 1) sr = op(data[--r], sr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sl, sr);\n    }\n\n    S all_prod()\
    \ { return data[1]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// \u30E2\
    \u30CE\u30A4\u30C9, \u6F14\u7B97, \u5358\u4F4D\u5143\ntemplate <typename S, S\
    \ (*op)(S, S), S (*e)()>\nclass SegmentTree {\nprivate:\n    int _n, sz;\n   \
    \ vector<S> data;\n\n    void calc(int k) { data[k] = op(data[k << 1], data[k\
    \ << 1 | 1]); }\n\npublic:\n    SegmentTree() = default;\n    explicit SegmentTree(int\
    \ n) : SegmentTree(vector<S>(n, e())) {}\n    explicit SegmentTree(const vector<S>&\
    \ v) : _n(v.size()) {\n        sz = 1;\n        while(sz < _n) sz <<= 1;\n   \
    \     data.assign(sz << 1, e());\n        for(int i = 0; i < _n; i++) data[sz\
    \ + i] = v[i];\n        for(int i = sz - 1; i >= 1; i--) calc(i);\n    }\n\n \
    \   void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += sz;\n\
    \        data[p] = x;\n        while(p >>= 1) calc(p);\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        return data[p + sz];\n    }\n\
    \n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n \
    \       S sl = e(), sr = e();\n        l += sz;\n        r += sz;\n        while(l\
    \ < r) {\n            if(l & 1) sl = op(sl, data[l++]);\n            if(r & 1)\
    \ sr = op(data[--r], sr);\n            l >>= 1;\n            r >>= 1;\n      \
    \  }\n        return op(sl, sr);\n    }\n\n    S all_prod() { return data[1];\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segment-tree.cpp
  requiredBy: []
  timestamp: '2021-04-05 19:19:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-DLS-2-A.test.cpp
documentation_of: segtree/segment-tree.cpp
layout: document
title: Segment-Tree
---

## 説明

モノイドについて区間に対する演算が出来るデータ構造

AC Library を参照のこと

TODO: 自分で書く

## 計算量

以下、モノイドの演算の時間計算量を $O(1)$ と仮定する。

- `SegmentTree(n)`: $O(n)$
- `get(p),all_prod()`: $O(1)$
- 他クエリ: $O(\log N)$