#include <bits/stdc++.h>

using namespace std;

#define int long long

struct item{
    int node;
    int cost;
    bool operator<(const item&b)const{
        return cost <= b.cost;
    }
};

void disktra(vector<vector<pair<int, int>>> &adj, int n){
    priority_queue<pair<int, int> , vector<pair<int , int>> , greater<pair<int, int>> > q;
    q.push({0, 1});
    vector<int> d(n + 5, (long long)(1e17));
    d[1] = 0;
    vector<int> f(n + 5, 0);
    f[1] = 1;
    while(!q.empty()) {
        int node = q.top().second;
        int c = q.top().first;
        q.pop();
        if(c != d[node]) continue;
        for(auto u : adj[node]){
            if(d[u.first] < c + u.second) continue;
            if(d[u.first] > c + u.second){
                d[u.first] = c + u.second;
                q.push({d[u.first], u.first});
                f[u.first] = f[node];
            }
            else if(d[u.first] == c + u.second){
                f[u.first] += f[node];
            }
        }
    }   
    cout << d[n] << ' ' << f[n] << '\n';
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 5);

    for(int i = 0; i < m; i++){
        int u, v, c; cin; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    disktra(adj, n);
}
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;    
    while (t--) {
        solve();
    }
    
    return 0;
}