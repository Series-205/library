#pragma once

#include <bits/stdc++.h>
using namespace std;

class RollingHash {
private:
    const uint64_t MOD = (1ull << 61) - 1;
    const uint64_t MASK30 = (1ull << 30) - 1;
    const uint64_t MASK31 = (1ull << 31) - 1;
    const uint64_t POSITIVIZER = MOD * 7;
    vector<uint64_t> power{1};
    uint64_t base = 0;

    inline uint64_t mul(uint64_t l, uint64_t r) {
        uint64_t lu = l >> 31;
        uint64_t ld = l & MASK31;
        uint64_t ru = r >> 31;
        uint64_t rd = r & MASK31;
        uint64_t mid = ld * ru + lu * rd;
        return ((lu * ru) << 1) + ld * rd + ((mid & MASK30) << 31) +
               (mid >> 30);
    }
    inline uint64_t calcMod(uint64_t x) {
        x = (x & MOD) + (x >> 61);
        if(x >= MOD) x -= MOD;
        return x;
    }
    inline uint64_t get_base() {
        random_device engine;
        uniform_int_distribution<uint64_t> dist(129, MOD - 1);
        return dist(engine);
    }
    inline uint64_t pow(size_t p) {
        if(power.size() <= p) {
            size_t sz = power.size();
            power.resize(p + 1);
            while(sz <= p) {
                power[sz] = calcMod(mul(power[sz - 1], base));
                sz++;
            }
        }
        return power[p];
    }

public:
    explicit RollingHash() : base(get_base()) {}
    vector<uint64_t> build(const string &s) {
        vector<uint64_t> hashed(s.size() + 1);
        for(size_t i = 0; i < s.size(); i++)
            hashed[i + 1] = calcMod(mul(hashed[i], base) + s[i]);
        return hashed;
    }
    inline uint64_t slice(const vector<uint64_t> &hashed, size_t l, size_t r) {
        return calcMod(hashed[r] + POSITIVIZER - mul(hashed[l], pow(r - l)));
    }
};