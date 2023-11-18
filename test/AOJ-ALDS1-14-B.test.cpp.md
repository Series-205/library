---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/kmp.cpp
    title: KMP
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/AOJ-ALDS1-14-B.test.cpp\"\n#define PROBLEM \\\n   \
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"string/kmp.cpp\"\n\
    \n#line 4 \"string/kmp.cpp\"\nusing namespace std;\n\n// Knuth-Morris-Pratt algorithm\n\
    class KMP {\nprivate:\n    static vector<int> makeTable(const string &s) {\n \
    \       int n = s.size();\n        vector<int> ret(n + 1);\n        int j = -1;\n\
    \        ret[0] = j;\n        for(int i = 0; i < n; i++) {\n            while(j\
    \ >= 0 && s[i] != s[j]) j = ret[j];\n            ret[i + 1] = ++j;\n        }\n\
    \        return ret;\n    }\n\npublic:\n    // search \"word\" within \"str\"\n\
    \    // O(|str|)\n    static vector<int> search(const string &str, const string\
    \ &word) {\n        vector<int> table(makeTable(word)), ret;\n        const int\
    \ N = str.size(), M = word.size();\n        int m = 0, i = 0;\n        while(m\
    \ + i < N) {\n            if(word[i] == str[m + i]) {\n                if(++i\
    \ == M) {\n                    ret.push_back(m);\n                    m += i -\
    \ table[i];\n                    i = table[i];\n                }\n          \
    \  } else {\n                m += i - table[i];\n                if(i > 0) i =\
    \ table[i];\n            }\n        }\n        return ret;\n    }\n};\n/*\n *\
    \ @brief KMP\n * @docs docs/kmp.md\n */\n#line 8 \"test/AOJ-ALDS1-14-B.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    string str, word;\n    cin >> str;\n    cin >> word;\n\n    auto ans = KMP::search(str,\
    \ word);\n\n    for(auto &&val : ans) cout << val << \"\\n\";\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../string/kmp.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    string str, word;\n    cin >> str;\n    cin >> word;\n\n    auto ans = KMP::search(str,\
    \ word);\n\n    for(auto &&val : ans) cout << val << \"\\n\";\n}\n"
  dependsOn:
  - string/kmp.cpp
  isVerificationFile: true
  path: test/AOJ-ALDS1-14-B.test.cpp
  requiredBy: []
  timestamp: '2023-11-17 23:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-ALDS1-14-B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-ALDS1-14-B.test.cpp
- /verify/test/AOJ-ALDS1-14-B.test.cpp.html
title: test/AOJ-ALDS1-14-B.test.cpp
---
