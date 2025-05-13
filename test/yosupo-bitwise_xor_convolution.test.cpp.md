---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/xor_convolution.cpp
    title: convolution/xor_convolution.cpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.cpp
    title: modint/modint.cpp
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
    \ f;\n    }\n};\n#line 2 \"modint/modint.cpp\"\n\ntemplate <long long MOD>\nstruct\
    \ Modint {\n    long long x;\n    Modint(long long x_ = 0) : x(x_ % MOD) {\n \
    \       if(x < 0) x += MOD;\n    }\n    friend Modint operator+(Modint a, Modint\
    \ b) { return a.x + b.x; }\n    friend Modint operator-(Modint a, Modint b) {\
    \ return a.x - b.x; }\n    friend Modint operator*(Modint a, Modint b) { return\
    \ a.x * b.x; }\n    friend Modint operator/(Modint a, Modint b) { return a * b.inv();\
    \ }\n    // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\
    \u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n    friend Modint& operator+=(Modint&\
    \ a, Modint b) { return a = a.x + b.x; }\n    friend Modint& operator-=(Modint&\
    \ a, Modint b) { return a = a.x - b.x; }\n    friend Modint& operator*=(Modint&\
    \ a, Modint b) { return a = a.x * b.x; }\n    friend Modint& operator/=(Modint&\
    \ a, Modint b) { return a = a * b.inv(); }\n    Modint inv() const { return pow(MOD\
    \ - 2); }\n    Modint pow(long long b) const {\n        Modint a = *this, c =\
    \ 1;\n        while(b) {\n            if(b & 1) c *= a;\n            a *= a;\n\
    \            b >>= 1;\n        }\n        return c;\n    }\n};\n#line 8 \"test/yosupo-bitwise_xor_convolution.test.cpp\"\
    \n\nusing mint = Modint<998244353>;\n\nint main() {\n    cin.tie(nullptr);\n \
    \   ios::sync_with_stdio(false);\n\n    int n;\n    cin >> n;\n    vector<mint>\
    \ a(1 << n), b(1 << n);\n    for(int i = 0; i < 1 << n; i++) {\n        long long\
    \ in;\n        cin >> in;\n        a[i] = in;\n    }\n    for(int i = 0; i < 1\
    \ << n; i++) {\n        long long in;\n        cin >> in;\n        b[i] = in;\n\
    \    }\n\n    auto ans = xorConvolution::convolution(a, b);\n    for(int i = 0;\
    \ i < 1 << n; i++)\n        cout << ans[i].x << \" \\n\"[(i + 1) == 1 << n];\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../convolution/xor_convolution.cpp\"\
    \n#include \"../modint/modint.cpp\"\n\nusing mint = Modint<998244353>;\n\nint\
    \ main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int\
    \ n;\n    cin >> n;\n    vector<mint> a(1 << n), b(1 << n);\n    for(int i = 0;\
    \ i < 1 << n; i++) {\n        long long in;\n        cin >> in;\n        a[i]\
    \ = in;\n    }\n    for(int i = 0; i < 1 << n; i++) {\n        long long in;\n\
    \        cin >> in;\n        b[i] = in;\n    }\n\n    auto ans = xorConvolution::convolution(a,\
    \ b);\n    for(int i = 0; i < 1 << n; i++)\n        cout << ans[i].x << \" \\\
    n\"[(i + 1) == 1 << n];\n}"
  dependsOn:
  - convolution/xor_convolution.cpp
  - modint/modint.cpp
  isVerificationFile: true
  path: test/yosupo-bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-05-13 23:36:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-bitwise_xor_convolution.test.cpp
- /verify/test/yosupo-bitwise_xor_convolution.test.cpp.html
title: test/yosupo-bitwise_xor_convolution.test.cpp
---
