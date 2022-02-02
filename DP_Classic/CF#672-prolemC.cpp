#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    vector<vector<int>> dp(n + 5, vector<int> (2));
    dp[0][0] = 0; // +
    dp[0][1] = 0; // -
    for(int i = 0; i < n; i++){
        dp[i + 1][0] = max(dp[i][0], dp[i][1] - v[i]);
        dp[i + 1][1] = max(dp[i][1], dp[i][0] + v[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    // freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}