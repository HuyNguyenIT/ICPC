/*
Cho dãy so A gom N phan tu, ban dau các phan tu deu bang 0. Có 2 loai truy van nhu sau:
+) 1 x y: Tang 1*2 vào A[x], 2*3 vào A[x+1], 3*4 vào A[x+2], … cho den A[y].
+) 2 x y: In ra tong các phan tu tu x toi y theo modulo 10^9+7.
Input:
Dòng dau tiên là su luong kí tu N và so luong truy van M (N, M <= 200 000).
M dòng tiep, moi dòng gom 1 dong truy van.
Output: 
Voi moi truy van dang 2 in ra dáp án tìm duoc trên mot dòng.
*/

#include<bits/stdc++.h>

using namespace std;

#define int long long

int const N = 2e5 + 123;

int const mod = 1e9 + 7;

int inv2 = 500000004;
int inv6 = 166666668;

int add(int a,int b){
    int res = (a % mod + b % mod) % mod;
    if(res>=mod)
        res-=mod;
    return res;
}

int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}

struct{
	int f[3][N << 2], lazy[3][N << 2];
	
	void init(int k, int l, int r){
		for(int i = 0; i < 3; i++){
			lazy[i][k] = 0;
			f[i][k] = 0;
		}
		if(l < r){
			int m = (l + r) >> 1;
			init(k << 1, l, m);
			init(k << 1 | 1, m + 1, r);
		}
	}
	
	void down(int k, int l, int r){
		int len = r - l + 1;
		f[2][k] = add(f[2][k] , (len % mod * lazy[2][k] % mod) % mod);
		int sumR = add(len * l ,  (len % mod * (len - 1) % mod * inv2 % mod) % mod);
		f[1][k] = add(f[1][k] , sumR * lazy[1][k]);
		f[0][k] = add(f[0][k], (sub((r % mod * (r + 1) % mod * (2 * r + 1) % mod* inv6 % mod) % mod ,
		 ((l - 1) % mod * l % mod * (2 * (l - 1) + 1) % mod * inv6 % mod) % mod) % mod * lazy[0][k] % mod) % mod);
		if(l < r){
			for(int i = 0; i < 3; i++){
				lazy[i][k << 1] = add(lazy[i][k << 1], lazy[i][k]);
				lazy[i][k << 1 | 1] = add(lazy[i][k << 1 | 1], lazy[i][k]);
			} 
		}
		for(int i = 0; i < 3; i++) {
			lazy[i][k] = 0; 
		}
	}
	
	void update(int k, int l, int r, int L, int R){
		if(l > r) return;
		down(k, l, r);
		if(l > R || L > r) return;
		if(l >= L && r <= R){
			int len = r - l + 1;
			f[2][k] = add(f[2][k], ((L - 1) % mod * (L - 2) % mod * len % mod) % mod);
			int sumR = add((len % mod * l % mod) % mod , (len % mod * (len - 1) % mod * inv2 % mod) % mod);
			f[1][k] = add(f[1][k], (sub(3 , 2 * L) % mod * sumR % mod) % mod);
			f[0][k] = add(f[0][k], sub((r % mod * (r + 1) % mod * (2 * r + 1) % mod * inv6 % mod) % mod ,
			 ( (l - 1) % mod * (l) % mod * (2 * (l - 1) + 1) % mod * inv6 % mod) % mod));
			
			if(l < r){
				int m = (l + r) >> 1;	
				
				lazy[2][k << 1] = add(lazy[2][k << 1],((L - 1) % mod * (L - 2) % mod) % mod);
				lazy[2][k << 1 | 1] = add(lazy[2][k << 1 | 1], ((L - 1) % mod * (L - 2) % mod) % mod);
				
				lazy[1][k << 1] = add(lazy[1][k << 1], sub(3 , 2 * L));
				lazy[1][k << 1 | 1] = add(lazy[1][k << 1 | 1], sub(3 , 2 * L));
					
				lazy[0][k << 1] += 1;
				lazy[0][k << 1 | 1] += 1;
			}
			return;
		}
		int m = (l + r) >> 1;
		update(k << 1, l, m, L, R);
		update(k << 1 | 1, m + 1, r, L, R);
		for(int i = 0; i < 3; i++){
			f[i][k] = add(f[i][k << 1], f[i][k << 1 | 1]);
		}
	}
	
	
	int get(int k, int l, int r, int L, int R){
		if(l > r) return 0;
		down(k, l, r);
		if(L > r || R < l) return 0;
		if(L <= l && r <= R) {
			int answer = 0;
			for(int i = 0; i < 3; i++){
				answer = add(answer, f[i][k]);
			}
			return answer;
		}
		int m = (l + r) >> 1;
		return add(get(k << 1, l, m, L, R) , get(k << 1 | 1, m + 1, r, L, R));	
	}
	
	
} ST;

void TestCase(){
	int n, q; cin >> n >> q;
	
	ST.init(1, 1, n);
	
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r;
			ST.update(1, 1, n, l, r); 
		
		} else {
			int l,r; cin >> l >> r;
			int answer = ST.get(1, 1, n, l, r);
			if(answer < 0) answer += mod;
			cout << answer << '\n';
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
