#include<bits/stdc++.h>

using namespace std;

int const N = 1e6 + 123;

vector<int> parent(N);
vector<int> sizes(N, 1);
vector<int> nexts(N);

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> v(n + 5);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) make_set(i);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        union_sets(u, v);
    }

    vector<vector<int>> adj(n + 5);

    for(int i = 1; i <= n; i++){
        int par = find_set(i);
        adj[par].push_back(i);
    }

    vector<int> answer(n + 5);

    for(int i = 1; i <= n; i++){
        if(adj[i].size()){
            vector<int> a, b;
            for(auto x : adj[i]){
                a.push_back(x);
                b.push_back(v[x]);
            }
            sort(b.rbegin(), b.rend());
            int j = 0;
            for(auto x : b){
                answer[a[j]] = x;
                j++;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << answer[i] << ' ';
}

int32_t main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie();

    // freopen("input.txt", "r", stdin);

    int T = 1; 
    while(T--){
        solve();
    }
}