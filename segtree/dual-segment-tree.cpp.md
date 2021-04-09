---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DLS-2-D.test.cpp
    title: test/AOJ-DLS-2-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dual-segment-tree.md
    document_title: Dual-Segment-Tree
    links: []
  bundledCode: "#line 2 \"segtree/dual-segment-tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F),\n          F (*id)()>\nclass DualSegmentTree {\n    int _n, sz, lg;\n  \
    \  vector<S> data;\n    vector<F> lazy;\n\n    void _push(int k, F f) {\n    \
    \    if(k < sz)\n            lazy[k] = composition(f, lazy[k]);\n        else\n\
    \            data[k - sz] = mapping(f, data[k - sz]);\n    }\n    void push(int\
    \ k) {\n        _push(k << 1, lazy[k]);\n        _push(k << 1 | 1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\n\npublic:\n    DualSegmentTree() = default;\n\
    \    explicit DualSegmentTree(const vector<S>& v) : _n(v.size()) {\n        lg\
    \ = 0;\n        while(1U << lg < (uint)_n) lg++;\n        sz = 1 << lg;\n    \
    \    data = v;\n        data.resize(sz);\n        lazy.assign(sz, id());\n   \
    \ }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n       \
    \ p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n        data[p\
    \ - sz] = x;\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n      \
    \  return data[p - sz];\n    }\n\n    void apply(int p, F f) {\n        assert(0\
    \ <= p && p < _n);\n        p += sz;\n        for(int i = lg; i >= 1; i--) push(p\
    \ >> i);\n        data[p - sz] = mapping(f, data[p]);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l\
    \ == r) return;\n        l += sz;\n        r += sz;\n\n        for(int i = lg;\
    \ i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n       \
    \     if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        while(l\
    \ < r) {\n            if(l & 1) _push(l++, f);\n            if(r & 1) _push(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n};\n/*\n\
    \ * @brief Dual-Segment-Tree\n * @docs docs/dual-segment-tree.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, class F, S (*mapping)(F, S), F (*composition)(F, F),\n          F\
    \ (*id)()>\nclass DualSegmentTree {\n    int _n, sz, lg;\n    vector<S> data;\n\
    \    vector<F> lazy;\n\n    void _push(int k, F f) {\n        if(k < sz)\n   \
    \         lazy[k] = composition(f, lazy[k]);\n        else\n            data[k\
    \ - sz] = mapping(f, data[k - sz]);\n    }\n    void push(int k) {\n        _push(k\
    \ << 1, lazy[k]);\n        _push(k << 1 | 1, lazy[k]);\n        lazy[k] = id();\n\
    \    }\n\npublic:\n    DualSegmentTree() = default;\n    explicit DualSegmentTree(const\
    \ vector<S>& v) : _n(v.size()) {\n        lg = 0;\n        while(1U << lg < (uint)_n)\
    \ lg++;\n        sz = 1 << lg;\n        data = v;\n        data.resize(sz);\n\
    \        lazy.assign(sz, id());\n    }\n\n    void set(int p, S x) {\n       \
    \ assert(0 <= p && p < _n);\n        p += sz;\n        for(int i = lg; i >= 1;\
    \ i--) push(p >> i);\n        data[p - sz] = x;\n    }\n\n    S get(int p) {\n\
    \        assert(0 <= p && p < _n);\n        p += sz;\n        for(int i = lg;\
    \ i >= 1; i--) push(p >> i);\n        return data[p - sz];\n    }\n\n    void\
    \ apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p += sz;\n \
    \       for(int i = lg; i >= 1; i--) push(p >> i);\n        data[p - sz] = mapping(f,\
    \ data[p]);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l\
    \ && l <= r && r <= _n);\n        if(l == r) return;\n        l += sz;\n     \
    \   r += sz;\n\n        for(int i = lg; i >= 1; i--) {\n            if(((l >>\
    \ i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n        }\n\n        while(l < r) {\n            if(l & 1) _push(l++,\
    \ f);\n            if(r & 1) _push(--r, f);\n            l >>= 1;\n          \
    \  r >>= 1;\n        }\n    }\n};\n/*\n * @brief Dual-Segment-Tree\n * @docs docs/dual-segment-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: segtree/dual-segment-tree.cpp
  requiredBy: []
  timestamp: '2021-04-09 16:57:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-DLS-2-D.test.cpp
documentation_of: segtree/dual-segment-tree.cpp
layout: document
redirect_from:
- /library/segtree/dual-segment-tree.cpp
- /library/segtree/dual-segment-tree.cpp.html
title: Dual-Segment-Tree
---
## TODO

交換則が成り立たなくても OK なようにする

## 説明

双対セグ木

区間更新と一点取得が可能

## 計算量

- 初期化: $O(n)$
- クエリ: $O(\log n)$