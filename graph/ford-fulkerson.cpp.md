---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-GRL-6-A.test.cpp
    title: test/AOJ-GRL-6-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/ford-fulkerson.md
    document_title: Ford-Fulkerson
    links: []
  bundledCode: "#line 2 \"graph/ford-fulkerson.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename flow_t>\nstruct FordFulkerson {\n \
    \   struct edge {\n        int to;\n        flow_t cap;\n        int rev;\n  \
    \      bool isrev;\n    };\n\n    vector<vector<edge>> graph;\n    vector<int>\
    \ used;\n    const flow_t INF;\n    int timestamp;\n\n    explicit FordFulkerson(int\
    \ V)\n        : graph(V),\n          used(V, -1),\n          INF(numeric_limits<flow_t>::max()),\n\
    \          timestamp(0) {}\n\n    void add_edge(int from, int to, flow_t cap)\
    \ {\n        graph[from].push_back(edge{to, cap, (int)graph[to].size(), false});\n\
    \        graph[to].push_back(edge{from, 0, (int)graph[from].size() - 1, false});\n\
    \    }\n\n    flow_t dfs(int idx, const int t, flow_t flow) {\n        if(idx\
    \ == t) return flow;\n        used[idx] = timestamp;\n        for(auto &&e : graph[idx])\n\
    \            if(e.cap > 0 && used[e.to] != timestamp) {\n                flow_t\
    \ d = dfs(e.to, t, min(flow, e.cap));\n                if(d > 0) {\n         \
    \           e.cap -= d;\n                    graph[e.to][e.rev].cap += d;\n  \
    \                  return d;\n                }\n            }\n        return\
    \ 0;\n    }\n\n    flow_t max_flow(int s, int t) {\n        flow_t flow = 0;\n\
    \        for(flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) flow += f;\n   \
    \     return flow;\n    }\n};\n/*\n * @brief Ford-Fulkerson\n * @docs docs/ford-fulkerson.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename flow_t>\nstruct FordFulkerson {\n    struct edge {\n        int to;\n\
    \        flow_t cap;\n        int rev;\n        bool isrev;\n    };\n\n    vector<vector<edge>>\
    \ graph;\n    vector<int> used;\n    const flow_t INF;\n    int timestamp;\n\n\
    \    explicit FordFulkerson(int V)\n        : graph(V),\n          used(V, -1),\n\
    \          INF(numeric_limits<flow_t>::max()),\n          timestamp(0) {}\n\n\
    \    void add_edge(int from, int to, flow_t cap) {\n        graph[from].push_back(edge{to,\
    \ cap, (int)graph[to].size(), false});\n        graph[to].push_back(edge{from,\
    \ 0, (int)graph[from].size() - 1, false});\n    }\n\n    flow_t dfs(int idx, const\
    \ int t, flow_t flow) {\n        if(idx == t) return flow;\n        used[idx]\
    \ = timestamp;\n        for(auto &&e : graph[idx])\n            if(e.cap > 0 &&\
    \ used[e.to] != timestamp) {\n                flow_t d = dfs(e.to, t, min(flow,\
    \ e.cap));\n                if(d > 0) {\n                    e.cap -= d;\n   \
    \                 graph[e.to][e.rev].cap += d;\n                    return d;\n\
    \                }\n            }\n        return 0;\n    }\n\n    flow_t max_flow(int\
    \ s, int t) {\n        flow_t flow = 0;\n        for(flow_t f; (f = dfs(s, t,\
    \ INF)) > 0; timestamp++) flow += f;\n        return flow;\n    }\n};\n/*\n *\
    \ @brief Ford-Fulkerson\n * @docs docs/ford-fulkerson.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: graph/ford-fulkerson.cpp
  requiredBy: []
  timestamp: '2021-06-20 12:34:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-GRL-6-A.test.cpp
documentation_of: graph/ford-fulkerson.cpp
layout: document
redirect_from:
- /library/graph/ford-fulkerson.cpp
- /library/graph/ford-fulkerson.cpp.html
title: Ford-Fulkerson
---
## 説明

- `FordFulkerson(V)`: 頂点数 $V$ で初期化
- `add_edge(from, to, cap)`: `from` から `to` に容量 `cap` の辺を張る
- `max_flow(s, t)`: $s$ から $t$ への max_flow

## 計算量

$O(FE)$