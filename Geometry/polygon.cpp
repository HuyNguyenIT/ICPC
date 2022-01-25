#include<bits/stdc++.h>
using namespace std;

struct P{
    int x, y; 
    P midPoint(P p){
        return {(x + p.x), (y + p.y)};
    }
    
};

int sign(P p1, P p2){
	int dot = p1.x*p2.x + p1.y*p2.y ;
	int det = p1.x*p2.y - p1.y*p2.x;
	double angle = atan2(det, dot);
	if(angle > 0) return 1;
    else return -1;
}

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
    a.push_back(a[0]);
    a.push_back(a[1]);
    int last = 0;
    for(int i = 0; i < n; i++){
        int cur = sign({a[i + 1].x - a[i].x, a[i + 1].y - a[i].y},
         {a[i + 2].x - a[i + 1].x, a[i + 2].y - a[i + 1].y});
         if(last == 0) last = cur;
         else if(last != cur){
             cout << 0 << '\n';
             return;
         }
    }
    cout << 1 << '\n';
    
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