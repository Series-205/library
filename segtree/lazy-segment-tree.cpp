#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
class LazySegmentTree {
private:
    int _n, sz, lg;
    vector<S> data;
    vector<F> lazy;

    void calc(int k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }
    void all_apply(int k, F f) {
        data[k] = mapping(f, data[k]);
        if(k < sz) lazy[k] = composition(f, lazy[k]);
    }
    void push(int k) {
        all_apply(k << 1, lazy[k]);
        all_apply(k << 1 | 1, lazy[k]);
        lazy[k] = id();
    }

public:
    LazySegmentTree() = default;
    explicit LazySegmentTree(int n) : LazySegmentTree(vector<S>(n, e())) {}
    explicit LazySegmentTree(const vector<S>& v) : _n(v.size()) {
        lg = 0;
        while((1U << lg) < (uint)_n) lg++;
        sz = 1 << lg;
        data.assign(sz << 1, e());
        lazy.assign(sz, id());
        for(int i = 0; i < _n; i++) data[sz + i] = v[i];
        for(int i = sz - 1; i >= 1; i--) calc(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += sz;
        for(int i = lg; i >= 1; i--) push(p >> i);
        data[p] = x;
        for(int i = 1; i <= lg; i++) calc(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += sz;
        for(int i = lg; i >= 1; i--) push(p >> i);
        return data[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return e();
        l += sz;
        r += sz;

        for(int i = lg; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push(r >> i);
        }

        S sl = e(), sr = e();
        while(l < r) {
            if(l & 1) sl = op(sl, data[l++]);
            if(r & 1) sr = op(data[--r], sr);
            l >>= 1;
            r >>= 1;
        }

        return op(sl, sr);
    }

    S all_prod() { return data[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += sz;
        for(int i = lg; i >= 1; i--) push(p >> i);
        data[p] = mapping(f, data[p]);
        for(int i = 1; i <= lg; i++) calc(p >> i);
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

        {
            int _l = l, _r = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = _l;
            r = _r;
        }

        for(int i = 1; i <= lg; i++) {
            if(((l >> i) << i) != l) calc(l >> i);
            if(((r >> i) << i) != r) calc((r - 1) >> i);
        }
    }
};
/*
 * @brief Lazy-Segment-Tree
 * @docs docs/lazy-segment-tree.md
 */