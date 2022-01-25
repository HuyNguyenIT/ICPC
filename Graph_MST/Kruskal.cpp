#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 123;

vector<int> parent(N);

#define int long long

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

struct item{
	int x, y, v;
};

bool cmp(item a, item b){
	return a.v < b.v;
}

void TestCase(){
	int n, m; cin >> n >> m;
	vector<item> v;
	for(int i = 0; i < m; i++){
		int x, y, val; cin >> x >> y >> val;
		v.push_back({x, y, val});
	}
	for(int i = 1; i <= n; i++){
		make_set(i);
	}
	sort(v.begin(), v.end(), cmp);
	
	int answer = 0;
	for(item d : v){
		int p = find_set(d.x);
		int q = find_set(d.y);
		if(p != q){
			answer += d.v;
			union_sets(d.x, d.y);
		}
	}
	cout << answer << '\n';
	
}

int32_t main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(); cout.tie();
	int T = 1; cin >> T;
	while(T--){
		TestCase();
	}
}



