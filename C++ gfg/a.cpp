#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N = 100100;
int t[2 * N];
int get(int l, int r) {
    l += N;
    r += N;
    int ans = 0;
    while (l < r) {
        if (l & 1) ans += t[l++];
        if (r & 1) ans += t[--r];
        l /= 2, r /= 2;
    }
    return ans;
}
void add(int x, int y) {
    x += N;
    while (x)
        t[x] += y, x /= 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        cout << "Case #" << test << ": ";
        int n;
        cin >> n;
        int ans = 0;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
            add(x, 1);
            while (get(ans + 1, N) >= ans + 1)
                ++ans;
            cout << ans << ' ';
        }
        cout << '\n';
        for (int x : a)
            add(x, -1);
    }
    return 0;
}
