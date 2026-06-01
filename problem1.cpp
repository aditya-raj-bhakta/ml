#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, s;
    cin >> n >> x >> s;

    string u;
    cin >> u;

    vector<int> dp(min(n, x) + 2, -1e9);
    dp[0] = 0;

    for (char ch : u) {
        vector<int> ndp = dp;

        for (int k = 0; k < (int)dp.size(); k++) {
            if (dp[k] < 0) continue;

            if (ch != 'E') {
                if (k < x && k + 1 < (int)dp.size()) {
                    ndp[k + 1] = max(ndp[k + 1], dp[k] + 1);
                }
            }

            if (ch != 'I') {
                if (dp[k] < 1LL * k * s) {
                    ndp[k] = max(ndp[k], dp[k] + 1);
                }
            }
        }

        dp.swap(ndp);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}