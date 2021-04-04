---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.cpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/aoj-DLS-1-a.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"data-structure/union-find.cpp\"\
    \nusing namespace std;\n\nstruct UnionFind {\n    vector<int> data;\n\n    UnionFind()\
    \ = default;\n\n    explicit UnionFind(size_t sz) : data(sz, -1) {}\n\n    bool\
    \ unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n        if(x\
    \ == y) return false;\n        if(data[x] > data[y]) swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ x) { return data[x] < 0 ? x : data[x] = find(data[x]); }\n\n    int size(int\
    \ x) { return -data[x]; }\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n#line 7 \"test/aoj-DLS-1-a.test.cpp\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n\n    UnionFind uf(n);\n    for(int i = 0; i < q; i++) {\n\
    \        int c, x, y;\n        cin >> c >> x >> y;\n        if(c)\n          \
    \  cout << uf.same(x, y) << \"\\n\";\n        else\n            uf.unite(x, y);\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../data-structure/union-find.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\n    UnionFind uf(n);\n\
    \    for(int i = 0; i < q; i++) {\n        int c, x, y;\n        cin >> c >> x\
    \ >> y;\n        if(c)\n            cout << uf.same(x, y) << \"\\n\";\n      \
    \  else\n            uf.unite(x, y);\n    }\n\n    return 0;\n}"
  dependsOn:
  - data-structure/union-find.cpp
  isVerificationFile: true
  path: test/aoj-DLS-1-a.test.cpp
  requiredBy: []
  timestamp: '2021-04-04 22:46:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DLS-1-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DLS-1-a.test.cpp
- /verify/test/aoj-DLS-1-a.test.cpp.html
title: test/aoj-DLS-1-a.test.cpp
---
