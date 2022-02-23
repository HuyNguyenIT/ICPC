#include<bits/stdc++.h>
using namespace std;
#define int long long
struct P{
    long long x, y;
    void read(){
        cin >> x >> y;
    }
    
    P operator - (const P &b) const{
        return P{x - b.x, y - b.y};
    }

    void operator -= (const P &b){
        x -= b.x;
        y -= b.y;
    }

    P operator + (const P &b){
        return P{x + b.x, y + b.y};
    }

    long long operator * (const P &b) const{
        return x * b.y - y * b.x;
    }

    long long triagle(P p1, P p2){
        return (p1 - *this) * (p2 - *this);
    }
};



void TestCase(){
    int n; cin >> n;
    vector<P> points;
    for(int i = 0; i < n; i++){
        P p; p.read();
        points.push_back(p);
    }
    double answer = 0;
    for(int i = 1; i < n - 1; i++){
        answer += points[0].triagle(points[i], points[i + 1]);
    }
    cout << fixed << ' ' << setprecision(3) <<  abs(answer/2) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    // freopen("input.txt", "r", stdin);
    int tt = 1; cin >> tt;
    while(tt--){
        TestCase();
    }
}