---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/rerooting.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class DP>\nclass ReRooting {\n    int size;\n\n\
    private:\n    vector<vector<int>> G;\n    vector<DP> dp;\n\n    DP id;\n    function<DP(DP,\
    \ DP)> merge;\n    function<DP(DP)> add_root;\n\npublic:\n    ReRooting(int n,\
    \ DP _id, function<DP(DP, DP)> _merge,\n              function<DP(DP)> _add_root)\n\
    \        : size(n), G(n), dp(n), id(_id), merge(_merge), add_root(_add_root) {}\n\
    \n    ReRooting(vector<vector<int>> _g, DP _id, function<DP(DP, DP)> _merge,\n\
    \              function<DP(DP)> _add_root)\n        : size(_g.size()),\n     \
    \     G(_g),\n          dp(_g.size()),\n          id(_id),\n          merge(_merge),\n\
    \          add_root(_add_root) {}\n\n    void add_edge(int u, int v) {\n     \
    \   G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    void build(int\
    \ root = 0) {\n        dfs1(root, -1);\n        dfs2(root, -1, id);\n    }\n\n\
    \    const DP operator[](size_t n) const { return dp[n]; }\n\nprivate:\n    DP\
    \ dfs1(int v, int p) {\n        dp[v] = id;\n        for(int u : G[v]) {\n   \
    \         if(u != p) {\n                dp[v] = merge(dp[v], dfs1(u, v));\n  \
    \          }\n        }\n        return dp[v] = add_root(dp[v]);\n    }\n\n  \
    \  void dfs2(int v, int p, DP dp_p) {\n        size_t n = G[v].size();\n     \
    \   if(n == 0) {\n            dp[v] = add_root(id);\n            return;\n   \
    \     }\n        vector<DP> l(n, id);\n        for(int i = 0; i < n; i++) {\n\
    \            int u = G[v][i];\n            if(u == p) {\n                l[i]\
    \ = dp_p;\n            } else {\n                l[i] = dp[u];\n            }\n\
    \        }\n        auto r = l;\n\n        for(int i = 0; i + 1 < n; i++) l[i\
    \ + 1] = merge(l[i], l[i + 1]);\n        for(int i = n - 1; i > 0; i--) r[i -\
    \ 1] = merge(r[i - 1], r[i]);\n\n        dp[v] = add_root(r[0]);\n\n        for(int\
    \ i = 0; i < n; i++) {\n            int u = G[v][i];\n            if(u != p) {\n\
    \                DP a = (i ? l[i - 1] : id);\n                DP b = (i + 1 <\
    \ (ll)n ? r[i + 1] : id);\n                dfs2(u, v, add_root(merge(a, b)));\n\
    \            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class DP>\nclass ReRooting {\n    int size;\n\nprivate:\n    vector<vector<int>>\
    \ G;\n    vector<DP> dp;\n\n    DP id;\n    function<DP(DP, DP)> merge;\n    function<DP(DP)>\
    \ add_root;\n\npublic:\n    ReRooting(int n, DP _id, function<DP(DP, DP)> _merge,\n\
    \              function<DP(DP)> _add_root)\n        : size(n), G(n), dp(n), id(_id),\
    \ merge(_merge), add_root(_add_root) {}\n\n    ReRooting(vector<vector<int>> _g,\
    \ DP _id, function<DP(DP, DP)> _merge,\n              function<DP(DP)> _add_root)\n\
    \        : size(_g.size()),\n          G(_g),\n          dp(_g.size()),\n    \
    \      id(_id),\n          merge(_merge),\n          add_root(_add_root) {}\n\n\
    \    void add_edge(int u, int v) {\n        G[u].push_back(v);\n        G[v].push_back(u);\n\
    \    }\n\n    void build(int root = 0) {\n        dfs1(root, -1);\n        dfs2(root,\
    \ -1, id);\n    }\n\n    const DP operator[](size_t n) const { return dp[n]; }\n\
    \nprivate:\n    DP dfs1(int v, int p) {\n        dp[v] = id;\n        for(int\
    \ u : G[v]) {\n            if(u != p) {\n                dp[v] = merge(dp[v],\
    \ dfs1(u, v));\n            }\n        }\n        return dp[v] = add_root(dp[v]);\n\
    \    }\n\n    void dfs2(int v, int p, DP dp_p) {\n        size_t n = G[v].size();\n\
    \        if(n == 0) {\n            dp[v] = add_root(id);\n            return;\n\
    \        }\n        vector<DP> l(n, id);\n        for(int i = 0; i < n; i++) {\n\
    \            int u = G[v][i];\n            if(u == p) {\n                l[i]\
    \ = dp_p;\n            } else {\n                l[i] = dp[u];\n            }\n\
    \        }\n        auto r = l;\n\n        for(int i = 0; i + 1 < n; i++) l[i\
    \ + 1] = merge(l[i], l[i + 1]);\n        for(int i = n - 1; i > 0; i--) r[i -\
    \ 1] = merge(r[i - 1], r[i]);\n\n        dp[v] = add_root(r[0]);\n\n        for(int\
    \ i = 0; i < n; i++) {\n            int u = G[v][i];\n            if(u != p) {\n\
    \                DP a = (i ? l[i - 1] : id);\n                DP b = (i + 1 <\
    \ (ll)n ? r[i + 1] : id);\n                dfs2(u, v, add_root(merge(a, b)));\n\
    \            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.cpp
  requiredBy: []
  timestamp: '2023-11-24 18:54:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/rerooting.cpp
layout: document
redirect_from:
- /library/graph/rerooting.cpp
- /library/graph/rerooting.cpp.html
title: graph/rerooting.cpp
---
