#include <bits/stdc++.h>

using namespace std;

#define int long long

int cost(int pos, int k, vector<vector<int> > &v){
    int n = v.size();
    int answer = 0;
    for(int i = 0; i < 4; i++){
        if((k >> i) & 1){
            answer += v[i][pos];
        }
    }
    return answer;
}

bool check(int i, int j){
    if((j & i) != 0) return false;
    for(int bit = 0; bit <= 5; bit++){
        if(((j >> bit) & 1) && ((j >> (bit + 1)) & 1)) return false;
    }

    return true;

}

void solve() {
    int n; cin >> n;

    vector<vector<int>> v(10, vector<int>(n + 5));

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++) cin >> v[i][j];
    }

    vector<vector<int>> dp(n + 5, vector<int> ((1<< 5), -INT_MAX));

    int answer = -INT_MAX;

    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < (1 << 4); j++){
            for(int k = 0; k < (1 << 4); k++){
                if(check(j, k)){
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + cost(i, k, v));
                }
            }
        }

    }

    for(int i = 0; i < (1 << 4); i++){
        answer = max(answer, dp[n][i]);
    }

    cout << max(answer, (long long)(0));
}
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}