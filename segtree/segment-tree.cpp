#pragma once
#include <bits/stdc++.h>
using namespace std;

// モノイド, 演算, 単位元
template <typename S, S (*op)(S, S), S (*e)()>
class SegmentTree {
private:
    int _n, sz;
    vector<S> data;

    void calc(int k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }

public:
    SegmentTree() = default;
    explicit SegmentTree(int n) : SegmentTree(vector<S>(n, e())) {}
    explicit SegmentTree(const vector<S>& v) : _n(v.size()) {
        sz = 1;
        while(sz < _n) sz <<= 1;
        data.assign(sz << 1, e());
        for(int i = 0; i < _n; i++) data[sz + i] = v[i];
        for(int i = sz - 1; i >= 1; i--) calc(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += sz;
        data[p] = x;
        while(p >>= 1) calc(p);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return data[p + sz];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sl = e(), sr = e();
        l += sz;
        r += sz;
        while(l < r) {
            if(l & 1) sl = op(sl, data[l++]);
            if(r & 1) sr = op(data[--r], sr);
            l >>= 1;
            r >>= 1;
        }
        return op(sl, sr);
    }

    S all_prod() { return data[1]; }
};