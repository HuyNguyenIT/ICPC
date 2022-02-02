#include<bits/stdc++.h>

using namespace std;

#define int long long

int const N = 1e3 + 1;

vector<int> dp;

void init(){
    dp = vector<int>(1005, 1005);
    dp[1] = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= i; j++){
            int newJ = (long long)(i/j) + i;
            if(newJ >= 1005) continue;
            dp[newJ] = min(dp[newJ], dp[i] + 1);
        }
    }    
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int>b(n), c(n);
    for(auto &x : b) cin >> x;
    for(auto &x : c) cin >> x;
    vector<vector<int>> f (n + 5, vector<int> (12010, 0));
    int mx = min(k, (long long)12005);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= mx; j++){
            f[i][j] = max(f[i][j], f[i - 1][j]);
            if(dp[b[i - 1]] <= j){
                f[i][j] = max({f[i][j], f[i - 1][j], f[i - 1][j - dp[b[i - 1]]] + c[i - 1]});
            }
        }
    }
    cout << f[n][mx] << '\n';


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    // freopen("output.txt", "r", stdin);
    init();
    int t; cin >> t; 
    while(t--){
        solve();
    }
}