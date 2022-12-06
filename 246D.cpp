using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> color(n);
    vector<vector<int>> adj(n);
    for (int& x : color){
        cin >> x;
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 1e9, mx = 0;
    vector<bool> seen(n);
    array<unordered_set<int>, 100001> cnt;
    function<void(int)> dfs = [&](int cur){
        if (seen[cur]){
            return;
        }
        seen[cur] = 1;
        for (int next : adj[cur]){
            if (color[cur] != color[next]){
                cnt[color[cur]].insert(color[next]);
                mx = max(mx, int(cnt[color[cur]].size()));
            }
            dfs(next);
        }
    };

    for (int i = 0; i < n; ++i){
        dfs(i);
    }
    for (int n : color){
        if (mx == int(cnt[n].size())){
            ans = min(ans, n);
        }
    }
    cout << ans;
}
