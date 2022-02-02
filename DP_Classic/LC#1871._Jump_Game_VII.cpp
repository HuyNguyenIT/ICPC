#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n + 5, false);
        dp[0] = true;
        int cnt = 0;
        
        for(int i = 1; i < n; i++){
            if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1] == true) cnt -= 1;
            if(i - minJump >= 0 && dp[i - minJump] == true) cnt += 1;
            if(cnt > 0 and s[i] == '0') dp[i] = true;

        }
        return dp[n - 1] ;
    }
};

void solve(){
    string s; int minJump, maxJump; cin >> s >> minJump >> maxJump;
    cout << Solution().canReach(s, minJump, maxJump) << '\n';
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie();cout.tie();
    freopen("input.txt", "r", stdin);
    int tt = 1; cin >> tt;
    while(tt--){
        solve();
    }
}

