---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/heavy-light-decomposition.cpp
    title: Heavy-Light-Decomposition
  - icon: ':heavy_check_mark:'
    path: segtree/segment-tree.cpp
    title: Segment-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo-vertex-add-subtree-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"graph/heavy-light-decomposition.cpp\"\n\n#line\
    \ 4 \"graph/heavy-light-decomposition.cpp\"\nusing namespace std;\n\nclass HeavyLightDecomposition\
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
    \ * @docs docs/heavy-light-decomposition.md\n */\n#line 3 \"segtree/segment-tree.cpp\"\
    \nusing namespace std;\n\n// \u30E2\u30CE\u30A4\u30C9, \u6F14\u7B97, \u5358\u4F4D\
    \u5143\ntemplate <typename S, S (*op)(S, S), S (*e)()>\nclass SegmentTree {\n\
    private:\n    int _n, sz;\n    vector<S> data;\n\n    void calc(int k) { data[k]\
    \ = op(data[k << 1], data[k << 1 | 1]); }\n\npublic:\n    SegmentTree() = default;\n\
    \    explicit SegmentTree(int n) : SegmentTree(vector<S>(n, e())) {}\n    explicit\
    \ SegmentTree(const vector<S>& v) : _n(v.size()) {\n        sz = 1;\n        while(sz\
    \ < _n) sz <<= 1;\n        data.assign(sz << 1, e());\n        for(int i = 0;\
    \ i < _n; i++) data[sz + i] = v[i];\n        for(int i = sz - 1; i >= 1; i--)\
    \ calc(i);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += sz;\n        data[p] = x;\n        while(p >>= 1) calc(p);\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        return\
    \ data[p + sz];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sl = e(), sr = e();\n        l += sz;\n     \
    \   r += sz;\n        while(l < r) {\n            if(l & 1) sl = op(sl, data[l++]);\n\
    \            if(r & 1) sr = op(data[--r], sr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sl, sr);\n    }\n\n    S all_prod()\
    \ { return data[1]; }\n};\n/*\n * @brief Segment-Tree\n * @docs docs/segment-tree.md\n\
    \ */\n#line 8 \"test/yosupo-vertex-add-subtree-sum.test.cpp\"\n\nusing ll = long\
    \ long;\n\nusing S = ll;\nS op(S l, S r) { return l + r; }\nS e() { return 0;\
    \ }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    cin >> n >> q;\n    vector<S> a(n);\n    for(int i = 0; i\
    \ < n; i++) cin >> a[i];\n\n    HeavyLightDecomposition tree(n);\n    for(int\
    \ i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n        tree.add_edge(p,\
    \ i);\n    }\n    tree.build(0);\n\n    vector<S> b(n);\n    for(int i = 0; i\
    \ < n; i++) b[tree[i]] = a[i];\n    SegmentTree<S, op, e> seg(b);\n\n    for(int\
    \ i = 0; i < q; i++) {\n        int t;\n        cin >> t;\n        if(t) {\n \
    \           int u;\n            cin >> u;\n            auto [l, r] = tree.subtree_query(u);\n\
    \            cout << seg.prod(l, r) << \"\\n\";\n        } else {\n          \
    \  int u, x;\n            cin >> u >> x;\n            seg.set(tree[u], seg.get(tree[u])\
    \ + x);\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../graph/heavy-light-decomposition.cpp\"\
    \n#include \"../segtree/segment-tree.cpp\"\n\nusing ll = long long;\n\nusing S\
    \ = ll;\nS op(S l, S r) { return l + r; }\nS e() { return 0; }\n\nint main() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int n, q;\n  \
    \  cin >> n >> q;\n    vector<S> a(n);\n    for(int i = 0; i < n; i++) cin >>\
    \ a[i];\n\n    HeavyLightDecomposition tree(n);\n    for(int i = 1; i < n; i++)\
    \ {\n        int p;\n        cin >> p;\n        tree.add_edge(p, i);\n    }\n\
    \    tree.build(0);\n\n    vector<S> b(n);\n    for(int i = 0; i < n; i++) b[tree[i]]\
    \ = a[i];\n    SegmentTree<S, op, e> seg(b);\n\n    for(int i = 0; i < q; i++)\
    \ {\n        int t;\n        cin >> t;\n        if(t) {\n            int u;\n\
    \            cin >> u;\n            auto [l, r] = tree.subtree_query(u);\n   \
    \         cout << seg.prod(l, r) << \"\\n\";\n        } else {\n            int\
    \ u, x;\n            cin >> u >> x;\n            seg.set(tree[u], seg.get(tree[u])\
    \ + x);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - graph/heavy-light-decomposition.cpp
  - segtree/segment-tree.cpp
  isVerificationFile: true
  path: test/yosupo-vertex-add-subtree-sum.test.cpp
  requiredBy: []
  timestamp: '2021-04-10 19:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-vertex-add-subtree-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-vertex-add-subtree-sum.test.cpp
- /verify/test/yosupo-vertex-add-subtree-sum.test.cpp.html
title: test/yosupo-vertex-add-subtree-sum.test.cpp
---
