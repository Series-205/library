---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    using namespace std;\n\nstruct HeavyLightDecomposition {\n    vector<vector<int>>\
    \ &g;\n    vector<int> sz, in, out, head, rev, par;\n\n    explicit HeavyLightDecomposition(vector<vector<int>>\
    \ &g)\n        : g(g),\n          sz(g.size()),\n          in(g.size()),\n   \
    \       out(g.size()),\n          head(g.size()),\n          rev(g.size()),\n\
    \          par(g.size()) {}\n\n    void dfs_sz(int v, int p) {\n        par[v]\
    \ = p;\n        sz[v] = 1;\n        if(!g[v].empty() && g[v][0] == p) swap(g[v][0],\
    \ g[v].back());\n        for(auto &&u : g[v])\n            if(u != p) {\n    \
    \            dfs_sz(u, v);\n                sz[v] += sz[u];\n                if(sz[u]\
    \ > sz[g[v][0]]) swap(u, g[v][0]);\n            }\n    }\n\n    void dfs_hld(int\
    \ v, int p, int &t) {\n        in[v] = t++;\n        rev[in[v]] = v;\n       \
    \ for(auto &&u : g[v])\n            if(u != p) {\n                head[u] = (u\
    \ == g[v][0] ? head[v] : u);\n                dfs_hld(u, v, t);\n            }\n\
    \        out[v] = t;\n    }\n\n    void build(int r = 0) {\n        dfs_sz(r,\
    \ -1);\n        int t = 0;\n        dfs_hld(r, -1, t);\n    }\n\n    int lca(int\
    \ u, int v) {\n        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n\
    \            if(head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    template <typename Q>\n    void add(int u, int v, const\
    \ Q &q, bool edge = false) {\n        while(true) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            if(head[u] == head[v]) break;\n            q(in[head[v]],\
    \ in[v] + 1);\n            v = par[head[v]];\n        }\n        q(in[u] + edge,\
    \ in[v] + 1);\n    }\n\n    template <typename T, typename Q, typename F>\n  \
    \  T query(int u, int v, const T &ti, const Q &q, const F &f,\n            bool\
    \ edge = false) {\n        T l = ti, r = ti;\n        while(true) {\n        \
    \    if(in[u] > in[v]) {\n                swap(u, v);\n                swap(l,\
    \ r);\n            }\n            if(head[u] == head[v]) break;\n            l\
    \ = f(q(in[head[v]], in[v] + 1), l);\n            v = par[head[v]];\n        }\n\
    \        return f(f(q(in[u] + edge, in[v] + 1), l), r);\n    }\n};\n/*\n * @brief\
    \ Heavy-Light-Decomposition\n * @docs docs/heavy-light-decomposition.md\n */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct\
    \ HeavyLightDecomposition {\n    vector<vector<int>> &g;\n    vector<int> sz,\
    \ in, out, head, rev, par;\n\n    explicit HeavyLightDecomposition(vector<vector<int>>\
    \ &g)\n        : g(g),\n          sz(g.size()),\n          in(g.size()),\n   \
    \       out(g.size()),\n          head(g.size()),\n          rev(g.size()),\n\
    \          par(g.size()) {}\n\n    void dfs_sz(int v, int p) {\n        par[v]\
    \ = p;\n        sz[v] = 1;\n        if(!g[v].empty() && g[v][0] == p) swap(g[v][0],\
    \ g[v].back());\n        for(auto &&u : g[v])\n            if(u != p) {\n    \
    \            dfs_sz(u, v);\n                sz[v] += sz[u];\n                if(sz[u]\
    \ > sz[g[v][0]]) swap(u, g[v][0]);\n            }\n    }\n\n    void dfs_hld(int\
    \ v, int p, int &t) {\n        in[v] = t++;\n        rev[in[v]] = v;\n       \
    \ for(auto &&u : g[v])\n            if(u != p) {\n                head[u] = (u\
    \ == g[v][0] ? head[v] : u);\n                dfs_hld(u, v, t);\n            }\n\
    \        out[v] = t;\n    }\n\n    void build(int r = 0) {\n        dfs_sz(r,\
    \ -1);\n        int t = 0;\n        dfs_hld(r, -1, t);\n    }\n\n    int lca(int\
    \ u, int v) {\n        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n\
    \            if(head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    template <typename Q>\n    void add(int u, int v, const\
    \ Q &q, bool edge = false) {\n        while(true) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            if(head[u] == head[v]) break;\n            q(in[head[v]],\
    \ in[v] + 1);\n            v = par[head[v]];\n        }\n        q(in[u] + edge,\
    \ in[v] + 1);\n    }\n\n    template <typename T, typename Q, typename F>\n  \
    \  T query(int u, int v, const T &ti, const Q &q, const F &f,\n            bool\
    \ edge = false) {\n        T l = ti, r = ti;\n        while(true) {\n        \
    \    if(in[u] > in[v]) {\n                swap(u, v);\n                swap(l,\
    \ r);\n            }\n            if(head[u] == head[v]) break;\n            l\
    \ = f(q(in[head[v]], in[v] + 1), l);\n            v = par[head[v]];\n        }\n\
    \        return f(f(q(in[u] + edge, in[v] + 1), l), r);\n    }\n};\n/*\n * @brief\
    \ Heavy-Light-Decomposition\n * @docs docs/heavy-light-decomposition.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: graph/heavy-light-decomposition.cpp
  requiredBy: []
  timestamp: '2021-04-09 21:36:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-vertex-add-subtree-sum.test.cpp
  - test/yosupo-vertex-add-path-sum.test.cpp
documentation_of: graph/heavy-light-decomposition.cpp
layout: document
redirect_from:
- /library/graph/heavy-light-decomposition.cpp
- /library/graph/heavy-light-decomposition.cpp.html
title: Heavy-Light-Decomposition
---
## 説明

- `HeavyLightDecomposition(g)`: 木 $g$ で初期化
- `build(r)`: 頂点 $r$ を根として構築
- `lca(u, v)`: $u,v$ の最近共通祖先 $(\mathrm{LCA})$ を返す

## 計算量

`query`, `add` に渡される関数は $O(1)$ と仮定する

- constructor: $O(n)$
- `build`: $O(n)$
- クエリ: $O(\log n)$