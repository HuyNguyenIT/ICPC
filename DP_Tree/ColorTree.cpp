#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> v(n); vector<vector<int>> adj(n + 5);
    for(int i = 1; i <= n; i++){
        int par; cin >> par;
        adj[par].push_back(i);
    }
    dfs(0, -1);

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("input.txt", "r", stdin);

    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}