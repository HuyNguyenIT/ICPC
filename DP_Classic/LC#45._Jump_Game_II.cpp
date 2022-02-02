#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n + 5, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] != INT_MAX){
                for(int j = 1; j <= min(n - i - 1, v[i]); j++){
                    dp[i + j] = min(dp[j + i], dp[i] + 1);
              }
            }
        }
        return dp[n - 1];
    }
};

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    cout << Solution().jump(v) << '\n';
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int tt = 1; cin >> tt;
    while(tt--){
        solve();
    }
}

