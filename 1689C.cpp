using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> cnt(n);
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<int(int, int)> dfs = [&](int cur, int parent){
        if (ssize(adj[cur]) == 1 && cur || !cur && ssize(adj[cur]) == 0){ // leaf
            return 1;
        }
        if (ssize(adj[cur]) == 2 && cur || !cur && ssize(adj[cur]) == 1){ // 1 edge stop
            return 2;
        }
        /* if (int sz = ssize(adj[cur]); sz <= (2 - (cur==0))){ */
        /*     return 1 + (sz == 2 && cur || sz == 1 && cur == 0); */
        /* } */
        int ans = INT_MAX;
        for (int next : adj[cur]) if (parent != next){
            ans = min(ans, dfs(next, cur));
        }
        return ans+2;
    };
    cout << n - dfs(0, -1);
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
