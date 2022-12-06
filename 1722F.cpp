using namespace std;
#include <bits/stdc++.h>

int dx[8]{1, 1, 1, -1, -1, -1, 0, 0};
int dy[8]{-1, 0, 1, -1, 0, 1, -1, 1};

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; ++i){
        for (auto& c : grid[i]){
            cin >> c;
        }
    }
    auto norm = [&](auto p){
        vector<int> dist;
        for (auto& [a, b] : p){
            for (auto& [c, d] : p){
                dist.push_back((a-c)*(a-c)+(b-d)*(b-d));
            }
        }
        ranges::sort(dist);
        return dist;
    };
    function<void(int, int, vector<pair<int, int>>&)> dfs = [&](int i, int j, auto& p){
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] != '*'){
            return;
        }
        grid[i][j] = 'x';
        p.push_back({i, j});
        for (int k = 0; k < 8; ++k){
            dfs(i+dx[k], j+dy[k], p);
        }
    };
    vector<int> need = norm(vector<pair<int, int>>{{0, 0}, {1, 0}, {0, 1}});
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            vector<pair<int, int>> p;
            dfs(i, j, p);
            if (ssize(p) > 0 && (ssize(p) != 3 || norm(p) != need)){
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
