#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;

    vector<vector<int>> dp(n + 5, vector<int>(1 << 10, 0));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= (1 << 9); j++){
            if(!dp[i][j]) continue;

            for(int k = 0; k < m; k++){
                dp[i + 1][j | (a[i] & b[k])] = 1;
            }
        }
    }
    
    for(int i = 0; i <= (1 << 9); i++){
        if(dp[n][i]){
            cout << i << '\n';
            return;
        }
    }

}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}