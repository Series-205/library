---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/xor_convolution.cpp
    title: convolution/xor_convolution.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/yosupo-bitwise_xor_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"convolution/xor_convolution.cpp\"\
    \nusing namespace std;\n\nclass xorConvolution {\n    template <typename T>\n\
    \    static void FWT(vector<T>& f) {\n        int n = f.size();\n        for(int\
    \ i = 1; i < n; i <<= 1)\n            for(int j = 0; j < n; j++)\n           \
    \     if((j & i) == 0) {\n                    T x = f[j], y = f[j | i];\n    \
    \                f[j] = x + y, f[j | i] = x - y;\n                }\n    }\n\n\
    public:\n    template <typename T>\n    static vector<T> convolution(vector<T>\
    \ f, vector<T> g) {\n        int sz = 1, n = max(f.size(), g.size());\n      \
    \  while(sz < n) sz <<= 1;\n        f.resize(sz);\n        g.resize(sz);\n   \
    \     FWT(f);\n        FWT(g);\n        for(int i = 0; i < sz; i++) f[i] *= g[i];\n\
    \        FWT(f);\n        for(int i = 0; i < sz; i++) f[i] /= sz;\n        return\
    \ f;\n    }\n};\n#line 7 \"test/yosupo-bitwise_xor_convolution.test.cpp\"\n\n\
    template <int M>\nclass ModInt {\n    int x;\n\npublic:\n    constexpr ModInt()\
    \ : x(0) {}\n    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) %\
    \ M) % M) {}\n    constexpr ModInt &operator+=(const ModInt p) {\n        if((x\
    \ += p.x) >= M) x -= M;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const\
    \ ModInt p) {\n        if((x += M - p.x) >= M) x -= M;\n        return *this;\n\
    \    }\n    constexpr ModInt &operator*=(const ModInt p) {\n        x = (int)(1LL\
    \ * x * p.x % M);\n        return *this;\n    }\n    constexpr ModInt &operator/=(const\
    \ ModInt p) {\n        *this *= p.inverse();\n        return *this;\n    }\n \
    \   constexpr ModInt operator-() const { return ModInt(-x); }\n    constexpr ModInt\
    \ operator+(const ModInt p) const {\n        return ModInt(*this) += p;\n    }\n\
    \    constexpr ModInt operator-(const ModInt p) const {\n        return ModInt(*this)\
    \ -= p;\n    }\n    constexpr ModInt operator*(const ModInt p) const {\n     \
    \   return ModInt(*this) *= p;\n    }\n    constexpr ModInt operator/(const ModInt\
    \ p) const {\n        return ModInt(*this) /= p;\n    }\n    constexpr bool operator==(const\
    \ ModInt p) const { return x == p.x; }\n    constexpr bool operator!=(const ModInt\
    \ p) const { return x != p.x; }\n    constexpr ModInt inverse() const {\n    \
    \    int a = x, b = M, u = 1, v = 0, t = 0;\n        while(b > 0) {\n        \
    \    t = a / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v,\
    \ v);\n        }\n        return ModInt(u);\n    }\n    constexpr ModInt pow(int64_t\
    \ k) const {\n        ModInt ret(1), mul(x);\n        while(k > 0) {\n       \
    \     if(k & 1) ret *= mul;\n            mul *= mul;\n            k >>= 1;\n \
    \       }\n        return ret;\n    }\n    constexpr friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    constexpr friend\
    \ istream &operator>>(istream &is, ModInt &a) {\n        int64_t t = 0;\n    \
    \    is >> t;\n        a = ModInt(t);\n        return (is);\n    }\n};\nusing\
    \ mint = ModInt<998244353>;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n;\n    cin >> n;\n    vector<mint> a(1 << n), b(1 << n);\n    for(int\
    \ i = 0; i < 1 << n; i++) cin >> a[i];\n    for(int i = 0; i < 1 << n; i++) cin\
    \ >> b[i];\n\n    auto ans = xorConvolution::convolution(a, b);\n    for(int i\
    \ = 0; i < 1 << n; i++) cout << ans[i] << \" \\n\"[(i + 1) == 1 << n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../convolution/xor_convolution.cpp\"\
    \n\ntemplate <int M>\nclass ModInt {\n    int x;\n\npublic:\n    constexpr ModInt()\
    \ : x(0) {}\n    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) %\
    \ M) % M) {}\n    constexpr ModInt &operator+=(const ModInt p) {\n        if((x\
    \ += p.x) >= M) x -= M;\n        return *this;\n    }\n    constexpr ModInt &operator-=(const\
    \ ModInt p) {\n        if((x += M - p.x) >= M) x -= M;\n        return *this;\n\
    \    }\n    constexpr ModInt &operator*=(const ModInt p) {\n        x = (int)(1LL\
    \ * x * p.x % M);\n        return *this;\n    }\n    constexpr ModInt &operator/=(const\
    \ ModInt p) {\n        *this *= p.inverse();\n        return *this;\n    }\n \
    \   constexpr ModInt operator-() const { return ModInt(-x); }\n    constexpr ModInt\
    \ operator+(const ModInt p) const {\n        return ModInt(*this) += p;\n    }\n\
    \    constexpr ModInt operator-(const ModInt p) const {\n        return ModInt(*this)\
    \ -= p;\n    }\n    constexpr ModInt operator*(const ModInt p) const {\n     \
    \   return ModInt(*this) *= p;\n    }\n    constexpr ModInt operator/(const ModInt\
    \ p) const {\n        return ModInt(*this) /= p;\n    }\n    constexpr bool operator==(const\
    \ ModInt p) const { return x == p.x; }\n    constexpr bool operator!=(const ModInt\
    \ p) const { return x != p.x; }\n    constexpr ModInt inverse() const {\n    \
    \    int a = x, b = M, u = 1, v = 0, t = 0;\n        while(b > 0) {\n        \
    \    t = a / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v,\
    \ v);\n        }\n        return ModInt(u);\n    }\n    constexpr ModInt pow(int64_t\
    \ k) const {\n        ModInt ret(1), mul(x);\n        while(k > 0) {\n       \
    \     if(k & 1) ret *= mul;\n            mul *= mul;\n            k >>= 1;\n \
    \       }\n        return ret;\n    }\n    constexpr friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    constexpr friend\
    \ istream &operator>>(istream &is, ModInt &a) {\n        int64_t t = 0;\n    \
    \    is >> t;\n        a = ModInt(t);\n        return (is);\n    }\n};\nusing\
    \ mint = ModInt<998244353>;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n;\n    cin >> n;\n    vector<mint> a(1 << n), b(1 << n);\n    for(int\
    \ i = 0; i < 1 << n; i++) cin >> a[i];\n    for(int i = 0; i < 1 << n; i++) cin\
    \ >> b[i];\n\n    auto ans = xorConvolution::convolution(a, b);\n    for(int i\
    \ = 0; i < 1 << n; i++) cout << ans[i] << \" \\n\"[(i + 1) == 1 << n];\n}"
  dependsOn:
  - convolution/xor_convolution.cpp
  isVerificationFile: true
  path: test/yosupo-bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-10-02 08:42:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-bitwise_xor_convolution.test.cpp
- /verify/test/yosupo-bitwise_xor_convolution.test.cpp.html
title: test/yosupo-bitwise_xor_convolution.test.cpp
---
