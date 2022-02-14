#include <bits/stdc++.h>

using namespace std;

#define int long long
int const N = 1e5 + 123;
int n;
vector<int> f(N, 0);
vector<vector<int>> adj(N);
vector<int> cost(N);
int answer = 0;

vector<vector<int>> dp(N , vector<int>(2, 0));

/*----------------------------------------------------------------
    dp[node][1] : select node
    dp[node][0] : not select node

*/

void dfs(int node, int par){
    dp[node][1] = cost[node];
    dp[node][0] = 0;
    for(auto x : adj[node]){
        if(x == par) continue;
        dfs(x, node);
        dp[node][0] += max(dp[x][1] , dp[x][0]);
        dp[node][1] += dp[x][0];
    }
    
    if(dp[node][1] < 0) dp[node][1] = 0;
    if(dp[node][0] < 0) dp[node][0] = 0;

    answer = max(dp[node][1], dp[node][0]);
    // cout << node << ' ' << dp[node][1] << ' ' << dp[node][0] << '\n';
}

void solve() {
    cin >> n;
    int res = -987654321;
    for(int i = 1; i <= n; i++) cin >> cost[i], res = max(res, cost[i]);
    
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(res <= 0) {
        cout << res << '\n';
        return;
    }
    dfs(1, -1);
    cout << answer << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}