---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/segment-tree.cpp
    title: Segment-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo-point-set-range-composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"segtree/segment-tree.cpp\"\
    \nusing namespace std;\n\n// \u30E2\u30CE\u30A4\u30C9, \u6F14\u7B97, \u5358\u4F4D\
    \u5143\ntemplate <typename S, S (*op)(S, S), S (*e)()>\nclass SegmentTree {\n\
    private:\n    int _n, sz;\n    vector<S> data;\n\n    void calc(int k) { data[k]\
    \ = op(data[k << 1], data[k << 1 | 1]); }\n\npublic:\n    SegmentTree() = default;\n\
    \    explicit SegmentTree(int n) : SegmentTree(vector<S>(n, e())) {}\n    explicit\
    \ SegmentTree(const vector<S>& v) : _n(v.size()) {\n        sz = 1;\n        while(sz\
    \ < _n) sz <<= 1;\n        data.assign(sz << 1, e());\n        for(int i = 0;\
    \ i < _n; i++) data[sz + i] = v[i];\n        for(int i = sz - 1; i >= 1; i--)\
    \ calc(i);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += sz;\n        data[p] = x;\n        while(p >>= 1) calc(p);\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        return\
    \ data[p + sz];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sl = e(), sr = e();\n        l += sz;\n     \
    \   r += sz;\n        while(l < r) {\n            if(l & 1) sl = op(sl, data[l++]);\n\
    \            if(r & 1) sr = op(data[--r], sr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sl, sr);\n    }\n\n    S all_prod()\
    \ { return data[1]; }\n};\n/*\n * @brief Segment-Tree\n * @docs docs/segment-tree.md\n\
    \ */\n#line 7 \"test/yosupo-point-set-range-composite.test.cpp\"\n\nconstexpr\
    \ int mod = 998244353;\n\nstruct S {\n    int64_t a, b;\n    int64_t calc(int64_t\
    \ x) { return (a * x + b) % mod; }\n};\n\ninline S op(S l, S r) { return S{r.a\
    \ * l.a % mod, (r.a * l.b + r.b) % mod}; }\ninline S e() { return S{1, 0}; }\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n  \
    \  int n, q;\n    cin >> n >> q;\n    vector<S> v;\n    v.reserve(n);\n\n    for(int\
    \ i = 0; i < n; i++) {\n        int a, b;\n        cin >> a >> b;\n        v.push_back(S{a,\
    \ b});\n    }\n\n    SegmentTree<S, op, e> seg(v);\n\n    for(int i = 0; i < q;\
    \ i++) {\n        int a, b, c, d;\n        cin >> a >> b >> c >> d;\n        if(a)\n\
    \            cout << seg.prod(b, c).calc(d) << \"\\n\";\n        else\n      \
    \      seg.set(b, S{c, d});\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../segtree/segment-tree.cpp\"\
    \n\nconstexpr int mod = 998244353;\n\nstruct S {\n    int64_t a, b;\n    int64_t\
    \ calc(int64_t x) { return (a * x + b) % mod; }\n};\n\ninline S op(S l, S r) {\
    \ return S{r.a * l.a % mod, (r.a * l.b + r.b) % mod}; }\ninline S e() { return\
    \ S{1, 0}; }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    cin >> n >> q;\n    vector<S> v;\n    v.reserve(n);\n\n \
    \   for(int i = 0; i < n; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        v.push_back(S{a, b});\n    }\n\n    SegmentTree<S, op, e> seg(v);\n\n\
    \    for(int i = 0; i < q; i++) {\n        int a, b, c, d;\n        cin >> a >>\
    \ b >> c >> d;\n        if(a)\n            cout << seg.prod(b, c).calc(d) << \"\
    \\n\";\n        else\n            seg.set(b, S{c, d});\n    }\n\n    return 0;\n\
    }"
  dependsOn:
  - segtree/segment-tree.cpp
  isVerificationFile: true
  path: test/yosupo-point-set-range-composite.test.cpp
  requiredBy: []
  timestamp: '2021-04-08 20:15:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-point-set-range-composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-point-set-range-composite.test.cpp
- /verify/test/yosupo-point-set-range-composite.test.cpp.html
title: test/yosupo-point-set-range-composite.test.cpp
---
