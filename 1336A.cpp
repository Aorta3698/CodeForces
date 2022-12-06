using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> all;
    function<int(int,int,int)> dfs = [&](int cur, int parent, int depth){
        int res = 0;
        for (int next : adj[cur]) if (next != parent){
            res += dfs(next, cur, depth+1);
        }
        all.push_back(depth - res);
        return res+1;
    };
    dfs(0, -1, 0);
    /* ranges::sort(all); */
    ranges::nth_element(all, k+begin(all)-1, greater<>());
    long long ans = 0;
    for (int i = 0; i < k; ++i){
        ans += all[i];
    }
    /* for (int i = n-1; i >= n-k; --i){ */
    /*     ans += all[i]; */
    /* } */
    cout << ans;
}
