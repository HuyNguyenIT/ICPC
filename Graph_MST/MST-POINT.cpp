#include<bits/stdc++.h>

using namespace std;

int const N = 200;

#define int long long

struct item{
	double x, y;
};

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
 
struct T{
	int x, y; double v;
};

double distance(item a, item b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(T x, T y){
	return x.v < y.v;
}

void TestCase(){
	int m; cin >> m;
	vector<item> v(m + 5);
	for(int i = 1; i <= m; i++){
		double x, y; cin >> x >> y;
		v[i] = {x, y};
	}
	
	vector<T> a;
	
	for(int i = 1; i <= m; i++){
		for(int j = i + 1; j <= m; j++){
			a.push_back({i, j, distance(v[i], v[j])});
		}
	}
	
	for(int i = 1; i <= m; i++) make_set(i);
	sort(a.begin(), a.end(), cmp);
	double answer = 0;
	for(auto d : a){
		int p = find_set(d.x);
		int q = find_set(d.y);
		if(p != q){
			union_sets(q, p);
			answer += d.v;
		}
	}
	cout << setprecision(6) << fixed << answer << '\n';
}

int32_t main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(); cout.tie();
	int T = 1; cin >> T;
	while(T--){
		TestCase();
	}
	return 0;
}
