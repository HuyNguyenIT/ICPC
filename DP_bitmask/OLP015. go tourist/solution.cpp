#include<bits/stdc++.h>

using namespace std;

int const N = 3e5 + 123;

int const mod = 1e9 + 7;

#define int long long

void TestCase(){
    int n; cin >> n;
    vector<vector<int>> v(n + 5, vector<int>(n + 5));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> v[i][j];
    }
    vector<vector<int> > dp(1 << n, vector<int>(n + 5, INT_MAX));
    for(int i = 0; i < n; i++){
        dp[1 << i][i] = 0;
    }
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((mask >> j) & 1) continue;
                dp[mask | 1 << j][j] = min(dp[mask | 1 << j][j], dp[mask][i] + v[i][j]) ;
            }
        }
    }
    int answer = INT_MAX;
    for(int i = 0; i < n; i++){
        answer = min(answer, dp[(1 << n) - 1][i]);
    }
    cout << answer << '\n';
}	

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie();
    int T = 1; cin >> T;
    while(T--){
        TestCase();
    }
}