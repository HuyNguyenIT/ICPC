#include <bits/stdc++.h>

using namespace std;

#define int long long

int const N = 2e5 + 123;

vector<int> f(N, 0);

int answer = 0;

void dfs(int node, int par, vector<vector<int>> &adj){
    priority_queue<int> q;
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node, adj);
        q.push(f[child]);
    }
    if(q.empty()){
        f[node] = 0;
        return;
    }
    f[node] = q.top() + 1;
    int x = f[node];
    q.pop();
    int y = 0;
    int res = 0;
    if(!q.empty())y = q.top(), res = x + y + 1;
    else res = x;
    answer = max({f[node], res, answer});
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 5);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj);

    cout << answer << '\n';
    
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie();
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}