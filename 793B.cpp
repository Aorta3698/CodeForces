using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    bool seen[4][3][1000][1000];
    char grid[1000][1000];
    int si, sj, di, dj;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            for (int d = 0; d < 4; ++d){
                for (int t = 0; t < 3; ++t){
                    seen[d][t][i][j] = 0;
                }
            }
            cin >> grid[i][j];
            if (grid[i][j] == 'S'){
                si = i;
                sj = j;
            }else if (grid[i][j] == 'T'){
                di = i;
                dj = j;
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<array<int, 4>> q;
    for (int i = 0; i < 4; ++i){
        q.push({i, 0, si, sj});
        seen[i][0][si][sj] = 1;
    }
    while(q.size()){
        auto [d, t, x, y] = q.front();
        q.pop();
        if (x == di && y == dj){
            cout << "YES";
            return 0;
        }
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd = i;
            int nt = t + (nd != d);
            if (nx < 0 || ny < 0 || nx == m || ny == n || nt > 2 || grid[nx][ny] == '*' || seen[nd][nt][nx][ny]){
                continue;
            }
            seen[nd][nt][nx][ny] = 1;
            q.push({nd, nt, nx, ny});
        }
    }

    cout << "NO";
}
