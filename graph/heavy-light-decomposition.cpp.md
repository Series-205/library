---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lowest-common-ancestor.test.cpp
    title: test/yosupo-lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex-add-path-sum.test.cpp
    title: test/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex-add-subtree-sum.test.cpp
    title: test/yosupo-vertex-add-subtree-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/heavy-light-decomposition.md
    document_title: Heavy-Light-Decomposition
    links: []
  bundledCode: "#line 2 \"graph/heavy-light-decomposition.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nclass HeavyLightDecomposition {\nprivate:\n    vector<vector<int>>\
    \ g;\n    vector<int> sz, in, out, head, rev, par;\n    bool built;\n\n    void\
    \ dfs_sz(int v, int p) {\n        par[v] = p;\n        sz[v] = 1;\n        if(!g[v].empty()\
    \ && g[v][0] == p) swap(g[v][0], g[v].back());\n        for(auto &&u : g[v])\n\
    \            if(u != p) {\n                dfs_sz(u, v);\n                sz[v]\
    \ += sz[u];\n                if(sz[u] > sz[g[v][0]]) swap(u, g[v][0]);\n     \
    \       }\n    }\n\n    void dfs_hld(int v, int p, int &t) {\n        in[v] =\
    \ t++;\n        rev[in[v]] = v;\n        for(auto &&u : g[v])\n            if(u\
    \ != p) {\n                head[u] = (u == g[v][0] ? head[v] : u);\n         \
    \       dfs_hld(u, v, t);\n            }\n        out[v] = t;\n    }\n\npublic:\n\
    \    explicit HeavyLightDecomposition(int n)\n        : g(n), sz(n), in(n), out(n),\
    \ head(n), rev(n), par(n), built(false) {}\n    explicit HeavyLightDecomposition(const\
    \ vector<vector<int>> &g, int root = 0)\n        : g(g),\n          sz(g.size()),\n\
    \          in(g.size()),\n          out(g.size()),\n          head(g.size()),\n\
    \          rev(g.size()),\n          par(g.size()) {\n        build(root);\n \
    \   }\n\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n     \
    \   g[v].push_back(u);\n    }\n\n    void build(int r = 0) {\n        dfs_sz(r,\
    \ -1);\n        int t = 0;\n        head[r] = r;\n        dfs_hld(r, -1, t);\n\
    \        built = true;\n    }\n\n    int lca(int u, int v) {\n        assert(built);\n\
    \        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n          \
    \  if(head[u] == head[v]) return u;\n            v = par[head[v]];\n        }\n\
    \    }\n\n    pair<int, int> subtree_query(int u) {\n        assert(built);\n\
    \        return pair<int, int>{in[u], out[u]};\n    }\n\n    vector<pair<int,\
    \ int>> node_query(int u, int v) {\n        assert(built);\n        vector<pair<int,\
    \ int>> res;\n        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n\
    \            if(head[u] == head[v]) break;\n            res.emplace_back(in[head[v]],\
    \ in[v] + 1);\n            v = par[head[v]];\n        }\n        res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    vector<pair<int, int>> edge_query(int\
    \ u, int v) {\n        assert(built);\n        vector<pair<int, int>> res;\n \
    \       while(true) {\n            if(in[u] > in[v]) swap(u, v);\n           \
    \ if(head[u] == head[v]) break;\n            res.emplace_back(in[head[v]], in[v]\
    \ + 1);\n            v = par[head[v]];\n        }\n        res.emplace_back(in[u]\
    \ + 1, in[v] + 1);\n        return res;\n    }\n\n    int operator[](int u) {\n\
    \        assert(built);\n        return in[u];\n    }\n};\n/*\n * @brief Heavy-Light-Decomposition\n\
    \ * @docs docs/heavy-light-decomposition.md\n */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nclass HeavyLightDecomposition\
    \ {\nprivate:\n    vector<vector<int>> g;\n    vector<int> sz, in, out, head,\
    \ rev, par;\n    bool built;\n\n    void dfs_sz(int v, int p) {\n        par[v]\
    \ = p;\n        sz[v] = 1;\n        if(!g[v].empty() && g[v][0] == p) swap(g[v][0],\
    \ g[v].back());\n        for(auto &&u : g[v])\n            if(u != p) {\n    \
    \            dfs_sz(u, v);\n                sz[v] += sz[u];\n                if(sz[u]\
    \ > sz[g[v][0]]) swap(u, g[v][0]);\n            }\n    }\n\n    void dfs_hld(int\
    \ v, int p, int &t) {\n        in[v] = t++;\n        rev[in[v]] = v;\n       \
    \ for(auto &&u : g[v])\n            if(u != p) {\n                head[u] = (u\
    \ == g[v][0] ? head[v] : u);\n                dfs_hld(u, v, t);\n            }\n\
    \        out[v] = t;\n    }\n\npublic:\n    explicit HeavyLightDecomposition(int\
    \ n)\n        : g(n), sz(n), in(n), out(n), head(n), rev(n), par(n), built(false)\
    \ {}\n    explicit HeavyLightDecomposition(const vector<vector<int>> &g, int root\
    \ = 0)\n        : g(g),\n          sz(g.size()),\n          in(g.size()),\n  \
    \        out(g.size()),\n          head(g.size()),\n          rev(g.size()),\n\
    \          par(g.size()) {\n        build(root);\n    }\n\n    void add_edge(int\
    \ u, int v) {\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\
    \n    void build(int r = 0) {\n        dfs_sz(r, -1);\n        int t = 0;\n  \
    \      head[r] = r;\n        dfs_hld(r, -1, t);\n        built = true;\n    }\n\
    \n    int lca(int u, int v) {\n        assert(built);\n        while(true) {\n\
    \            if(in[u] > in[v]) swap(u, v);\n            if(head[u] == head[v])\
    \ return u;\n            v = par[head[v]];\n        }\n    }\n\n    pair<int,\
    \ int> subtree_query(int u) {\n        assert(built);\n        return pair<int,\
    \ int>{in[u], out[u]};\n    }\n\n    vector<pair<int, int>> node_query(int u,\
    \ int v) {\n        assert(built);\n        vector<pair<int, int>> res;\n    \
    \    while(true) {\n            if(in[u] > in[v]) swap(u, v);\n            if(head[u]\
    \ == head[v]) break;\n            res.emplace_back(in[head[v]], in[v] + 1);\n\
    \            v = par[head[v]];\n        }\n        res.emplace_back(in[u], in[v]\
    \ + 1);\n        return res;\n    }\n\n    vector<pair<int, int>> edge_query(int\
    \ u, int v) {\n        assert(built);\n        vector<pair<int, int>> res;\n \
    \       while(true) {\n            if(in[u] > in[v]) swap(u, v);\n           \
    \ if(head[u] == head[v]) break;\n            res.emplace_back(in[head[v]], in[v]\
    \ + 1);\n            v = par[head[v]];\n        }\n        res.emplace_back(in[u]\
    \ + 1, in[v] + 1);\n        return res;\n    }\n\n    int operator[](int u) {\n\
    \        assert(built);\n        return in[u];\n    }\n};\n/*\n * @brief Heavy-Light-Decomposition\n\
    \ * @docs docs/heavy-light-decomposition.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: graph/heavy-light-decomposition.cpp
  requiredBy: []
  timestamp: '2021-04-10 19:01:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-vertex-add-subtree-sum.test.cpp
  - test/yosupo-lowest-common-ancestor.test.cpp
  - test/yosupo-vertex-add-path-sum.test.cpp
documentation_of: graph/heavy-light-decomposition.cpp
layout: document
redirect_from:
- /library/graph/heavy-light-decomposition.cpp
- /library/graph/heavy-light-decomposition.cpp.html
title: Heavy-Light-Decomposition
---
## TODO

`query()` を交換則が成り立たなくても OK な感じにする

## 説明

- `HeavyLightDecomposition(g)`: 木 $g$ で初期化
- `build(r)`: 頂点 $r$ を根として構築
- `lca(u, v)`: $u,v$ の最近共通祖先 $(\mathrm{LCA})$ を返す

## 計算量

`query`, `add` に渡される関数は $O(1)$ と仮定する

- constructor: $O(n)$
- `build`: $O(n)$
- クエリ: $O(\log n)$