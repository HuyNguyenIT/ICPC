#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;

    for(auto&x : v) cin >> x;
    for(auto x : v) mx = max(mx, x);

    vector<vector<int>> dp(n + 5, vector<int> (2005, 2005));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 2000; j++){
            if(dp[i - 1][j] < 2005){
                if(j + v[i - 1] <= 2000){
                    dp[i][j + v[i - 1]] = min(dp[i][j + v[i - 1]], max(dp[i - 1][j] , j + v[i - 1]));
                }
            }
            if(j - v[i - 1] >= 0){
                dp[i][j - v[i - 1]] = min({max(dp[i - 1][j], j), dp[i][j - v[i - 1]]});
            }else{
                dp[i][0] = min(dp[i][0], dp[i - 1][j] + v[i - 1] - j);
            }
        }
    } 

    int answer = INT_MAX;
    for(int i = 0; i <= 2000; i++){
        answer = min(answer, dp[n][i]); 
    }

    cout << answer << '\n';

}


int32_t main(){	

    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie(); 

    // freopen("input.txt", "r", stdin);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
