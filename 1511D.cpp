using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string ans;
    vector<vector<int>> adj(k);
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < k ; ++j){
            adj[i].push_back(j);
        }
    }
    function<void(int)> dfs = [&](int cur){
        while(adj[cur].size()){
            int last = adj[cur].back();
            adj[cur].pop_back();
            dfs(last);
        }
        ans += char('a' + cur);
    };
    dfs(0);
    reverse(begin(ans), end(ans));
    string res = ans;
    while(int(res.size()) < n){
        res += ans.substr(1);
    }
    cout << res.substr(0, n);
}
