---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DLS-1-a.test.cpp
    title: test/aoj-DLS-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/union-find.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct UnionFind {\n    vector<int> data;\n\n    UnionFind()\
    \ = default;\n\n    explicit UnionFind(size_t sz) : data(sz, -1) {}\n\n    bool\
    \ unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n        if(x\
    \ == y) return false;\n        if(data[x] > data[y]) swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ x) { return data[x] < 0 ? x : data[x] = find(data[x]); }\n\n    int size(int\
    \ x) { return -data[x]; }\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct UnionFind\
    \ {\n    vector<int> data;\n\n    UnionFind() = default;\n\n    explicit UnionFind(size_t\
    \ sz) : data(sz, -1) {}\n\n    bool unite(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        if(x == y) return false;\n        if(data[x] >\
    \ data[y]) swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n  \
    \      return true;\n    }\n\n    int find(int x) { return data[x] < 0 ? x : data[x]\
    \ = find(data[x]); }\n\n    int size(int x) { return -data[x]; }\n\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.cpp
  requiredBy: []
  timestamp: '2021-04-04 22:46:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DLS-1-a.test.cpp
documentation_of: data-structure/union-find.cpp
layout: document
title: Union-Find
---

あかさたな