#include<bits/stdc++.h>

using namespace std;

int const N = 1005;

struct{
    int f[N << 2][2];

    void init(int k, int l, int r){
        if(l == r) {
            f[k][0] = 0;
            f[k][1] = 0;
            
        }
        if(l < r){
            int m = (l + r) >> 1;
            init(k << 1, l, m);
            init(k << 1 | 1, m + 1, r);
            f[k][1] = f[k << 1][1] + f[k << 1 | 1][1];
            f[k][0] = f[k << 1][0] + f[k << 1 | 1][0];
        }
    }

    void update(int k, int l, int r, int pos ,int v, int ip){
        if(l > r) return;
        if(l > pos || pos > r) return;
        if(l == r && l == pos){
            f[k][ip] = v;
            return;
        }
        int m = (l + r) >> 1;
        update(k << 1, l, m, pos, v, ip);
        update(k << 1 | 1, m + 1, r, pos, v, ip);
        f[k][1] = max(f[k << 1][1], f[k << 1 | 1][1]);
        f[k][0] = max(f[k << 1][0], f[k << 1 | 1][0]);
    }

    int get(int k, int l, int r, int L, int R, int ip){
        if(l > r) return 0;
        if(L > r || R < l) return 0;
        if(L <= l && r <= R) return f[k][ip];
        int m = (l + r) >> 1;
        return max(get(k << 1, l, m, L, R, ip) ,get(k << 1 | 1, m + 1, r, L, R, ip));	
    }

} ST;


struct item{
    int v, pos;
};

bool cmp(item x, item y){
    return make_pair(x.v, x.pos) < make_pair(y.v, y.pos);
}
class Solution {
public:
    int wiggleMaxLength(vector<int>& aa) {
        int n = aa.size();
        vector<item> a(n);
        for(int i = 0; i < n; i++){
            a[i].v = aa[i];
            a[i].pos = i;
        }
        vector<item> odd_a = a;
        sort(a.begin(), a.end(), cmp);

        map<int, int> mymap;
        int k = 1;
        int len = 1;
        for(int i = 0; i < n; i++){
            if(mymap[a[i].v] == 0){
                mymap[a[i].v] = k;
                len = k;
                k++;
            }
        }
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            b[i] = mymap[odd_a[i].v];
        }

        vector<vector<int>> f(n, vector<int> (2, 0));
        ST.init(1, 1, len);;
        for(int i = 0; i < n; i++){
            f[i][0] = 1;
            f[i][1] = 1;
            f[i][0] = max(ST.get(1, 1, len, b[i] + 1, len, 1) + 1, f[i][0]);
            f[i][1] = max(ST.get(1, 1, len, 1, b[i] - 1, 0) + 1, f[i][1]);
            ST.update(1, 1, len, b[i], f[i][0], 0);
            ST.update(1, 1, len, b[i], f[i][1], 1);
            
        }
        return max(f[n - 1][1], f[n - 1][0]) << '\n';
    }
};



int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    
}