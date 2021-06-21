---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-GRL-6-A-2.test.cpp
    title: test/AOJ-GRL-6-A-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dinic.md
    document_title: Dinic
    links: []
  bundledCode: "#line 2 \"graph/dinic.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename flow_t>\nstruct Dinic {\n    const flow_t INF;\n\
    \    struct edge {\n        int to, rev;\n        flow_t cap;\n    };\n    vector<vector<edge>>\
    \ graph;\n    vector<int> min_cost, iter;\n\n    explicit Dinic(int V) : INF(numeric_limits<flow_t>::max()),\
    \ graph(V) {}\n\n    void add_edge(int from, int to, flow_t cap) {\n        graph[from].push_back(edge{to,\
    \ (int)graph[to].size(), cap});\n        graph[to].push_back(edge{from, (int)graph[from].size()\
    \ - 1, 0});\n    }\n\n    bool bfs(int s, int t) {\n        min_cost.assign(graph.size(),\
    \ -1);\n        queue<int> que;\n        min_cost[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty() && min_cost[t] == -1) {\n            int p = que.front();\n\
    \            que.pop();\n            for(auto &&e : graph[p])\n              \
    \  if(e.cap > 0 && min_cost[e.to] == -1) {\n                    min_cost[e.to]\
    \ = min_cost[p] + 1;\n                    que.push(e.to);\n                }\n\
    \        }\n        return min_cost[t] != -1;\n    }\n\n    flow_t dfs(int idx,\
    \ int t, flow_t flow) {\n        if(idx == t) return flow;\n        for(int &i\
    \ = iter[idx]; i < graph[idx].size(); i++) {\n            edge &e = graph[idx][i];\n\
    \            if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {\n             \
    \   flow_t d = dfs(e.to, t, min(flow, e.cap));\n                if(d > 0) {\n\
    \                    e.cap -= d;\n                    graph[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n\n    flow_t max_flow(int s, int t) {\n      \
    \  flow_t flow = 0;\n        while(bfs(s, t)) {\n            iter.assign(graph.size(),\
    \ 0);\n            flow_t f = 0;\n            while((f = dfs(s, t, INF)) > 0)\
    \ flow += f;\n        }\n        return flow;\n    }\n};\n/*\n * @brief Dinic\n\
    \ * @docs docs/dinic.md\n */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename flow_t>\nstruct Dinic {\n    const flow_t INF;\n    struct edge {\n\
    \        int to, rev;\n        flow_t cap;\n    };\n    vector<vector<edge>> graph;\n\
    \    vector<int> min_cost, iter;\n\n    explicit Dinic(int V) : INF(numeric_limits<flow_t>::max()),\
    \ graph(V) {}\n\n    void add_edge(int from, int to, flow_t cap) {\n        graph[from].push_back(edge{to,\
    \ (int)graph[to].size(), cap});\n        graph[to].push_back(edge{from, (int)graph[from].size()\
    \ - 1, 0});\n    }\n\n    bool bfs(int s, int t) {\n        min_cost.assign(graph.size(),\
    \ -1);\n        queue<int> que;\n        min_cost[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty() && min_cost[t] == -1) {\n            int p = que.front();\n\
    \            que.pop();\n            for(auto &&e : graph[p])\n              \
    \  if(e.cap > 0 && min_cost[e.to] == -1) {\n                    min_cost[e.to]\
    \ = min_cost[p] + 1;\n                    que.push(e.to);\n                }\n\
    \        }\n        return min_cost[t] != -1;\n    }\n\n    flow_t dfs(int idx,\
    \ int t, flow_t flow) {\n        if(idx == t) return flow;\n        for(int &i\
    \ = iter[idx]; i < graph[idx].size(); i++) {\n            edge &e = graph[idx][i];\n\
    \            if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {\n             \
    \   flow_t d = dfs(e.to, t, min(flow, e.cap));\n                if(d > 0) {\n\
    \                    e.cap -= d;\n                    graph[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n\n    flow_t max_flow(int s, int t) {\n      \
    \  flow_t flow = 0;\n        while(bfs(s, t)) {\n            iter.assign(graph.size(),\
    \ 0);\n            flow_t f = 0;\n            while((f = dfs(s, t, INF)) > 0)\
    \ flow += f;\n        }\n        return flow;\n    }\n};\n/*\n * @brief Dinic\n\
    \ * @docs docs/dinic.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy: []
  timestamp: '2021-06-21 20:58:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-GRL-6-A-2.test.cpp
documentation_of: graph/dinic.cpp
layout: document
redirect_from:
- /library/graph/dinic.cpp
- /library/graph/dinic.cpp.html
title: Dinic
---
## 説明

最大流

- `Dinic(V)`: 頂点数 $V$ で初期化
- `add_edge(from, to, cap)`: `from` から `to` に容量 `cap` の辺を張る
- `max_flow(s, t)`: $s$ から $t$ への max_flow

## 計算量

- 最悪計算量: $O(EV^2)$
- 殆どのケースではかなり高速