#include<bits/stdc++.h>

using namespace std;

#define int long long

int const N = 1e6 + 123;

int const mod = 1e8 + 7;

void hashS(string &s, vector<int> &H){
	int hashcode = 0;
	int base = 26;
	H[0] = s[0] - 'a';
	for(int i = 1; i < s.size(); i++){
		H[i] = (H[i - 1] * base + s[i] - 'a') % mod;
	}

}

vector<int> p(N, 1);
unordered_map <int, int> mp;
void init(){
	p[1] = 26;
	for(int i = 2; i <= N; i++){
		p[i] = (p[i - 1] % mod * 26) % mod;
	}
}

int getHash(int l, int r, vector<int> &hash){
	return ((hash[r] - (hash[l - 1] * p[r - l + 1]) % mod + mod) % mod); 
}

bool good(int m, const string &s, vector<int> &hashS, int k){
	mp.clear();
	int n = s.size();
	int code = hashS[m - 1];
	mp[code] += 1;
	if(mp[code] >= k) return true;
	
	for(int i = 1; i < n; i++){
		if(i + m - 1 >= n) break;
		int h = getHash(i, i + m - 1, hashS);
		mp[h] += 1;
		if(mp[h] >= k) return true;
	}
	return false;
}

void TestCase(){
	int n; cin >> n;
	int k; cin >> k;
	string s; cin >> s;
	vector<int> PoliHashS(N);
	hashS(s, PoliHashS);
//	for(int i = 0; i < n; i++) cout << PoliHashS[i] << '\n';
	int answer = 0;
	int l = 1, r = n - 1;
	while(l <= r){
		int m = (l + r) >> 1;
		if(good(m, s, PoliHashS, k)){
			answer = max(answer, m);
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << answer << '\n';
	
}

int32_t main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(); cout.tie();
	int T = 1; cin >> T;
	init();
	
	while(T--){
		TestCase();
	}
}