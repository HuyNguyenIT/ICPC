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
    cout << log(10) << '\n';


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    init();
    int t = 1; 
    while(t--){
        solve();
    }
}