---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DLS-2-F.test.cpp
    title: test/AOJ-DLS-2-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DLS-2-G.test.cpp
    title: test/AOJ-DLS-2-G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-range-affine-range-sum.test.cpp
    title: test/yosupo-range-affine-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lazy-segment-tree.md
    document_title: Lazy-Segment-Tree
    links: []
  bundledCode: "#line 2 \"segtree/lazy-segment-tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nclass LazySegmentTree\
    \ {\nprivate:\n    int _n, sz, lg;\n    vector<S> data;\n    vector<F> lazy;\n\
    \n    void calc(int k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n   \
    \ void all_apply(int k, F f) {\n        data[k] = mapping(f, data[k]);\n     \
    \   if(k < sz) lazy[k] = composition(f, lazy[k]);\n    }\n    void push(int k)\
    \ {\n        all_apply(k << 1, lazy[k]);\n        all_apply(k << 1 | 1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\n\npublic:\n    LazySegmentTree() = default;\n\
    \    explicit LazySegmentTree(int n) : LazySegmentTree(vector<S>(n, e())) {}\n\
    \    explicit LazySegmentTree(const vector<S>& v) : _n(v.size()) {\n        lg\
    \ = 0;\n        while((1U << lg) < (uint)_n) lg++;\n        sz = 1 << lg;\n  \
    \      data.assign(sz << 1, e());\n        lazy.assign(sz, id());\n        for(int\
    \ i = 0; i < _n; i++) data[sz + i] = v[i];\n        for(int i = sz - 1; i >= 1;\
    \ i--) calc(i);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n\
    \        data[p] = x;\n        for(int i = 1; i <= lg; i++) calc(p >> i);\n  \
    \  }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        p += sz;\n\
    \        for(int i = lg; i >= 1; i--) push(p >> i);\n        return data[p];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        if(l == r) return e();\n        l += sz;\n        r += sz;\n\n\
    \        for(int i = lg; i >= 1; i--) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push(r >> i);\n        }\n\
    \n        S sl = e(), sr = e();\n        while(l < r) {\n            if(l & 1)\
    \ sl = op(sl, data[l++]);\n            if(r & 1) sr = op(data[--r], sr);\n   \
    \         l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sl, sr);\n\
    \    }\n\n    S all_prod() { return data[1]; }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += sz;\n        for(int i = lg;\
    \ i >= 1; i--) push(p >> i);\n        data[p] = mapping(f, data[p]);\n       \
    \ for(int i = 1; i <= lg; i++) calc(p >> i);\n    }\n    void apply(int l, int\
    \ r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r)\
    \ return;\n        l += sz;\n        r += sz;\n\n        for(int i = lg; i >=\
    \ 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n            if(((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int\
    \ _l = l, _r = r;\n            while(l < r) {\n                if(l & 1) all_apply(l++,\
    \ f);\n                if(r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = _l;\n            r =\
    \ _r;\n        }\n\n        for(int i = 1; i <= lg; i++) {\n            if(((l\
    \ >> i) << i) != l) calc(l >> i);\n            if(((r >> i) << i) != r) calc((r\
    \ - 1) >> i);\n        }\n    }\n};\n/*\n * @brief Lazy-Segment-Tree\n * @docs\
    \ docs/lazy-segment-tree.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F\
    \ (*composition)(F, F), F (*id)()>\nclass LazySegmentTree {\nprivate:\n    int\
    \ _n, sz, lg;\n    vector<S> data;\n    vector<F> lazy;\n\n    void calc(int k)\
    \ { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n    void all_apply(int k,\
    \ F f) {\n        data[k] = mapping(f, data[k]);\n        if(k < sz) lazy[k] =\
    \ composition(f, lazy[k]);\n    }\n    void push(int k) {\n        all_apply(k\
    \ << 1, lazy[k]);\n        all_apply(k << 1 | 1, lazy[k]);\n        lazy[k] =\
    \ id();\n    }\n\npublic:\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(int\
    \ n) : LazySegmentTree(vector<S>(n, e())) {}\n    explicit LazySegmentTree(const\
    \ vector<S>& v) : _n(v.size()) {\n        lg = 0;\n        while((1U << lg) <\
    \ (uint)_n) lg++;\n        sz = 1 << lg;\n        data.assign(sz << 1, e());\n\
    \        lazy.assign(sz, id());\n        for(int i = 0; i < _n; i++) data[sz +\
    \ i] = v[i];\n        for(int i = sz - 1; i >= 1; i--) calc(i);\n    }\n\n   \
    \ void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += sz;\n\
    \        for(int i = lg; i >= 1; i--) push(p >> i);\n        data[p] = x;\n  \
    \      for(int i = 1; i <= lg; i++) calc(p >> i);\n    }\n\n    S get(int p) {\n\
    \        assert(0 <= p && p < _n);\n        p += sz;\n        for(int i = lg;\
    \ i >= 1; i--) push(p >> i);\n        return data[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r)\
    \ return e();\n        l += sz;\n        r += sz;\n\n        for(int i = lg; i\
    \ >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n         \
    \   if(((r >> i) << i) != r) push(r >> i);\n        }\n\n        S sl = e(), sr\
    \ = e();\n        while(l < r) {\n            if(l & 1) sl = op(sl, data[l++]);\n\
    \            if(r & 1) sr = op(data[--r], sr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sl, sr);\n    }\n\n    S all_prod()\
    \ { return data[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n\
    \        data[p] = mapping(f, data[p]);\n        for(int i = 1; i <= lg; i++)\
    \ calc(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if(l == r) return;\n        l += sz;\n\
    \        r += sz;\n\n        for(int i = lg; i >= 1; i--) {\n            if(((l\
    \ >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n\n        {\n            int _l = l, _r = r;\n     \
    \       while(l < r) {\n                if(l & 1) all_apply(l++, f);\n       \
    \         if(r & 1) all_apply(--r, f);\n                l >>= 1;\n           \
    \     r >>= 1;\n            }\n            l = _l;\n            r = _r;\n    \
    \    }\n\n        for(int i = 1; i <= lg; i++) {\n            if(((l >> i) <<\
    \ i) != l) calc(l >> i);\n            if(((r >> i) << i) != r) calc((r - 1) >>\
    \ i);\n        }\n    }\n};\n/*\n * @brief Lazy-Segment-Tree\n * @docs docs/lazy-segment-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: segtree/lazy-segment-tree.cpp
  requiredBy: []
  timestamp: '2021-06-23 20:37:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-range-affine-range-sum.test.cpp
  - test/AOJ-DLS-2-G.test.cpp
  - test/AOJ-DLS-2-F.test.cpp
documentation_of: segtree/lazy-segment-tree.cpp
layout: document
redirect_from:
- /library/segtree/lazy-segment-tree.cpp
- /library/segtree/lazy-segment-tree.cpp.html
title: Lazy-Segment-Tree
---
## 説明

TODO: 書く

## 計算量

- コンストラクタ: $O(n)$
- `all_prod()`: $O(1)$
- 他クエリ: $O(\log n)$