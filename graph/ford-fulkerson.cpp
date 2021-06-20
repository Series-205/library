#pragma once

#include <bits/stdc++.h>
using namespace std;

template <typename flow_t>
struct FordFulkerson {
    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
    };

    vector<vector<edge>> graph;
    vector<int> used;
    const flow_t INF;
    int timestamp;

    explicit FordFulkerson(int V)
        : graph(V),
          used(V, -1),
          INF(numeric_limits<flow_t>::max()),
          timestamp(0) {}

    void add_edge(int from, int to, flow_t cap) {
        graph[from].push_back(edge{to, cap, (int)graph[to].size(), false});
        graph[to].push_back(edge{from, 0, (int)graph[from].size() - 1, false});
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if(idx == t) return flow;
        used[idx] = timestamp;
        for(auto &&e : graph[idx])
            if(e.cap > 0 && used[e.to] != timestamp) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        for(flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++) flow += f;
        return flow;
    }
};
/*
 * @brief Ford-Fulkerson
 * @docs docs/ford-fulkerson.md
 */