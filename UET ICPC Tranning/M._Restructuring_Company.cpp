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

int jump(int i, int par, int n){
    if(i > n || find_set(i) != par) return i;
    return nexts[i] = jump(nexts[i], par, n);
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < N; i++){
        parent[i] = i;
        nexts[i] = i + 1;
    }
    n--;
    while(q--){
        int q, a, b; cin >> q >> a >> b;
        a--; b--;
        if(q == 1){
            union_sets(a, b);
        } else if(q == 2){
            int cur = a;
            while(true){
                int nxt = jump(cur, find_set(cur), n);
                if(nxt > b) break;
                union_sets(a, nxt);
                a = nxt;
            }
        } else {
            if(find_set(a) == find_set(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
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