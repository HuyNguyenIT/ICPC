#include <bits/stdc++.h>

using namespace std;

#define int long long
int const N = 1e5 + 123;
int n;
vector<int> f(N, 0);
vector<vector<int>> adj(N);
vector<int> cost(N);
int answer = 0;
void dfs(int u, int par){
    f[u] = cost[u];
    for(auto x : adj[u]){
        if(x == par) continue;
        dfs(x, u);
        f[u] += f[x];
    }
    answer = max(answer, f[u]);

    
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> cost[i], answer = max(answer, cost[i]);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << answer << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}