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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/AOJ-DLS-2-A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"segtree/segment-tree.cpp\"\
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
    \ */\n#line 7 \"test/AOJ-DLS-2-A.test.cpp\"\n\nint op(int a, int b) { return min(a,\
    \ b); }\nint e() { return (1LL << 31) - 1; }\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n\n    SegmentTree<int, op, e> seg(n);\n\n    for(int i =\
    \ 0; i < q; i++) {\n        int c, x, y;\n        cin >> c >> x >> y;\n      \
    \  if(c)\n            cout << seg.prod(x, y + 1) << \"\\n\";\n        else\n \
    \           seg.set(x, y);\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../segtree/segment-tree.cpp\"\
    \n\nint op(int a, int b) { return min(a, b); }\nint e() { return (1LL << 31) -\
    \ 1; }\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\n    SegmentTree<int,\
    \ op, e> seg(n);\n\n    for(int i = 0; i < q; i++) {\n        int c, x, y;\n \
    \       cin >> c >> x >> y;\n        if(c)\n            cout << seg.prod(x, y\
    \ + 1) << \"\\n\";\n        else\n            seg.set(x, y);\n    }\n\n    return\
    \ 0;\n}"
  dependsOn:
  - segtree/segment-tree.cpp
  isVerificationFile: true
  path: test/AOJ-DLS-2-A.test.cpp
  requiredBy: []
  timestamp: '2021-04-08 19:35:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DLS-2-A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DLS-2-A.test.cpp
- /verify/test/AOJ-DLS-2-A.test.cpp.html
title: test/AOJ-DLS-2-A.test.cpp
---
