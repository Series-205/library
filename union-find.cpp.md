---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: aoj-DLS-1-a.test.cpp
    title: aoj-DLS-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"union-find.cpp\"\n#include <vector>\n\nstruct UnionFind\
    \ {\n    std::vector<int> data;\n\n    UnionFind() = default;\n\n    explicit\
    \ UnionFind(size_t sz) : data(sz, -1) {}\n\n    bool unite(int x, int y) {\n \
    \       x = find(x);\n        y = find(y);\n        if(x == y) return false;\n\
    \        if(data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        return true;\n    }\n\n    int find(int x) { return\
    \ data[x] < 0 ? x : data[x] = find(data[x]); }\n\n    int size(int x) { return\
    \ -data[x]; }\n\n    bool same(int x, int y) { return find(x) == find(y); }\n\
    };\n"
  code: "#pragma once\n#include <vector>\n\nstruct UnionFind {\n    std::vector<int>\
    \ data;\n\n    UnionFind() = default;\n\n    explicit UnionFind(size_t sz) : data(sz,\
    \ -1) {}\n\n    bool unite(int x, int y) {\n        x = find(x);\n        y =\
    \ find(y);\n        if(x == y) return false;\n        if(data[x] > data[y]) std::swap(x,\
    \ y);\n        data[x] += data[y];\n        data[y] = x;\n        return true;\n\
    \    }\n\n    int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]);\
    \ }\n\n    int size(int x) { return -data[x]; }\n\n    bool same(int x, int y)\
    \ { return find(x) == find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: union-find.cpp
  requiredBy: []
  timestamp: '2021-04-04 22:19:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - aoj-DLS-1-a.test.cpp
documentation_of: union-find.cpp
layout: document
redirect_from:
- /library/union-find.cpp
- /library/union-find.cpp.html
title: union-find.cpp
---
