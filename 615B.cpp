using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long ans = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i){
        for (int j : adj[i]){
            if (j < i){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, 1LL * dp[i] * int(size(adj[i])));
    }
    cout << ans;
}
