#include <bits/stdc++.h>

using namespace std;

#define int long long

int maximalRectangle(vector<vector<int>> matrix, int n, int m) {
    vector<vector<int>> dp(n + 5, vector<int> (m + 5, 0));
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0)
                dp[i][j] = matrix[i][j] == 1 ? 1 : 0;
            else
                dp[i][j] = matrix[i][j] == 1 ? (dp[i-1][j] + 1) : 0;
            int min = dp[i][j];
            for (int k = j; k >= 0; k--) {
                if (min == 0) break;
                if (dp[i][k] <= min) min = dp[i][k];
                maxArea = max(maxArea, min * (j - k + 1));
            }
        }
    }
    return maxArea;
} 
void solve() {
    int n, m, k; cin >> n >> m >> k;
    if(n == 0 || m == 0){
        cout << 0 << '\n';
        return;
    }
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
    int answer = 0;
    for(int down = 0; down <= n; down++){
        for(int right = 0; right <= m; right++){
            int nz = n - down;
            int mz = m - right;
            vector<vector<int>> c(nz, vector<int>(mz, 0));
            for(int i = 0; i < nz; i++){
                for(int j = 0; j < mz; j++){
                    c[i][j] = abs(a[i][j] - b[i + down][j + right]) <= k ? 1 : 0;
                    
                }
            }
            answer = max(answer, maximalRectangle(c, nz, mz));
        }
    }
    for(int down = 0; down <= n; down++){
        for(int right = 0; right <= m; right++){
            int nz = n - down;
            int mz = m - right;
            vector<vector<int>> c(nz, vector<int>(mz, 0));
            for(int i = 0; i < nz; i++){
                for(int j = 0; j < mz; j++){
                    c[i][j] = abs(a[i + down][j + right] - b[i][j]) <= k ? 1 : 0;
                }
            }
            answer = max(answer, maximalRectangle(c, nz, mz));
        }
    }
    
    cout << k << ' ' << answer << '\n';
}
 
int32_t main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie();
    
    freopen("input.txt", "r", stdin);

    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}