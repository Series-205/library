---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/dual-segment-tree.cpp
    title: Dual-Segment-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/AOJ-DLS-2-D.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"segtree/dual-segment-tree.cpp\"\
    \nusing namespace std;\n\ntemplate <class S, class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F),\n          F (*id)()>\nclass DualSegmentTree {\n    int _n, sz, lg;\n  \
    \  vector<S> data;\n    vector<F> lazy;\n\n    void _push(int k, F f) {\n    \
    \    if(k < sz)\n            lazy[k] = composition(f, lazy[k]);\n        else\n\
    \            data[k - sz] = mapping(f, data[k - sz]);\n    }\n    void push(int\
    \ k) {\n        _push(k << 1, lazy[k]);\n        _push(k << 1 | 1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\n\npublic:\n    DualSegmentTree() = default;\n\
    \    explicit DualSegmentTree(const vector<S>& v) : _n(v.size()) {\n        lg\
    \ = 0;\n        while(1U << lg < (uint)_n) lg++;\n        sz = 1 << lg;\n    \
    \    data = v;\n        data.resize(sz);\n        lazy.assign(sz, id());\n   \
    \ }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n       \
    \ p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n        data[p\
    \ - sz] = x;\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        p += sz;\n        for(int i = lg; i >= 1; i--) push(p >> i);\n      \
    \  return data[p - sz];\n    }\n\n    void apply(int p, F f) {\n        assert(0\
    \ <= p && p < _n);\n        p += sz;\n        for(int i = lg; i >= 1; i--) push(p\
    \ >> i);\n        data[p - sz] = mapping(f, data[p]);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l\
    \ == r) return;\n        l += sz;\n        r += sz;\n\n        for(int i = lg;\
    \ i >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n       \
    \     if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        while(l\
    \ < r) {\n            if(l & 1) _push(l++, f);\n            if(r & 1) _push(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n};\n/*\n\
    \ * @brief Dual-Segment-Tree\n * @docs docs/dual-segment-tree.md\n */\n#line 8\
    \ \"test/AOJ-DLS-2-D.test.cpp\"\n\nusing S = int;\nusing F = int;\nF id() { return\
    \ -1; }\nS mapping(F f, S s) { return f == id() ? s : f; }\nF composition(F f,\
    \ F g) { return f == id() ? g : f; }\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q;\n    cin >> n >> q;\n\n   \
    \ DualSegmentTree<S, F, mapping, composition, id> seg(vector<S>(n, INT_MAX));\n\
    \n    for(int i = 0; i < q; i++) {\n        int t;\n        cin >> t;\n      \
    \  if(t) {\n            int p;\n            cin >> p;\n            cout << seg.get(p)\
    \ << \"\\n\";\n        } else {\n            int l, r, x;\n            cin >>\
    \ l >> r >> x;\n            seg.apply(l, r + 1, x);\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../segtree/dual-segment-tree.cpp\"\
    \n\nusing S = int;\nusing F = int;\nF id() { return -1; }\nS mapping(F f, S s)\
    \ { return f == id() ? s : f; }\nF composition(F f, F g) { return f == id() ?\
    \ g : f; }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    cin >> n >> q;\n\n    DualSegmentTree<S, F, mapping, composition,\
    \ id> seg(vector<S>(n, INT_MAX));\n\n    for(int i = 0; i < q; i++) {\n      \
    \  int t;\n        cin >> t;\n        if(t) {\n            int p;\n          \
    \  cin >> p;\n            cout << seg.get(p) << \"\\n\";\n        } else {\n \
    \           int l, r, x;\n            cin >> l >> r >> x;\n            seg.apply(l,\
    \ r + 1, x);\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - segtree/dual-segment-tree.cpp
  isVerificationFile: true
  path: test/AOJ-DLS-2-D.test.cpp
  requiredBy: []
  timestamp: '2021-04-09 16:57:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DLS-2-D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DLS-2-D.test.cpp
- /verify/test/AOJ-DLS-2-D.test.cpp.html
title: test/AOJ-DLS-2-D.test.cpp
---
