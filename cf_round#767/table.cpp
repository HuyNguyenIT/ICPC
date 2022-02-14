#include <bits/stdc++.h>

using namespace std;

#define int long long

int maximalRectangle(vector<vector<char>>& matrix, int n, int m) {
    int dp[n][m];
    int maxArea = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0)
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
            else
                dp[i][j] = matrix[i][j] == '1' ? (dp[i-1][j] + 1) : 0;
            int min = dp[i][j];
            for (int k = j; k >= 0; k--) {
                if (min == 0) break;
                if (dp[i][k] < min) min = dp[i][k];
                maxArea = max(maxArea, min * (j - k + 1));
            }
        }
    }
    return maxArea;
} 
void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<vector<int>> a(n + 5, vector<int>(m + 5));
    vector<vector<int>> b(n + 5, vector<int>(m + 5));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    vector<vector<char>> c(n , vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(abs(a[i][j] - b[i][j]) <= k){
                c[i][j] = '1';
            } else c[i][j] = '0';
        }
    }
    cout << maximalRectangle(c, n, m) << '\n';
}
 
int32_t main() {
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