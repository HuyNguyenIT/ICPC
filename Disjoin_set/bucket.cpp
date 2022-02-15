#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 123;

vector<int> parent(N);

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
    if (a != b)
        parent[b] = a;
}

void TestCase(){
	int n; cin >> n;
	for(int i = 0; i < N; i++) make_set(i);
	while(n--){
		int u, v, q; cin >> u >> v >> q;
		if(q == 2){
			int x = find_set(u);
			int y = find_set(v);
			if(x == y) cout << 1 << '\n';
			else cout << 0 << '\n';
			
		} else {
			union_sets(u, v);
		}
	}
}

int32_t main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0); cout.tie();
	int T = 1;
	while(T--){
		TestCase();
	}
}