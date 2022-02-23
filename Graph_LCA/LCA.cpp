#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
const int LOG = 17;
vector<int> children[MAX_N];
int up[MAX_N][LOG]; 
int depth[MAX_N];

void dfs(int a, int parent) {
	for(int b : children[a]) {
		if(b == parent) continue;
		depth[b] = depth[a] + 1;
		up[b][0] = a;
		for(int j = 1; j < LOG; j++) {
			up[b][j] = up[up[b][j-1]][j-1];
		}
		dfs(b, a);
	}
}

int get_lca(int a, int b) { 
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j]; 
		}
	}

	if(a == b) {
		return a;
	}

	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		children[a].push_back(b);
		children[b].push_back(a);
	}
	
	dfs(1, -1);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		int par = get_lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[par] << '\n';
	}
}