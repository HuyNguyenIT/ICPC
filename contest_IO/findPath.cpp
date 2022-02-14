#include <bits/stdc++.h>

using namespace std;

#define int long long

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct item{
    int changes;
    pair<int, int> pos;
    int last_move;
    bool operator<(const item&b)const
    {
        return changes<= b.changes;
    }
};

bool good(int x, int y, int n, int m){
    if(x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1) return true;
    return false;
}

void bfs(vector<vector<char>> &v, pair<int, int> begin, pair<int, int> end, int n, int m){
    
    vector<vector<int>> mymap(n + 5, vector<int>(m + 5, 10000));

    mymap[begin.first][begin.second] = 0;
/*        (i == 1)
          (2)
           ^
           |
(i == 2)   |
(-1)<------------------> (1) (i == 3)
           |   
           |
           V (i == 0)
          (-2)
                                                */
    mymap[begin.first][begin.second] = 0;
   
    priority_queue<item> q;
    q.push({0, begin, 0});

    while (!q.empty()) {
        pair<int, int> position = q.top().pos;
        int changes = q.top().changes;
        int last_dir = q.top().last_move;
        q.pop();

        if(position == end){
            if(changes <= 2){
                cout << "YES\n";
                return;
            } 
        }

        if (changes > mymap[position.first][position.second])
            continue;
        int x = position.first;
        int y = position.second;
        // cout << x << ' ' << y << ' ' << changes << '\n';
        if(changes != mymap[position.first][position.second] || changes > 2) continue;

        for (int i = 0; i < 4; i++) {
            if(last_dir == 0){
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(good(new_x, new_y, n, m) && v[new_x][new_y] != '*'){
                    if(i == 0){
                        q.push({0, {new_x, new_y}, -2});
                        mymap[new_x][new_y] = 0;
                    } else if(i == 1){
                        q.push({0, {new_x, new_y}, 2});
                        mymap[new_x][new_y] = 0;
                    } else if(i == 2){
                        q.push({0, {new_x, new_y}, -1});
                        mymap[new_x][new_y] = 0;
                    } else if(i == 3){
                        q.push({0, {new_x, new_y}, 1});
                        mymap[new_x][new_y] = 0;
                    }
                }
            } else {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(good(new_x, new_y, n, m) && v[new_x][new_y] != '*'){
                    if(i == 0){
                        int new_changes = changes;
                        if(last_dir != -2){
                            new_changes += 1;
                        }

                        if(mymap[new_x][new_y] > new_changes){
                            q.push({new_changes, {new_x, new_y}, -2});
                            mymap[new_x][new_y] = new_changes;
                        }
                    } else if(i == 1){
                        int new_changes = changes;
                        if(last_dir != 2){
                            new_changes += 1;
                        }

                        if(mymap[new_x][new_y] > new_changes){
                            q.push({new_changes, {new_x, new_y}, 2});
                            mymap[new_x][new_y] = new_changes;
                        }
                    } else if(i == 2){
                       int new_changes = changes;
                        if(last_dir != -1){
                            new_changes += 1;
                        }

                        if(mymap[new_x][new_y] > new_changes){
                            q.push({new_changes, {new_x, new_y}, -1});
                            mymap[new_x][new_y] = new_changes;
                        }
                    } else if(i == 3){
                        int new_changes = changes;
                        if(last_dir != 1){
                            new_changes += 1;
                        }

                        if(mymap[new_x][new_y] > new_changes){
                            q.push({new_changes, {new_x, new_y}, 1});
                            mymap[new_x][new_y] = new_changes;
                        }
                    }
                }
            }
           
        }
    }
    cout << "NO\n";
    return;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n + 5, vector<char>(m + 5));
    pair<int, int> begin, end;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'S'){
                begin = {i, j};
            } else if(v[i][j] == 'T'){
                end = {i, j};
            }
        }
    }
    bfs(v, begin, end, n, m);
}
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("input.txt", "r", stdin);

    int t = 1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}