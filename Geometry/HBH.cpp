#include<bits/stdc++.h>
using namespace std;

struct P{
    int x, y; 
    P midPoint(P p){
        return {(x + p.x), (y + p.y)};
    }

};

bool equal(P p1, P p2){
    if(p1.x == p2.x && p1.y == p2.y) return true;
    return false;
}
bool cmp(P a, P b){
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
void TestCase(){
    int n; cin >> n;
    vector<P> a;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x ; cin >> y;
        a.push_back({x, y});
    }
    vector<P> answer;
    for (int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            answer.push_back({a[i].midPoint(a[j])});
        }
    }

    sort(answer.begin(), answer.end(), cmp);
    int res = 0;
    int l = 0, r = 0;
    for(int i = 0; i < answer.size() - 1; i++){
        if(equal(answer[i], answer[i + 1])){
            r += 1;
        } else {
            int k = r - l + 1;
            res += k * (k - 1) / 2;
            l = i + 1;
            r = i + 1;
        }
    }
    cout << res << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int ntest = 1; cin >> ntest;

    while(ntest--){
        TestCase();
    }
    return 0;
}