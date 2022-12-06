using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, INF = int(1e6);
    cin >> m >> n >> k;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; ++i){
        for (auto& ch : grid[i]){
            cin >> ch;
        }
    }

    vector<int> who(m*n);
    function<int(int,int,int)> dfs = [&](int i, int j, int id){
        if (grid[i][j] == '*' || who[i*n+j]){
            return 0;
        }
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
            return -INF;
        }
        who[i*n+j] = id;
        return 1 + dfs(i + 1, j, id)
                 + dfs(i - 1, j, id)
                 + dfs(i, j - 1, id)
                 + dfs(i, j + 1, id);
    };

    vector<pair<int,int>> all;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (int res = dfs(i, j, i*n+j+1); res > 0){
                all.emplace_back(res, i*n+j+1);
            }
        }
    }

    int gone = int(all.size()) - k, ans = 0;
    ranges::nth_element(all, begin(all) + gone - 1);
    vector<bool> mark(m*n);
    for (int i = 0; i < gone; ++i){
        auto& [sz, id] = all[i];
        ans += sz;
        mark[id] = 1;
    }

    cout << ans << '\n';
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (mark[who[i*n+j]]){
                grid[i][j] = '*';
            }
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
