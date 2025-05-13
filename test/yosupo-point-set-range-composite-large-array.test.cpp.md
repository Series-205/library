---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/modint.cpp
    title: modint/modint.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/dynamic-segment-tree.cpp
    title: segtree/dynamic-segment-tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "#line 1 \"test/yosupo-point-set-range-composite-large-array.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"modint/modint.cpp\"\
    \n\ntemplate <long long MOD>\nstruct Modint {\n    long long x;\n    Modint(long\
    \ long x_ = 0) : x(x_ % MOD) {\n        if(x < 0) x += MOD;\n    }\n    friend\
    \ Modint operator+(Modint a, Modint b) { return a.x + b.x; }\n    friend Modint\
    \ operator-(Modint a, Modint b) { return a.x - b.x; }\n    friend Modint operator*(Modint\
    \ a, Modint b) { return a.x * b.x; }\n    friend Modint operator/(Modint a, Modint\
    \ b) { return a * b.inv(); }\n    // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift +\
    \ \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n    friend\
    \ Modint& operator+=(Modint& a, Modint b) { return a = a.x + b.x; }\n    friend\
    \ Modint& operator-=(Modint& a, Modint b) { return a = a.x - b.x; }\n    friend\
    \ Modint& operator*=(Modint& a, Modint b) { return a = a.x * b.x; }\n    friend\
    \ Modint& operator/=(Modint& a, Modint b) { return a = a * b.inv(); }\n    Modint\
    \ inv() const { return pow(MOD - 2); }\n    Modint pow(long long b) const {\n\
    \        Modint a = *this, c = 1;\n        while(b) {\n            if(b & 1) c\
    \ *= a;\n            a *= a;\n            b >>= 1;\n        }\n        return\
    \ c;\n    }\n};\n#line 2 \"segtree/dynamic-segment-tree.cpp\"\n\ntemplate <typename\
    \ S, S (*op)(S, S), S (*e)(), long long WORD>\nstruct DynamicSegTree {\n    void\
    \ set(long long p, S x) { set(p, WORD - 1, x); }\n    S get(long long p) { return\
    \ get(p, WORD - 1); }\n    S all_prod() { return data; }\n    S prod(long long\
    \ l, long long r) { return prod(l, r, 0, 1LL << WORD); }\n\n    DynamicSegTree()\
    \ : data(e()) { cld[0] = cld[1] = nullptr; }\n\nprivate:\n    DynamicSegTree *cld[2];\n\
    \    S data;\n\n    DynamicSegTree *child(long long bit) {\n        if(cld[bit]\
    \ == nullptr) {\n            cld[bit] = new DynamicSegTree();\n        }\n   \
    \     return cld[bit];\n    }\n    S child_data(long long bit) {\n        if(cld[bit]\
    \ == nullptr)\n            return e();\n        else\n            return cld[bit]->data;\n\
    \    }\n\n    void update() { data = op(child_data(0), child_data(1)); }\n\n \
    \   void set(long long p, long long digit, S x) {\n        if(digit == -1) {\n\
    \            data = x;\n        } else {\n            long long bit = p >> digit\
    \ & 1;\n            child(bit)->set(p, digit - 1, x);\n            update();\n\
    \        }\n    }\n\n    S get(long long p, long long digit) {\n        if(digit\
    \ == -1) {\n            return data;\n        } else {\n            long long\
    \ bit = p >> digit & 1;\n            if(cld[bit] == nullptr)\n               \
    \ return e();\n            else\n                return cld[bit]->get(p, digit\
    \ - 1);\n        }\n    }\n\n    S prod(long long L, long long R, long long l,\
    \ long long r) {\n        if(r <= L || R <= l) {\n            return e();\n  \
    \      } else if(L <= l && r <= R) {\n            return data;\n        } else\
    \ {\n            S res = e();\n            if(cld[0] != nullptr) res = cld[0]->prod(L,\
    \ R, l, (l + r) / 2);\n            if(cld[1] != nullptr)\n                res\
    \ = op(res, cld[1]->prod(L, R, (l + r) / 2, r));\n            return res;\n  \
    \      }\n    }\n};\n#line 9 \"test/yosupo-point-set-range-composite-large-array.test.cpp\"\
    \n\nusing mint = Modint<998244353>;\nusing ll = long long;\n\nstruct S {\n   \
    \ mint a, b;\n    mint f(mint x) { return a * x + b; }\n};\nS op(S l, S r) { return\
    \ S{l.a * r.a, l.b * r.a + r.b}; }\nS e() { return S{1, 0}; }\n\nint main() {\n\
    \    ll n, q;\n    cin >> n >> q;\n\n    DynamicSegTree<S, op, e, 30> seg;\n \
    \   while(q--) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n  \
    \          ll p, c, d;\n            cin >> p >> c >> d;\n            seg.set(p,\
    \ S{c, d});\n        } else {\n            ll l, r, x;\n            cin >> l >>\
    \ r >> x;\n            cout << seg.prod(l, r).f(x).x << endl;\n        }\n   \
    \ }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../modint/modint.cpp\"\
    \n#include \"../segtree/dynamic-segment-tree.cpp\"\n\nusing mint = Modint<998244353>;\n\
    using ll = long long;\n\nstruct S {\n    mint a, b;\n    mint f(mint x) { return\
    \ a * x + b; }\n};\nS op(S l, S r) { return S{l.a * r.a, l.b * r.a + r.b}; }\n\
    S e() { return S{1, 0}; }\n\nint main() {\n    ll n, q;\n    cin >> n >> q;\n\n\
    \    DynamicSegTree<S, op, e, 30> seg;\n    while(q--) {\n        int t;\n   \
    \     cin >> t;\n        if(t == 0) {\n            ll p, c, d;\n            cin\
    \ >> p >> c >> d;\n            seg.set(p, S{c, d});\n        } else {\n      \
    \      ll l, r, x;\n            cin >> l >> r >> x;\n            cout << seg.prod(l,\
    \ r).f(x).x << endl;\n        }\n    }\n}"
  dependsOn:
  - modint/modint.cpp
  - segtree/dynamic-segment-tree.cpp
  isVerificationFile: true
  path: test/yosupo-point-set-range-composite-large-array.test.cpp
  requiredBy: []
  timestamp: '2025-05-13 23:36:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-point-set-range-composite-large-array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-point-set-range-composite-large-array.test.cpp
- /verify/test/yosupo-point-set-range-composite-large-array.test.cpp.html
title: test/yosupo-point-set-range-composite-large-array.test.cpp
---
