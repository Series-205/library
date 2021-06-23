#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#include "../string/kmp.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str, word;
    cin >> str;
    cin >> word;

    auto ans = KMP::search(str, word);

    for(auto &&val : ans) cout << val << "\n";
}