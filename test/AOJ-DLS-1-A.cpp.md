---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/union-find.cpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/AOJ-DLS-1-A.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"data-structure/union-find.cpp\"\
    \nusing namespace std;\n\nstruct UnionFind {\n    vector<int> data;\n\n    UnionFind()\
    \ = default;\n\n    explicit UnionFind(size_t sz) : data(sz, -1) {}\n\n    bool\
    \ unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n        if(x\
    \ == y) return false;\n        if(data[x] > data[y]) swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ x) { return data[x] < 0 ? x : data[x] = find(data[x]); }\n\n    int size(int\
    \ x) { return -data[x]; }\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n#line 7 \"test/AOJ-DLS-1-A.cpp\"\n\nint main() {\n    int n, q;\n   \
    \ cin >> n >> q;\n\n    UnionFind uf(n);\n    for(int i = 0; i < q; i++) {\n \
    \       int c, x, y;\n        cin >> c >> x >> y;\n        if(c)\n           \
    \ cout << uf.same(x, y) << \"\\n\";\n        else\n            uf.unite(x, y);\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../data-structure/union-find.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\n    UnionFind uf(n);\n\
    \    for(int i = 0; i < q; i++) {\n        int c, x, y;\n        cin >> c >> x\
    \ >> y;\n        if(c)\n            cout << uf.same(x, y) << \"\\n\";\n      \
    \  else\n            uf.unite(x, y);\n    }\n\n    return 0;\n}"
  dependsOn:
  - data-structure/union-find.cpp
  isVerificationFile: false
  path: test/AOJ-DLS-1-A.cpp
  requiredBy: []
  timestamp: '2021-04-05 17:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/AOJ-DLS-1-A.cpp
layout: document
redirect_from:
- /library/test/AOJ-DLS-1-A.cpp
- /library/test/AOJ-DLS-1-A.cpp.html
title: test/AOJ-DLS-1-A.cpp
---
