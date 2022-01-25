#include<bits/stdc++.h>
using namespace std;
void TestCase(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;
    sort(b.begin(), b.end());
    vector<vector<int>> f(n, vector<int>(m, -1));
    f[0][0] = a[0];
    f[0][1] = b[0];
    
    cout << '\n';
    for(auto&x : b) cout << x << ' ';
    cout << '\n';
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i + 1; j++){
            if(a[i] > f[i - 1][j] && f[i - 1][j] != -1){
                f[i][j] = a[i];
            }
            if(j == 0 || f[i - 1][j - 1] == -1) {
                cout << "f[" << i << "][" << j << "] = "<< f[i][j] << ' ';
                continue;

            }
            int pos = upper_bound(b.begin(), b.end(), f[i - 1][j - 1]) - b.begin();
            
            if(pos < m ){
                if(f[i][j] != -1)f[i][j] = min(f[i][j] , b[pos]);
                else f[i][j] = b[pos];
            }
            
            cout << "f[" << i << "][" << j << "] = "<< f[i][j] << ' ';
            
        }
        cout << '\n';
    }
    int answer = INT_MAX;
    for(int i = 0; i < n; i++){
        if(f[n - 1][i] == -1) continue;

        if(f[n - 1][i] != -1) {
            answer = i; break;
        }
    }

    if(answer == INT_MAX) answer = -1;
    cout << "\nanswer = " << answer << '\n';

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int tt; cin >> tt;
    while(tt--){
        TestCase();
    }
}