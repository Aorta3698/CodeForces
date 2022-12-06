using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s, t;
    cin >> n >> s >> t;
    array<unordered_set<int>, 26> adj;
    for (int i = 0; i < n; ++i){
        adj[s[i]-'a'].insert(t[i]-'a');
        adj[t[i]-'a'].insert(s[i]-'a');
    }
    array<int, 26> seen;
    array<vector<int>, 26> cnt;
    seen.fill(-1);
    function<void(int,int)> dfs = [&](int cur, int m){
        if (seen[cur] == -1){
            seen[cur] = m;
            cnt[m].push_back(cur);
            for (int next : adj[cur]){
                dfs(next, m);
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < 26; ++i){
        dfs(i, i);
        ans += max(int(cnt[i].size()) - 1, 0);
    }

    cout << ans << '\n';
    for (auto& v : cnt){
        for (int i = 1; i < int(v.size()); ++i){
            cout << char(v[i-1]+'a') << ' ' << char(v[i]+'a') << '\n';
        }
    }
}
