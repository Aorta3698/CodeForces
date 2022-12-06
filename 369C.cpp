using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<array<int, 3>>> adj(n);
    for (int i = 1; i < n; ++i){
        int x, y, t;
        cin >> x >> y >> t;
        --x, --y, --t;
        adj[x].push_back({y, t, i});
        adj[y].push_back({x, t, i});
    }
    vector<int> ans;
    function<bool(int,int)> dfs = [&](int cur, int parent){
        bool res = 0;
        for (auto& [next, bad, i] : adj[cur]) if (next != parent){
            bool a = dfs(next, cur);
            res |= a;
            if (!a && bad){
                ans.push_back(next+1);
                res = 1;
            }
        }
        return res;
    };

    dfs(0, -1);
    cout << ans.size() << '\n';
    for (int x : ans){
        cout << x << ' ';
    }
}
