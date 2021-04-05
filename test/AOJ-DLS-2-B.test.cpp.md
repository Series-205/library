---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.cpp
    title: Fenwick-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/AOJ-DLS-2-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data-structure/fenwick-tree.cpp\"\
    \n\n#line 4 \"data-structure/fenwick-tree.cpp\"\nusing namespace std;\n\ntemplate\
    \ <typename T>\nclass FenwickTree {\nprivate:\n    int _n;\n    vector<T> data;\n\
    \n    T sum(int r) {\n        T s = 0;\n        while(r > 0) {\n            s\
    \ += data[r - 1];\n            r -= r & -r;\n        }\n        return s;\n  \
    \  }\n\npublic:\n    FenwickTree() = default;\n    FenwickTree(int n) : _n(n),\
    \ data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n\
    \        p++;\n        while(p <= _n) {\n            data[p - 1] += x;\n     \
    \       p += p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n};\n#line\
    \ 7 \"test/AOJ-DLS-2-B.test.cpp\"\n\nint main() {\n    int n, q;\n    cin >> n\
    \ >> q;\n\n    FenwickTree<int> bit(n);\n\n    for(int i = 0; i < q; i++) {\n\
    \        int c, x, y;\n        cin >> c >> x >> y;\n        if(c)\n          \
    \  cout << bit.sum(x - 1, y) << \"\\n\";\n        else\n            bit.add(x\
    \ - 1, y);\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../data-structure/fenwick-tree.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\n    FenwickTree<int> bit(n);\n\
    \n    for(int i = 0; i < q; i++) {\n        int c, x, y;\n        cin >> c >>\
    \ x >> y;\n        if(c)\n            cout << bit.sum(x - 1, y) << \"\\n\";\n\
    \        else\n            bit.add(x - 1, y);\n    }\n}"
  dependsOn:
  - data-structure/fenwick-tree.cpp
  isVerificationFile: true
  path: test/AOJ-DLS-2-B.test.cpp
  requiredBy: []
  timestamp: '2021-04-05 18:55:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DLS-2-B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DLS-2-B.test.cpp
- /verify/test/AOJ-DLS-2-B.test.cpp.html
title: test/AOJ-DLS-2-B.test.cpp
---
