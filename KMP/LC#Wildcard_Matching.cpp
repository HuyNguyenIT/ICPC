#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(); int m = p.size();
        vector<vector<int>> dp(n + 5, vector<int> (m + 5, false));
        dp[0][0] = true;
        for(int i = 0; i < m && p[i] == '*'; i++){
            dp[0][i + 1] = 1;
        }
        if(n == 0){
            for(int i = 0; i < m; i++){
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j - 1] != '*'){
                    if(p[j - 1] == '?')dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = dp[i - 1][j - 1] and p[j - 1] == s[i - 1];
                    continue; 
                } 
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
                
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        return dp[n][m];
    }
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie();

    freopen("input.txt", "r", stdin);
    int test; cin >> test;
    while(test--){
        string s, p; cin >> s >> p;
        cout << Solution().isMatch(s, p) << '\n';
    }
}