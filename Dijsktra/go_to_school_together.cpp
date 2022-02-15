#include<bits/stdc++.h>

#define int long long

using namespace std;

int const N = 5e5 + 123;

int const base = 1e9 + 1;

vector <vector<pair<int, int> >> adj(N);

int const oo = 1e18;

int H(int a, int b){
	return (a * base + b + a * b);
}

void dijkstra(int s, vector <int> &d, map<int, vector<int>> &p){
	d.assign(N, oo);
	d[s] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    
    while(!q.empty()){
    	int v = q.top().second;
    	int d_v = q.top().first;
    	q.pop();
    	if(d_v != d[v]) continue;
    	
    	for(auto edge : adj[v]){
    		int to = edge.first;
    		int len = edge.second;
    		if(d[v] + len < d[to]){
    			d[to] = d[v] + len;
    			p[to].clear();
    			p[to].push_back(v);
    			q.push({d[to], to});
			} else if(d[v] + len == d[to]){
				p[to].push_back(v);
			}
		}
	}
}

map<int, int> mp1, mp2;
set<int> st1, st2;
bool check = false;

void dfs(int a, map<int, vector<int>> &p, int par){
	st1.insert(a);
	for(int x : p[a]){
		mp1[H(a, x)] = 1;
		mp1[H(x, a)] = 1;
		if(x != par)dfs(x, p, a);
	}
}

void dfs2(int a, map<int, vector<int>> &p, int par, set<pair<int, int>> &v){
	st2.insert(a);
	for(int x : p[a]){
		mp2[H(x, a)] = 1;
		mp2[H(a, x)] = 1;
		if(mp1[H(a, x)] == 1){
			v.insert({a, x});
		}
		if(x != par)dfs2(x, p, a, v);
	}
}
void TestCase(){
	st1.clear();
	st2.clear();
	check = false;
	map<int, vector<int>> p1, p2;
	int s1, h1, s2, h2; 
	int n, m;
	cin >> n >> m;
	
	cin >> s1 >> h1 >> s2 >> h2;
	adj = vector <vector<pair<int, int> >>(N);
	mp1.clear(); mp2.clear();
	
	for(int i = 0; i < m; i++){
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		
	}
	
	vector<int> d1, d2;
	set<pair<int, int>> edges;

	dijkstra(s1, d1, p1);
	dijkstra(s2, d2, p2);


	dfs(h1, p1, -1);
	dfs2(h2, p2, -1, edges);
	
	
	int answer = 0;
	for(auto x : edges){
		if(d1[x.first] == d2[x.first]){
			cout << "infinity\n";return;
		}
		else if(d1[x.second] == d2[x.first]){
			answer += 1;
		}
		else if(d1[x.first] == d2[x.second]){
			answer += 1;
		} else {
			if(d1[x.first] < d2[x.second] && d2[x.second] < d1[x.second]) answer += 1;
			else if(d2[x.first] < d1[x.second] && d1[x.second] < d2[x.second]) answer += 1;
		}
		
	}
	
	st1.insert(h1);
	st1.insert(s1);
	st2.insert(h2);
	st2.insert(s2);
	map<int, int> ans;
	
	for(auto x : st1) ans[x] = 1;
	for(auto x : st2) {
		if(ans[x] == 1){
			if(d1[x] == d2[x]) answer += 1;
			else if(x == h1) answer += 1;
		}
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