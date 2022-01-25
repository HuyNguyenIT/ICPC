#include<bits/stdc++.h>

using namespace std;

int const N = 1e5 + 111;

#define int long long

pair<int, int> compute(int pos, vector<int> &v, vector<int> &p, int n){
    set<int> st;
    for(int i = 0; i <= n - pos + 1; i++){
        st.insert(i);
    }
    for(int i = pos; i < n; i++){
        if(v[i] <= n - pos + 1) {
            if (st.find(v[i]) != st.end())
			st.erase(v[i]);
        }
        p.push_back(*st.begin());
    }
    int npos = lower_bound(p.begin(), p.end(), *st.begin()) - p.begin();
    
    return {p[npos], pos + npos};
}

void TestCase(){
    int n; cin >> n;
    set<int> st;
    vector<int> v(n);
    for(auto&x : v) cin >> x;
    map<int, int> f;
    for(int i = 0; i <= n; i++){
        st.insert(i);
    }
    for(auto x : v) f[x] += 1;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        if (st.find(v[i]) != st.end())
			st.erase(v[i]);
        p[i] = *st.begin();
    }
    int target = *st.begin();
    vector<int> answer;
    int pos = lower_bound(p.begin(), p.end(), target) - p.begin();
    answer.push_back(p[pos]);
    while(pos < n - 1){
        vector<int> pp;
        pair<int, int> pi = compute(pos + 1, v, pp, n);
        answer.push_back(pi.first);
        pos = pi.second;
        // cout << pos << ' ' << '\n';
        // cout << pi.first << "    " << pi.second << endl;
    }
    cout << answer.size() << endl;
    for(auto x : answer) cout << x << ' ';
    cout << '\n';
}

int32_t main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(0); cout.tie();
    // freopen("input.txt", "r", stdin);
    int tt; cin >> tt;
    while(tt--){
        TestCase();
    }
}