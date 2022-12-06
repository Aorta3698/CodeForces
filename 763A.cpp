using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> colors(n);
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int& c : colors){
        cin >> c;
    }
    function<bool(int, int)> check = [&](int cur, int parent){
        bool res = 1;
        for (int next : adj[cur]) if (next != parent){
            if (parent != -1){
                res &= colors[next] == colors[cur];
            }
            if (res){
                res &= check(next, cur);
            }
        }
        return res;
    };
    function<int(int, int)> dfs = [&](int cur, int parent){
        if (parent != -1 && colors[cur] != colors[parent]){
            for (int now : {cur, parent}){
                if (check(now, -1)){
                    return now+1;
                }
            }
            return 0;
        }
        for (int next : adj[cur]) if (next != parent){
            if (int res = dfs(next, cur); res != 1){
                return res;
            }
        }
        return 1;
    };
    int ans = dfs(0, -1);
    if (ans == 0){
        cout << "NO";
    }else{
        cout << "YES\n" << ans;
    }
}
