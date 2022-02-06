#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& v) {

        int n = v.size();

        vector<vector<int>> dp(n + 5, vector<int> (2, -987654321));

        /* 
            dp[i][1] bought
            dp[i][0]  selled
        */
        dp[1][1] = -v[0];
        dp[1][0] = -987654321;
        for(int i = 2; i <= n; i++){
           dp[i][1] = max({dp[i - 1][0] - v[i - 1], -v[i - 1], dp[i - 1][1]});
           dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + v[i - 1]);
           cout << "dp[" << i << "][1" << "] = " << dp[i][1] << '\n';
           cout << "dp[" << i << "][0" << "] = " << dp[i][0] << '\n';
       }
       
       return max(dp[n][1], dp[n][0]);

    }
};

void solve(){
	int n; cin >> n;
    vector<int> v(n);

    for(auto&x : v) cin >> x;

    cout << Solution().maxProfit(v) << '\n';

}


int32_t main(){	

    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie(); 

    freopen("input.txt", "r", stdin);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
