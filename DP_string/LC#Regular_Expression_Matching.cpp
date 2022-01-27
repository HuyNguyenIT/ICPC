#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(); int m = p.size();
        vector<vector<int>> dp(n + 5, vector<int>(m + 5, false));
        dp[0][0] = true;
        for(int i = 1; i < m && p[i] == '*'; i++){
            dp[0][i + 1] = true;
        }
        int last = 0;
        for(int i = 0; i < m; i++){
            if(p[i] != '*') last += 1;
            else last -= 1;
            if(last < 0) last = 0;
            if(last == 0) dp[0][i + 1] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j - 1] != '*'){
                    if(p[j - 1] != '.'){
                        dp[i][j] = dp[i - 1][j - 1] and s[i - 1] == p[j - 1];
                    } else {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j]) and (p[j - 2] == s[i - 1] || p[j - 2] == '.');
                    if(!dp[i][j] && j >= 2){
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        
        return dp[n][m] ;
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