#include<bits/stdc++.h>

using namespace std;

void TestCase(){
    int n; cin >> n; vector<int> a(n);
    for(auto&x : a) cin >> x;
    vector<vector<int>> f(n, vector<int> (n, 2));
    for(int i = 0; i < n; i++){
        f[i][0] = 1;
        f[i][1] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                f[i][1] = max(f[j][0] + 1, f[i][1]);
            } else if(a[i] < a[j]){
                f[i][0] = max(f[i][0], f[j][1] + 1);
            }
        }
    }
    cout << max(f[n - 1][1], f[n - 1][0]) << '\n';

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int tt; cin >> tt;
    while(tt--){
        TestCase();
    }
}