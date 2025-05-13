#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <bits/stdc++.h>
using namespace std;

#include "../convolution/xor_convolution.cpp"
#include "../modint/modint.cpp"

using mint = Modint<998244353>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<mint> a(1 << n), b(1 << n);
    for(int i = 0; i < 1 << n; i++) {
        long long in;
        cin >> in;
        a[i] = in;
    }
    for(int i = 0; i < 1 << n; i++) {
        long long in;
        cin >> in;
        b[i] = in;
    }

    auto ans = xorConvolution::convolution(a, b);
    for(int i = 0; i < 1 << n; i++)
        cout << ans[i].x << " \n"[(i + 1) == 1 << n];
}