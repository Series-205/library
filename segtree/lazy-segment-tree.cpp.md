---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segtree/lazy-segment-tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nclass LazySegmentTree\
    \ {\nprivate:\n    int _n, sz, lg;\n    vector<S> data;\n    vector<F> lazy;\n\
    \n    void calc(int k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n   \
    \ void all_apply(int k, F f) {\n        data[k] = mapping(f, data[k]);\n     \
    \   if(k < sz) lazy[k] = compopsition(f, lazy[k]);\n    }\n    void push(int k)\
    \ {\n        all_apply(k << 1, lazy[k]);\n        all_apply(k << 1 | 1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\n\npublic:\n    LazySegmentTree() = default;\n\
    \    explicit LazySegmentTree(int n) : LazySegmentTree(vector<S>(n, e())) {}\n\
    \    explicit LazySegmentTree(const vector<S>& v) : _n(v.size()) {\n        lg\
    \ = 0;\n        while((1U << log) < (uint)_n) lg++;\n        sz = 1 << lg;\n \
    \       data.assign(sz << 1, e());\n        lazy.assign(sz, id());\n        for(int\
    \ i = 0; i < _n; i++) data[sz + i] = v[i];\n        for(int i = sz - 1; i >= 1;\
    \ i--) calc(i);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n\
    \        data[p] = x;\n        for(int i = 1; i <= lg; i++) calc(p >> i);\n  \
    \  }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        p += sz;\n\
    \        for(int i = lg; i >= 1; i--) push(p >> i);\n        return data[p];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        if(l == r) return e();\n        l += sz;\n        r += sz;\n\n\
    \        int i = lg;\n        while(((l >> i) << i) != l) {\n            push(l\
    \ >> i);\n            i--;\n        }\n        int j = lg;\n        while(((l\
    \ ^ r) >> j) == 0) j--;\n        while(((r >> j) << j) != r) {\n            push(r\
    \ >> j);\n            j--;\n        }\n\n        S sl = e(), sr = e();\n     \
    \   while(l < r) {\n            if(l & 1) sl = op(sl, data[l++]);\n          \
    \  if(r & 1) sr = op(data[--r], sr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n\n        return op(sl, sr);\n    }\n\n    S all_prod() { return\
    \ data[1]; }\n\n    void apply(int p, F f) { set(p, mapping(f, data[p])); }\n\
    \    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        if(l == r) return;\n        l += sz;\n        r += sz;\n\n   \
    \     int i = lg;\n        while(((l >> i) << i) != l) {\n            push(l >>\
    \ i);\n            i--;\n        }\n        int j = lg;\n        while(((l ^ r)\
    \ >> j) == 0) j--;\n        int k = j;\n        while(((r >> j) << j) != r) {\n\
    \            push(r >> j);\n            j--;\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while(l < r) {\n                if(l &\
    \ 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r, f);\n      \
    \          l >>= 1;\n                r >>= 1;\n            }\n            l =\
    \ l2;\n            r = r2;\n        }\n\n        for(j++; j <= k; j++) calc(r\
    \ >> j);\n        for(i++; i <= lg; i++) calc(l >> i);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F\
    \ (*composition)(F, F), F (*id)()>\nclass LazySegmentTree {\nprivate:\n    int\
    \ _n, sz, lg;\n    vector<S> data;\n    vector<F> lazy;\n\n    void calc(int k)\
    \ { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n    void all_apply(int k,\
    \ F f) {\n        data[k] = mapping(f, data[k]);\n        if(k < sz) lazy[k] =\
    \ compopsition(f, lazy[k]);\n    }\n    void push(int k) {\n        all_apply(k\
    \ << 1, lazy[k]);\n        all_apply(k << 1 | 1, lazy[k]);\n        lazy[k] =\
    \ id();\n    }\n\npublic:\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(int\
    \ n) : LazySegmentTree(vector<S>(n, e())) {}\n    explicit LazySegmentTree(const\
    \ vector<S>& v) : _n(v.size()) {\n        lg = 0;\n        while((1U << log) <\
    \ (uint)_n) lg++;\n        sz = 1 << lg;\n        data.assign(sz << 1, e());\n\
    \        lazy.assign(sz, id());\n        for(int i = 0; i < _n; i++) data[sz +\
    \ i] = v[i];\n        for(int i = sz - 1; i >= 1; i--) calc(i);\n    }\n\n   \
    \ void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += sz;\n\
    \        for(int i = lg; i >= 1; i--) push(p >> i);\n        data[p] = x;\n  \
    \      for(int i = 1; i <= lg; i++) calc(p >> i);\n    }\n\n    S get(int p) {\n\
    \        assert(0 <= p && p < _n);\n        p += sz;\n        for(int i = lg;\
    \ i >= 1; i--) push(p >> i);\n        return data[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r)\
    \ return e();\n        l += sz;\n        r += sz;\n\n        int i = lg;\n   \
    \     while(((l >> i) << i) != l) {\n            push(l >> i);\n            i--;\n\
    \        }\n        int j = lg;\n        while(((l ^ r) >> j) == 0) j--;\n   \
    \     while(((r >> j) << j) != r) {\n            push(r >> j);\n            j--;\n\
    \        }\n\n        S sl = e(), sr = e();\n        while(l < r) {\n        \
    \    if(l & 1) sl = op(sl, data[l++]);\n            if(r & 1) sr = op(data[--r],\
    \ sr);\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ op(sl, sr);\n    }\n\n    S all_prod() { return data[1]; }\n\n    void apply(int\
    \ p, F f) { set(p, mapping(f, data[p])); }\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return;\n\
    \        l += sz;\n        r += sz;\n\n        int i = lg;\n        while(((l\
    \ >> i) << i) != l) {\n            push(l >> i);\n            i--;\n        }\n\
    \        int j = lg;\n        while(((l ^ r) >> j) == 0) j--;\n        int k =\
    \ j;\n        while(((r >> j) << j) != r) {\n            push(r >> j);\n     \
    \       j--;\n        }\n\n        {\n            int l2 = l, r2 = r;\n      \
    \      while(l < r) {\n                if(l & 1) all_apply(l++, f);\n        \
    \        if(r & 1) all_apply(--r, f);\n                l >>= 1;\n            \
    \    r >>= 1;\n            }\n            l = l2;\n            r = r2;\n     \
    \   }\n\n        for(j++; j <= k; j++) calc(r >> j);\n        for(i++; i <= lg;\
    \ i++) calc(l >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segtree/lazy-segment-tree.cpp
  requiredBy: []
  timestamp: '2021-04-08 23:43:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/lazy-segment-tree.cpp
layout: document
redirect_from:
- /library/segtree/lazy-segment-tree.cpp
- /library/segtree/lazy-segment-tree.cpp.html
title: segtree/lazy-segment-tree.cpp
---
