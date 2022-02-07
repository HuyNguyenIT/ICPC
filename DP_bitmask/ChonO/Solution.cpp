#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
 
void solve() {
    int n; cin >> n;
    vector<vector<int>> v(n + 5, vector<int>(n + 5));
    vector<int> dp(n + 5, 0);

    dp[0] = 0;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> v[i][j];

    for(int i = 0; i < (1 << n); i++){
        int k = __builtin_popcount(i);

        for(int j = 0; j < n; j++){
            if(!((i >> j) & 1)){
                dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + v[k][j]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << '\n';

    
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}