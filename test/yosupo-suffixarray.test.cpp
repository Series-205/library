#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#include "../string/suffix-array.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    SuffixArray sa(s);
    for(int i = 0; i < n; i++) cout << sa[i] << " \n"[i + 1 == n];
}