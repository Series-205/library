#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D"

#include <bits/stdc++.h>
using namespace std;

#include "../string/suffix-array.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    SuffixArray sa(s);
    int q;
    cin >> q;
    while(q--) {
        cin >> s;
        cout << (sa.lower_bound(s) != sa.upper_bound(s)) << "\n";
    }
}