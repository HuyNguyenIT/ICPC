//https://vn.spoj.com/problems/KQUERY/
#include<bits/stdc++.h>

#define int long long

using namespace std;

int const N = 1e5 + 123;

struct element{
	int v, position;
};

struct item{
	int l, r, k, idx;
};

bool cmp1(element a, element b){
	return a.v < b.v;
}

bool cmp2(item a, item b){
	return a.k < b.k;
}

struct{
	int f[N << 2], lazy[N << 2];

	void init(int k, int l, int r){
		if(l == r) {
			f[k] = 1;
		}
		if(l < r){
			int m = (l + r) >> 1;
			init(k << 1, l, m);
			init(k << 1 | 1, m + 1, r);
			f[k] = f[k << 1] + f[k << 1 | 1];
		}
	}

	void update(int k, int l, int r, int L, int R, int v){
		if(l > r) return;
		if(l > R || L > r) return;
		if(l >= L && r <= R){
			f[k] = 0;
			return;
		}
		int m = (l + r) >> 1;
		update(k << 1, l, m, L, R, v);
		update(k << 1 | 1, m + 1, r, L, R, v);
		f[k] = f[k << 1] + f[k << 1 | 1];
	}

	int get(int k, int l, int r, int L, int R){
		if(l > r) return 0;
		if(L > r || R < l) return 0;
		if(L <= l && r <= R) return f[k];
		int m = (l + r) >> 1;
		return get(k << 1, l, m, L, R) + get(k << 1 | 1, m + 1, r, L, R);	
	}

} ST;

void TestCase(){
	int n; cin >> n;
	vector<element> a(n);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a[i] = {x, i};
	}
	ST.init(1, 0, n - 1);
	int m; cin >> m;
	vector<item> query;
	int idx = 0;
	for(int i = 0; i < m; i++){
		int l, r, k; cin >> l >> r >> k;
		l--;r--;
		query.push_back({l, r, k, i});
		
	}

	sort(a.begin(), a.end(), cmp1);
	sort(query.begin(), query.end(), cmp2);

	vector<int> answer(m + 5);
	int pos = 0;
	for(int i = 0; i < m; i++){
		while(pos < m && a[pos].v <= query[i].k){
			ST.update(1, 0, n - 1, a[pos].position, a[pos].position, 0); 
			pos += 1;
		}
		answer[query[i].idx] = ST.get(1, 0, n - 1, query[i].l, query[i].r);
	}
	for(int i = 0; i < m; i++){
		cout << answer[i] << '\n';
	}

}

int32_t main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(); cout.tie();
	int T = 1; 
	while(T--){
		TestCase();
	}
}



