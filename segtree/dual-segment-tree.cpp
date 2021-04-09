#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, class F, S (*mapping)(F, S), F (*composition)(F, F),
          F (*id)()>
class DualSegmentTree {
    int _n, sz, lg;
    vector<S> data;
    vector<F> lazy;

    void _push(int k, F f) {
        if(k < sz)
            lazy[k] = composition(f, lazy[k]);
        else
            data[k - sz] = mapping(f, data[k - sz]);
    }
    void push(int k) {
        _push(k << 1, lazy[k]);
        _push(k << 1 | 1, lazy[k]);
        lazy[k] = id();
    }

public:
    DualSegmentTree() = default;
    explicit DualSegmentTree(const vector<S>& v) : _n(v.size()) {
        lg = 0;
        while(1U << lg < (uint)_n) lg++;
        sz = 1 << lg;
        data = v;
        data.resize(sz);
        lazy.assign(sz, id());
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += sz;
        for(int i = lg; i >= 1; i--) push(p >> i);
        data[p - sz] = x;
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += sz;
        for(int i = lg; i >= 1; i--) push(p >> i);
        return data[p - sz];
    }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += sz;
        for(int i = lg; i >= 1; i--) push(p >> i);
        data[p - sz] = mapping(f, data[p]);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;
        l += sz;
        r += sz;

        for(int i = lg; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        while(l < r) {
            if(l & 1) _push(l++, f);
            if(r & 1) _push(--r, f);
            l >>= 1;
            r >>= 1;
        }
    }
};
/*
 * @brief Dual-Segment-Tree
 * @docs docs/dual-segment-tree.md
 */