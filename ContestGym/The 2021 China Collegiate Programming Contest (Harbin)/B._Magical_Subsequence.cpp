#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
 
void solve() {
    
    int n; cin >> n; vector<int> v(n);
    for(auto&x : v) cin >> x;

    vector<vector<int> > prev(n + 5, vector<int> (250, -1));
    prev[1][v[0]] = 0;
    vector<int> pos(250, -1);

    pos[v[0]] = 0;
    pos[v[1]] = 1;
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= 200; j++){
            prev[i][j] = prev[i - 1][j];
            prev[i][j] = pos[j];
            
        }
        pos[v[i]] = i;
    }

    vector<vector<int>> dp(250, vector<int>(n + 5, 0));
    int answer = 0;

    for(int i = 0; i <= 200; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i][j - 1];
            if(i >= v[j] && prev[j][i - v[j]] != -1 ){
                int last = prev[j][i - v[j]];
                if(last > 0) last--;
                dp[i][j] = max(dp[i][j - 1], dp[i][last] + 2);
            }
        }
        answer = max(answer, dp[i][n - 1]);
    }

    cout << answer << '\n';



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