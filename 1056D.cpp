using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 2; i <= n; ++i){
        int b = i - 1, a;
        cin >> a;
        --a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> cnt(n), has(n+1);
    function<void(int,int)> dfs = [&](int cur, int parent){
        for (int next : adj[cur]) if (next != parent){
            dfs(next, cur);
            cnt[cur] += cnt[next];
        }
        cnt[cur] = max(cnt[cur], 1);
        ++has[cnt[cur]];
    };
    dfs(0, -1);
    for (int i = 1, j = 0, sum = 0; i <= n; ++i){
        while(sum < i){
            sum += has[++j];
        }
        cout << j << ' ';
    }
}
