#pragma once

template <long long MOD>
struct Modint {
    long long x;
    Modint(long long x_ = 0) : x(x_ % MOD) {
        if(x < 0) x += MOD;
    }
    friend Modint operator+(Modint a, Modint b) { return a.x + b.x; }
    friend Modint operator-(Modint a, Modint b) { return a.x - b.x; }
    friend Modint operator*(Modint a, Modint b) { return a.x * b.x; }
    friend Modint operator/(Modint a, Modint b) { return a * b.inv(); }
    // 4 行コピペ  Alt + Shift + クリックで複数カーソル
    friend Modint& operator+=(Modint& a, Modint b) { return a = a.x + b.x; }
    friend Modint& operator-=(Modint& a, Modint b) { return a = a.x - b.x; }
    friend Modint& operator*=(Modint& a, Modint b) { return a = a.x * b.x; }
    friend Modint& operator/=(Modint& a, Modint b) { return a = a * b.inv(); }
    Modint inv() const { return pow(MOD - 2); }
    Modint pow(long long b) const {
        Modint a = *this, c = 1;
        while(b) {
            if(b & 1) c *= a;
            a *= a;
            b >>= 1;
        }
        return c;
    }
};