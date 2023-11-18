---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/centroid-decomposition.md
    document_title: Centroid-Decomposition
    links: []
  bundledCode: "#line 2 \"graph/centroid-decomposition.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct CentroidDecomposition {\nprivate:\n    vector<bool>\
    \ used;\n    vector<int> sz;\n\n    inline int calc_size(int u, int p) {\n   \
    \     sz[u] = 1;\n        for(int v : tree[u])\n            if(!used[v] && v !=\
    \ p) sz[u] += calc_size(v, u);\n        return sz[u];\n    }\n\n    inline int\
    \ find_centroid(int u, int p, const int mid) {\n        for(int v : tree[u])\n\
    \            if(!used[v] && v != p && sz[v] > mid)\n                return find_centroid(v,\
    \ u, mid);\n        return u;\n    }\n\n    inline void belong_dfs(int u, int\
    \ p, int centroid) {\n        belong[u].push_back(centroid);\n        for(int\
    \ v : tree[u])\n            if(!used[v] && v != p) belong_dfs(v, u, centroid);\n\
    \    }\n\n    inline int build(int u) {\n        int centroid = find_centroid(u,\
    \ -1, calc_size(u, -1) / 2);\n        used[centroid] = true;\n        belong_dfs(centroid,\
    \ -1, centroid);\n        for(int v : tree[centroid])\n            if(!used[v])\
    \ cdtree[centroid].push_back(build(v));\n        used[centroid] = false;\n   \
    \     return centroid;\n    }\n\npublic:\n    vector<vector<int>> tree, cdtree;\n\
    \    vector<vector<int>> belong;  // belong[u]: u \u3092\u542B\u3080\u9023\u7D50\
    \u6210\u5206\u306E centroid \u305F\u3061\n    int root = -1;               //\
    \ root of cdtree\n\n    explicit CentroidDecomposition(const vector<vector<int>>\
    \ &g)\n        : tree(g), root(-1) {}\n\n    explicit CentroidDecomposition(int\
    \ n) : tree(n), root(-1) {}\n\n    inline void add_edge(int u, int v) {\n    \
    \    tree[u].push_back(v);\n        tree[v].push_back(u);\n    }\n\n    // return\
    \ root of cdtree\n    inline int build() {\n        cdtree.assign(tree.size(),\
    \ {});\n        used.assign(tree.size(), false);\n        sz.resize(tree.size());\n\
    \        belong.assign(tree.size(), {});\n        return root = build(0);\n  \
    \  }\n};\n/*\n * @brief Centroid-Decomposition\n * @docs docs/centroid-decomposition.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct\
    \ CentroidDecomposition {\nprivate:\n    vector<bool> used;\n    vector<int> sz;\n\
    \n    inline int calc_size(int u, int p) {\n        sz[u] = 1;\n        for(int\
    \ v : tree[u])\n            if(!used[v] && v != p) sz[u] += calc_size(v, u);\n\
    \        return sz[u];\n    }\n\n    inline int find_centroid(int u, int p, const\
    \ int mid) {\n        for(int v : tree[u])\n            if(!used[v] && v != p\
    \ && sz[v] > mid)\n                return find_centroid(v, u, mid);\n        return\
    \ u;\n    }\n\n    inline void belong_dfs(int u, int p, int centroid) {\n    \
    \    belong[u].push_back(centroid);\n        for(int v : tree[u])\n          \
    \  if(!used[v] && v != p) belong_dfs(v, u, centroid);\n    }\n\n    inline int\
    \ build(int u) {\n        int centroid = find_centroid(u, -1, calc_size(u, -1)\
    \ / 2);\n        used[centroid] = true;\n        belong_dfs(centroid, -1, centroid);\n\
    \        for(int v : tree[centroid])\n            if(!used[v]) cdtree[centroid].push_back(build(v));\n\
    \        used[centroid] = false;\n        return centroid;\n    }\n\npublic:\n\
    \    vector<vector<int>> tree, cdtree;\n    vector<vector<int>> belong;  // belong[u]:\
    \ u \u3092\u542B\u3080\u9023\u7D50\u6210\u5206\u306E centroid \u305F\u3061\n \
    \   int root = -1;               // root of cdtree\n\n    explicit CentroidDecomposition(const\
    \ vector<vector<int>> &g)\n        : tree(g), root(-1) {}\n\n    explicit CentroidDecomposition(int\
    \ n) : tree(n), root(-1) {}\n\n    inline void add_edge(int u, int v) {\n    \
    \    tree[u].push_back(v);\n        tree[v].push_back(u);\n    }\n\n    // return\
    \ root of cdtree\n    inline int build() {\n        cdtree.assign(tree.size(),\
    \ {});\n        used.assign(tree.size(), false);\n        sz.resize(tree.size());\n\
    \        belong.assign(tree.size(), {});\n        return root = build(0);\n  \
    \  }\n};\n/*\n * @brief Centroid-Decomposition\n * @docs docs/centroid-decomposition.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: graph/centroid-decomposition.cpp
  requiredBy: []
  timestamp: '2023-03-20 20:11:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroid-decomposition.cpp
layout: document
title: Centroid Decomposition
---

## 説明

重心分解

## 計算量

$O(N \log N)$
