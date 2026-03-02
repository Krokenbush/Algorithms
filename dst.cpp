#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxn = 1e5 + 10;
const int maxlog = 25;

struct DST {
    int n;
    ll dp[maxn][maxlog];

    DST (vector <int> &a) {
        n = a.size();
        for (int h = 0; (1 << h) < n; ++h) {
            int len = (1 << h);
            for (int c = len; c - len < n; c += 2 * len) {

                if (c < n) dp[c][h] = a[c];

                for (int i = c + 1; i < min(c + len, n); ++i) {
                    dp[i][h] = dp[i - 1][h] + a[i];
                }

                if (c - 1 < n) dp[c - 1][h] = a[c - 1];
                else dp[n - 1][h] = a[n - 1];

                for (int i = min(c - 2, n - 2); i >= c - len; --i) {
                    dp[i][h] = dp[i + 1][h] + a[i];
                }
            }
        }
    }

    ll get (int l, int r) {
        if (l == r) return dp[l][0];
        int lvl = __lg(l ^ r);
        return dp[l][lvl] + dp[r][lvl];
    }
};

void solution () {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    DST dst(a);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << dst.get(l, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solution();
    }

    return 0;
}
