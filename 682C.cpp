using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n;
    vector<int> val(n);
    vector<vector<pair<int,int>>> adj(n);
    for (int&v : val){
        cin >> v;
    }
    for (int i = 1, a, b; i < n; ++i){
        cin >> a >> b;
        --a;
        adj[i].push_back({a, b});
        adj[a].push_back({i, b});
    }
    function<int(int, int, int, bool)> dfs = [&](int cur, int parent, int sum, bool bad){
        bad |= sum > val[cur];
        int res = bad;
        for (auto& [next, cost] : adj[cur]) if (next != parent){
            res += dfs(next, cur, max(sum + cost, cost), bad);
        }
        return res;
    };
    cout << dfs(0, -1, 0, false);
}
