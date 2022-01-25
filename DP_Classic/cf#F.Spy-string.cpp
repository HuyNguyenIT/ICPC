#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 123;

void TestCase(){
    int n, m; cin >> n >> m;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    string answer = "";
    for(int j = 0; j < m; j++){
        set<char> st;
        vector<int> cnt(200, 0);
        for(int i = 0; i < n; i++){
            st.insert(v[i][j]);
            cnt[v[i][j] - 'a'] += 1;
        }
        if(st.size() > 2){
            cout << -1 << '\n';
            return;
        }
        if(st.size() == 1){
            for(auto x : st) answer += x;
            continue;
        }
        for(auto c : st){
            if(cnt[c - 'a'] == 1){
                answer += c;
                break;
            }
        }
    }
    cout << answer.size() << ' ' << answer << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    freopen("input.txt", "r", stdin);
    int T = 1; cin >> T;
    while(T--){
        TestCase();
    }

}