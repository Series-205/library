---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/ford-fulkerson.cpp
    title: Ford-Fulkerson
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/AOJ-GRL-6-A.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/ford-fulkerson.cpp\"\
    \n\n#line 4 \"graph/ford-fulkerson.cpp\"\nusing namespace std;\n\ntemplate <typename\
    \ flow_t>\nstruct FordFulkerson {\n    struct edge {\n        int to;\n      \
    \  flow_t cap;\n        int rev;\n        bool isrev;\n    };\n\n    vector<vector<edge>>\
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
    \ @brief Ford-Fulkerson\n * @docs docs/ford-fulkerson.md\n */\n#line 8 \"test/AOJ-GRL-6-A.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int V, E;\n    cin >> V >> E;\n\n    FordFulkerson<int> g(V);\n    for(int\
    \ i = 0; i < E; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n  \
    \      g.add_edge(a, b, c);\n    }\n\n    cout << g.max_flow(0, V - 1) << endl;\n\
    }\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../graph/ford-fulkerson.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int V, E;\n    cin >> V >> E;\n\n    FordFulkerson<int> g(V);\n    for(int\
    \ i = 0; i < E; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n  \
    \      g.add_edge(a, b, c);\n    }\n\n    cout << g.max_flow(0, V - 1) << endl;\n\
    }"
  dependsOn:
  - graph/ford-fulkerson.cpp
  isVerificationFile: true
  path: test/AOJ-GRL-6-A.test.cpp
  requiredBy: []
  timestamp: '2021-06-20 12:34:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-GRL-6-A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-GRL-6-A.test.cpp
- /verify/test/AOJ-GRL-6-A.test.cpp.html
title: test/AOJ-GRL-6-A.test.cpp
---
