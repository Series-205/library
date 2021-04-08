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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo-Unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"data-structure/union-find.cpp\"\
    \nusing namespace std;\n\nstruct UnionFind {\n    vector<int> data;\n\n    UnionFind()\
    \ = default;\n\n    explicit UnionFind(size_t sz) : data(sz, -1) {}\n\n    bool\
    \ unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n        if(x\
    \ == y) return false;\n        if(data[x] > data[y]) swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ x) { return data[x] < 0 ? x : data[x] = find(data[x]); }\n\n    int size(int\
    \ x) { return -data[x]; }\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n/*\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n#line 7 \"\
    test/yosupo-Unionfind.test.cpp\"\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\n    for(int i = 0;\
    \ i < q; i++) {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if(t)\n\
    \            cout << uf.same(u, v) << \"\\n\";\n        else\n            uf.unite(u,\
    \ v);\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../data-structure/union-find.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\n    for(int i = 0;\
    \ i < q; i++) {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if(t)\n\
    \            cout << uf.same(u, v) << \"\\n\";\n        else\n            uf.unite(u,\
    \ v);\n    }\n\n    return 0;\n}"
  dependsOn:
  - data-structure/union-find.cpp
  isVerificationFile: true
  path: test/yosupo-Unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-04-08 19:35:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-Unionfind.test.cpp
- /verify/test/yosupo-Unionfind.test.cpp.html
title: test/yosupo-Unionfind.test.cpp
---
