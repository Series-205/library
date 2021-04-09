---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/lazy-segment-tree.cpp
    title: segtree/lazy-segment-tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/AOJ-DLS-2-G.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"segtree/lazy-segment-tree.cpp\"\
    \nusing namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F,\
    \ S (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nclass LazySegmentTree\
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
    \    }\n\n    S all_prod() { return data[1]; }\n\n    void apply(int p, F f) {\
    \ set(p, mapping(f, data[p])); }\n    void apply(int l, int r, F f) {\n      \
    \  assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return;\n        l\
    \ += sz;\n        r += sz;\n\n        for(int i = lg; i >= 1; i--) {\n       \
    \     if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) !=\
    \ r) push((r - 1) >> i);\n        }\n\n        {\n            int _l = l, _r =\
    \ r;\n            while(l < r) {\n                if(l & 1) all_apply(l++, f);\n\
    \                if(r & 1) all_apply(--r, f);\n                l >>= 1;\n    \
    \            r >>= 1;\n            }\n            l = _l;\n            r = _r;\n\
    \        }\n\n        for(int i = 1; i <= lg; i++) {\n            if(((l >> i)\
    \ << i) != l) calc(l >> i);\n            if(((r >> i) << i) != r) calc((r - 1)\
    \ >> i);\n        }\n    }\n};\n#line 8 \"test/AOJ-DLS-2-G.test.cpp\"\n\nstruct\
    \ S {\n    int64_t val;\n    int sz;\n};\nS op(S l, S r) { return S{l.val + r.val,\
    \ l.sz + r.sz}; }\nS e() { return S{0, 0}; }\n\nusing F = int64_t;\nS mapping(F\
    \ f, S s) { return S{s.val + f * s.sz, s.sz}; }\nF composition(F f, F g) { return\
    \ f + g; }\nF id() { return 0; }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    cin >> n >> q;\n\n    LazySegmentTree<S, op, e, F, mapping,\
    \ composition, id> seg(\n        vector<S>(n, S{0, 1}));\n\n    for(int i = 0;\
    \ i < q; i++) {\n        int c;\n        cin >> c;\n        if(c) {\n        \
    \    int l, r;\n            cin >> l >> r;\n            cout << seg.prod(l - 1,\
    \ r).val << \"\\n\";\n        } else {\n            int l, r, x;\n           \
    \ cin >> l >> r >> x;\n            seg.apply(l - 1, r, x);\n        }\n    }\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../segtree/lazy-segment-tree.cpp\"\
    \n\nstruct S {\n    int64_t val;\n    int sz;\n};\nS op(S l, S r) { return S{l.val\
    \ + r.val, l.sz + r.sz}; }\nS e() { return S{0, 0}; }\n\nusing F = int64_t;\n\
    S mapping(F f, S s) { return S{s.val + f * s.sz, s.sz}; }\nF composition(F f,\
    \ F g) { return f + g; }\nF id() { return 0; }\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q;\n    cin >> n >> q;\n\n   \
    \ LazySegmentTree<S, op, e, F, mapping, composition, id> seg(\n        vector<S>(n,\
    \ S{0, 1}));\n\n    for(int i = 0; i < q; i++) {\n        int c;\n        cin\
    \ >> c;\n        if(c) {\n            int l, r;\n            cin >> l >> r;\n\
    \            cout << seg.prod(l - 1, r).val << \"\\n\";\n        } else {\n  \
    \          int l, r, x;\n            cin >> l >> r >> x;\n            seg.apply(l\
    \ - 1, r, x);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - segtree/lazy-segment-tree.cpp
  isVerificationFile: true
  path: test/AOJ-DLS-2-G.test.cpp
  requiredBy: []
  timestamp: '2021-04-09 12:12:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DLS-2-G.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DLS-2-G.test.cpp
- /verify/test/AOJ-DLS-2-G.test.cpp.html
title: test/AOJ-DLS-2-G.test.cpp
---
