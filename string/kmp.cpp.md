---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-ALDS1-14-B.test.cpp
    title: test/AOJ-ALDS1-14-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/kmp.md
    document_title: KMP
    links: []
  bundledCode: "#line 2 \"string/kmp.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// Knuth-Morris-Pratt algorithm\nclass KMP {\nprivate:\n    static vector<int>\
    \ makeTable(const string &s) {\n        int n = s.size();\n        vector<int>\
    \ ret(n + 1);\n        int j = -1;\n        ret[0] = j;\n        for(int i = 0;\
    \ i < n; i++) {\n            while(j >= 0 && s[i] != s[j]) j = ret[j];\n     \
    \       ret[i + 1] = ++j;\n        }\n        return ret;\n    }\n\npublic:\n\
    \    // search \"word\" within \"str\"\n    // O(|str|)\n    static vector<int>\
    \ search(const string &str, const string &word) {\n        vector<int> table(makeTable(word)),\
    \ ret;\n        const int N = str.size(), M = word.size();\n        int m = 0,\
    \ i = 0;\n        while(m + i < N) {\n            if(word[i] == str[m + i]) {\n\
    \                if(++i == M) {\n                    ret.push_back(m);\n     \
    \               m += i - table[i];\n                    i = table[i];\n      \
    \          }\n            } else {\n                m += i - table[i];\n     \
    \           if(i > 0) i = table[i];\n            }\n        }\n        return\
    \ ret;\n    }\n};\n/*\n * @brief KMP\n * @docs docs/kmp.md\n */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Knuth-Morris-Pratt\
    \ algorithm\nclass KMP {\nprivate:\n    static vector<int> makeTable(const string\
    \ &s) {\n        int n = s.size();\n        vector<int> ret(n + 1);\n        int\
    \ j = -1;\n        ret[0] = j;\n        for(int i = 0; i < n; i++) {\n       \
    \     while(j >= 0 && s[i] != s[j]) j = ret[j];\n            ret[i + 1] = ++j;\n\
    \        }\n        return ret;\n    }\n\npublic:\n    // search \"word\" within\
    \ \"str\"\n    // O(|str|)\n    static vector<int> search(const string &str, const\
    \ string &word) {\n        vector<int> table(makeTable(word)), ret;\n        const\
    \ int N = str.size(), M = word.size();\n        int m = 0, i = 0;\n        while(m\
    \ + i < N) {\n            if(word[i] == str[m + i]) {\n                if(++i\
    \ == M) {\n                    ret.push_back(m);\n                    m += i -\
    \ table[i];\n                    i = table[i];\n                }\n          \
    \  } else {\n                m += i - table[i];\n                if(i > 0) i =\
    \ table[i];\n            }\n        }\n        return ret;\n    }\n};\n/*\n *\
    \ @brief KMP\n * @docs docs/kmp.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.cpp
  requiredBy: []
  timestamp: '2021-06-23 20:37:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-ALDS1-14-B.test.cpp
documentation_of: string/kmp.cpp
layout: document
redirect_from:
- /library/string/kmp.cpp
- /library/string/kmp.cpp.html
title: KMP
---
## 説明

文字列 $S$ の中で単語 $W$ と一致する index を返す

## 計算量

$O(|S|)$