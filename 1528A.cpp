using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<array<int, 2>> score(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i){
        int& x = score[i][0];
        int& y = score[i][1];
        cin >> x >> y;
    }
    for (int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<long long, 2>> dp(n, array<long long, 2>{});
    function<long long(int, int, int)> dfs = [&](int cur, int parent, int mode){
        if (dp[cur][mode]){
            return dp[cur][mode];
        }
        long long res = 0;
        for (int next : adj[cur]) if (next != parent){
            long long a = dfs(next, cur, 1) + abs(score[cur][mode] - score[next][1]);
            long long b = dfs(next, cur, 0) + abs(score[cur][mode] - score[next][0]);
            res += max(a, b);
        }
        return dp[cur][mode] = res;
    };
    cout << max(dfs(0, -1, 0), dfs(0, -1, 1));
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
