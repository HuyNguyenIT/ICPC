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
        int answer = 0;
        dp[1][1] = -v[0];
        for(int i = 2; i <= n; i++){
           dp[i][1] = max(dp[i - 1][1], -v[i - 1]);
           answer = max(answer, v[i - 1] + dp[i - 1][1]);
       }
       
       return answer;

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
