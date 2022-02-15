#include <bits/stdc++.h>

using namespace std;

#define int long long

struct item{
    int x, y, cost;
    bool operator<(const item&b)const{
        return cost <= b.cost;
    }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y, int n, int m){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

void dijkstra(vector<vector<int>> v, int n, int m){
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> >>> q;
    q.push({v[0][0], {0, 0}});
    vector<vector<int>> d(n + 5, vector<int>(m + 5, 987654321));
    d[0][0] = v[0][0];
    while(!q.empty()){
        int x = q.top().second.first;
        int y = q.top().second.second;
        int cost = q.top().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(check(newx, newy, n, m)){
                if(d[newx][newy] > cost + v[newx][newy]){
                    d[newx][newy] = cost + v[newx][newy];
                    q.push({d[newx][newy], {newx, newy}});
                }
            }
        }
    }
    cout << d[n - 1][m - 1] << '\n';

}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n + 5, vector<int>(m + 5));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
    dijkstra(v, n, m);
}
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}