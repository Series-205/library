#pragma once

#include <bits/stdc++.h>
using namespace std;

class RollingHash {
private:
    const uint64_t MOD = (1ull << 61) - 1;
    vector<uint64_t> power{1};
    uint64_t base = 0;

    uint64_t mul(__uint128_t l, __uint128_t r) {
        __uint128_t t = l * r;
        t = (t >> 61) + (t & MOD);
        return t < MOD ? t : t - MOD;
    }
    uint64_t get_base() {
        random_device engine;
        uniform_int_distribution<uint64_t> dist(129, MOD - 1);
        return dist(engine);
    }
    uint64_t pow(size_t p) {
        if(power.size() <= p) {
            size_t sz = power.size();
            power.resize(p + 1);
            while(sz <= p) {
                power[sz] = mul(power[sz - 1], base);
                sz++;
            }
        }
        return power[p];
    }

public:
    explicit RollingHash() : base(get_base()) {}
    vector<uint64_t> build(const string &s) {
        vector<uint64_t> hashed(s.size() + 1);
        for(size_t i = 0; i < s.size(); i++) {
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if(hashed[i + 1] >= MOD) hashed[i + 1] -= MOD;
        }
        return hashed;
    }
    uint64_t slice(const vector<uint64_t> &hashed, size_t l, size_t r) {
        uint64_t res = hashed[r] + MOD - mul(hashed[l], pow(r - l));
        return res < MOD ? res : res - MOD;
    }
};