#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 123;

vector<int> parent(N);
vector<int> size(N, 1);

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
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void TestCase(){
	int n, m; cin >> n >> m;
	vector<int> tmp(n + 5, 1);
	size = tmp;
	for(int i = 1; i <= n; i++) make_set(i);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		union_sets(u, v);
	}
	int answer = 0;
	for(int i = 1; i <= n; i++){
		int u = find_set(i);
		answer = max(answer, size[u]);
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