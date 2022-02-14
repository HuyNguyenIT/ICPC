#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n; vector<int> a(n), b(n);
    int sum = 0;
    for(auto&x : a) cin >> x, sum += x;
    for(auto&x : b) cin >> x, sum += x;
    if(n == 1){
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> dp(n + 5, vector<int>(100 * 100 + 100, 0));

    int s = 100 * 100 + 1;
    dp[0][a[0]] = 1;
    dp[0][b[0]] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= s; j++){
            if(j >= a[i]) dp[i][j] |= dp[i - 1][j - a[i]];
            if(j >= b[i]) dp[i][j] |= dp[i - 1][j - b[i]];
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        answer += (a[i] * a[i] + b[i] * b[i]);
    }

    answer *= (n - 2);
    int res = INT_MAX;
    for(int j = 0; j <= s; j++){
        if(dp[n - 1][j]){
            res = min(res, answer + j * j + (sum - j) * (sum - j));
        }
    }

    cout << res << '\n';


}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}