#include<bits/stdc++.h>

using namespace std;

double const esp = 0.001;


void solve(){
    int n, d; cin >> n >> d;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    vector<vector<double>> f(n + 5, vector<double> (11, -INT_MAX));

    for(int i = 1; i <= n; i++){
        f[i][v[i - 1] % 10] = log(v[i - 1]);
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            if(abs(f[i - 1][j] + INT_MAX) < esp) continue;
            f[i][j] = max(f[i - 1][j], f[i][j]);
            f[i][(j * v[i - 1]) % 10] = max(f[i][(j * v[i - 1]) % 10], f[i - 1][j] + log(v[i - 1]));
        }
    }
    
    if(abs(f[n][d] + INT_MAX) < esp){
        cout << -1 << '\n';
    } else {
        vector<int> answer;
        int i = n, j = d;

        while(i > 0){
            if(abs(f[i][j] - f[i - 1][j]) < esp) {
                i -= 1;
            } else {
                bool ok = false;
                answer.push_back(v[i - 1]);
                for(int last = 0; last < 10; last += 1){
                    if((last * v[i - 1]) % 10 == j){
                        if(abs(f[i - 1][last] + log(v[i - 1]) - f[i][j]) < esp) {
                            j = last;
                            i -= 1;
                            ok = true;
                            break;
                        }
                    }
                }
                if(!ok) break;
            }
            
        }
        cout << answer.size() << '\n';
        for(auto&x : answer) cout << x << ' ';
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    // freopen("input.txt", "r", stdin);
    int t = 1;
    while(t--){
        solve();
    }
} 