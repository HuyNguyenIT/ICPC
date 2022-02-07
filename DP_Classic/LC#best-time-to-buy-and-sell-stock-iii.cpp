#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& v) {
        int answer = 0;
        int n = v.size();
        vector<vector<vector<int>>> dp(n + 5, vector<vector<int>>(5, vector<int>(5, -9865321)));


        dp[1][0][0] = 0;
        dp[1][0][1] = -v[0];

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 2; j++){
                for(int k = 0; k < 2; k++){
                    if(dp[i][j][k] == -9865321) continue;
                    if(i == n){
                        answer = max(answer, dp[i][j][k]);
                        continue;
                    }
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    if(k == 0) dp[i + 1][j][1] = max(dp[i][j][0] - v[i], dp[i + 1][j][1]);
                    if(k == 1) dp[i + 1][j + 1][0] = max(dp[i][j][1] + v[i], dp[i + 1][j + 1][0]);
                }
            }
        }
        return answer;

    }
};


void solve() {

    int n; cin >> n;
    vector<int> v(n);

    for(auto&x : v) cin >> x;

    cout << Solution().maxProfit(v) << '\n';

}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("input.txt", "r", stdin);

    int t = 1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}