using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1, f; i <= n; ++i){
        cin >> f;
        for (int u : {i - f, i + f}){
            if (u > 0 && u <= n){
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }
    }
    vector<bool> seen(n+1);
    function<int(int)> dfs = [&](int cur){
        int ans = 0;
        if (!seen[cur]){
            seen[cur] = 1;
            ans ^= cur ^ v[cur];
            for (int next : adj[cur]){
                ans ^= dfs(next);
            }
        }
        return ans;
    };
    for (int i = 1; i <= n; ++i){
        if (dfs(i)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
