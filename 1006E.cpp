using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i){
        int x;
        cin >> x;
        adj[i].push_back(x-1);
        adj[x-1].push_back(i);
    }

    vector<int> cnt(n), pos(n), all;
    function<void(int,int)> dfs = [&](int cur, int parent){
        ranges::sort(begin(adj[cur]), end(adj[cur]));
        pos[cur] = int(all.size());
        all.push_back(cur);
        ++cnt[cur];
        for (int next : adj[cur]) if (next != parent){
            dfs(next, cur);
            cnt[cur] += cnt[next];
        }
    };

    dfs(0, -1);
    for (int i = 0; i < q; ++i){
        int u, k;
        cin >> u >> k;
        --u; --k;
        if (k >= cnt[u]){
            cout << -1;
        }else{
            cout << all[pos[u] + k] + 1;
        }
        cout << '\n';
    }
}
