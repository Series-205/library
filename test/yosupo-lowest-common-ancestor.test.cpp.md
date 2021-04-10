---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/heavy-light-decomposition.cpp
    title: Heavy-Light-Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo-lowest-common-ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"graph/heavy-light-decomposition.cpp\"\n\n#line 4 \"graph/heavy-light-decomposition.cpp\"\
    \nusing namespace std;\n\nclass HeavyLightDecomposition {\nprivate:\n    vector<vector<int>>\
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
    \ * @docs docs/heavy-light-decomposition.md\n */\n#line 7 \"test/yosupo-lowest-common-ancestor.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int n, q;\n    cin >> n >> q;\n    HeavyLightDecomposition tree(n);\n   \
    \ for(int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n        tree.add_edge(p,\
    \ i);\n    }\n    tree.build();\n\n    for(int i = 0; i < q; i++) {\n        int\
    \ u, v;\n        cin >> u >> v;\n        cout << tree.lca(u, v) << \"\\n\";\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../graph/heavy-light-decomposition.cpp\"\n\n\
    int main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int\
    \ n, q;\n    cin >> n >> q;\n    HeavyLightDecomposition tree(n);\n    for(int\
    \ i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n        tree.add_edge(p,\
    \ i);\n    }\n    tree.build();\n\n    for(int i = 0; i < q; i++) {\n        int\
    \ u, v;\n        cin >> u >> v;\n        cout << tree.lca(u, v) << \"\\n\";\n\
    \    }\n\n    return 0;\n}"
  dependsOn:
  - graph/heavy-light-decomposition.cpp
  isVerificationFile: true
  path: test/yosupo-lowest-common-ancestor.test.cpp
  requiredBy: []
  timestamp: '2021-04-10 19:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-lowest-common-ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-lowest-common-ancestor.test.cpp
- /verify/test/yosupo-lowest-common-ancestor.test.cpp.html
title: test/yosupo-lowest-common-ancestor.test.cpp
---
