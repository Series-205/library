#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#include "../string/rolling-hash.cpp"

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();

    RollingHash rh;
    auto hashed = rh.build(s);

    for(int i = 0; i < n; i++) {
        int ok = 0, ng = n - i + 1;
        while(ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if(rh.slice(hashed, 0, mid) == rh.slice(hashed, i, i + mid))
                ok = mid;
            else
                ng = mid;
        }

        cout << ok << " \n"[i + 1 == n];
    }
}