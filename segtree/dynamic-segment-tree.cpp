#pragma once

template <typename S, S (*op)(S, S), S (*e)(), long long WORD>
struct DynamicSegTree {
    void set(long long p, S x) { set(p, WORD - 1, x); }
    S get(long long p) { return get(p, WORD - 1); }
    S all_prod() { return data; }
    S prod(long long l, long long r) { return prod(l, r, 0, 1LL << WORD); }

    DynamicSegTree() : data(e()) { cld[0] = cld[1] = nullptr; }

private:
    DynamicSegTree *cld[2];
    S data;

    DynamicSegTree *child(long long bit) {
        if(cld[bit] == nullptr) {
            cld[bit] = new DynamicSegTree();
        }
        return cld[bit];
    }
    S child_data(long long bit) {
        if(cld[bit] == nullptr)
            return e();
        else
            return cld[bit]->data;
    }

    void update() { data = op(child_data(0), child_data(1)); }

    void set(long long p, long long digit, S x) {
        if(digit == -1) {
            data = x;
        } else {
            long long bit = p >> digit & 1;
            child(bit)->set(p, digit - 1, x);
            update();
        }
    }

    S get(long long p, long long digit) {
        if(digit == -1) {
            return data;
        } else {
            long long bit = p >> digit & 1;
            if(cld[bit] == nullptr)
                return e();
            else
                return cld[bit]->get(p, digit - 1);
        }
    }

    S prod(long long L, long long R, long long l, long long r) {
        if(r <= L || R <= l) {
            return e();
        } else if(L <= l && r <= R) {
            return data;
        } else {
            S res = e();
            if(cld[0] != nullptr) res = cld[0]->prod(L, R, l, (l + r) / 2);
            if(cld[1] != nullptr)
                res = op(res, cld[1]->prod(L, R, (l + r) / 2, r));
            return res;
        }
    }
};