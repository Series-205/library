---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/fenwick-tree.cpp
    title: Fenwick-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo-point-add-range-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"segtree/fenwick-tree.cpp\"\n\n#line 4 \"segtree/fenwick-tree.cpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nclass FenwickTree {\nprivate:\n\
    \    int _n;\n    vector<T> data;\n\n    T sum(int r) {\n        T s = 0;\n  \
    \      while(r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n\
    \        }\n        return s;\n    }\n\npublic:\n    FenwickTree() = default;\n\
    \    explicit FenwickTree(int n) : _n(n), data(n) {}\n\n    void add(int p, T\
    \ x) {\n        assert(0 <= p && p < _n);\n        p++;\n        while(p <= _n)\
    \ {\n            data[p - 1] += x;\n            p += p & -p;\n        }\n    }\n\
    \n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n  \
    \      return sum(r) - sum(l);\n    }\n};\n/*\n * @brief Fenwick-Tree\n * @docs\
    \ docs/fenwick-tree.md\n */\n#line 7 \"test/yosupo-point-add-range-sum.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int n, q;\n    cin >> n >> q;\n    FenwickTree<int64_t> bit(n);\n\n    for(int\
    \ i = 0; i < n; i++) {\n        int a;\n        cin >> a;\n        bit.add(i,\
    \ a);\n    }\n\n    for(int i = 0; i < q; i++) {\n        int a, b, c;\n     \
    \   cin >> a >> b >> c;\n        if(a)\n            cout << bit.sum(b, c) << \"\
    \\n\";\n        else\n            bit.add(b, c);\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../segtree/fenwick-tree.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int n, q;\n    cin >> n >> q;\n    FenwickTree<int64_t> bit(n);\n\n    for(int\
    \ i = 0; i < n; i++) {\n        int a;\n        cin >> a;\n        bit.add(i,\
    \ a);\n    }\n\n    for(int i = 0; i < q; i++) {\n        int a, b, c;\n     \
    \   cin >> a >> b >> c;\n        if(a)\n            cout << bit.sum(b, c) << \"\
    \\n\";\n        else\n            bit.add(b, c);\n    }\n\n    return 0;\n}"
  dependsOn:
  - segtree/fenwick-tree.cpp
  isVerificationFile: true
  path: test/yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2021-04-08 19:35:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-point-add-range-sum.test.cpp
- /verify/test/yosupo-point-add-range-sum.test.cpp.html
title: test/yosupo-point-add-range-sum.test.cpp
---
