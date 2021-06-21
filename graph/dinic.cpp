#pragma once

#include <bits/stdc++.h>
using namespace std;

template <typename flow_t>
struct Dinic {
    const flow_t INF;
    struct edge {
        int to, rev;
        flow_t cap;
    };
    vector<vector<edge>> graph;
    vector<int> min_cost, iter;

    explicit Dinic(int V) : INF(numeric_limits<flow_t>::max()), graph(V) {}

    void add_edge(int from, int to, flow_t cap) {
        graph[from].push_back(edge{to, (int)graph[to].size(), cap});
        graph[to].push_back(edge{from, (int)graph[from].size() - 1, 0});
    }

    bool bfs(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while(!que.empty() && min_cost[t] == -1) {
            int p = que.front();
            que.pop();
            for(auto &&e : graph[p])
                if(e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, int t, flow_t flow) {
        if(idx == t) return flow;
        for(int &i = iter[idx]; i < graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        while(bfs(s, t)) {
            iter.assign(graph.size(), 0);
            flow_t f = 0;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};
/*
 * @brief Dinic
 * @docs docs/dinic.md
 */