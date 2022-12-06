using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> p(n);
    bool ok = n%2 == 0;
    for (int i = 0; i < n; ++i){
        auto& [a, b] = p[i];
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(i);
        adj[b].push_back(i);
        ok &= int(adj[a].size()) <= 2 && int(adj[b].size()) <= 2;
        ok &= a != b;
    }
    vector<int> c(n, -1);
    function<void(int,int)> dfs = [&](int cur, int color){
        if (c[cur] != -1){
            ok &= c[cur] == color;
            return;
        }
        c[cur] = color;
        auto& [a, b] = p[cur];
        for (int j : {a, b}){
            for (int k : adj[j]) if (k != cur){
                dfs(k, color^1);
            }
        }
    };
    for (int i = 0; i < n && ok; ++i) if (c[i] == -1){
        dfs(i, 0);
    }
    cout << (ok? "YES" : "NO");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
