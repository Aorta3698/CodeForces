using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> seen(n), cycle(n);
    vector<int> ans(n, -1);
    int p = -1;

    function<bool(int,int)> dfs = [&](int cur, int parent) -> bool{
        if (seen[cur]){
            ans[p = cur] = 0;
            return cycle[cur] = 1;
        }
        seen[cur] = 1;
        for (int next : adj[cur]) if (next != parent && dfs(next, cur)){
            return cycle[cur]? 0 : cycle[cur] = 1;
        }
        return 0;
    };

    function<void(int)> dist = [&](int cur){
        for (int next : adj[cur]) if (ans[next] == -1){
            ans[next] = cycle[next]? 0 : ans[cur] + 1;
            dist(next);
        }
    };

    dfs(0, -1);
    dist(p);
    for (int d : ans){
        cout << d << ' ';
    }
}
