using namespace std;
#include <bits/stdc++.h>

void solve(){
    string t;
    int n;
    cin >> t >> n;
    int m = ssize(t);
    vector<string> s(n);
    vector<pair<int,int>> all;
    vector<int> dp(m+1, m+1), parent(m+1), path(m+1);
    dp[0] = 0;
    for (auto& x : s){
        cin >> x;
    }
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (t.substr(i).starts_with(s[j])){
                all.push_back({i, j});
            }
        }
    }
    ranges::sort(all);
    for (auto& [l, k] : all){
        for (int i = l, r = l + ssize(s[k]); i < r; ++i){
            if (dp[i] + 1 < dp[r]){
                dp[r] = dp[i] + 1;
                parent[r] = i;
                path[r] = k;
            }
        }
    }
    if (dp[m] > m){
        cout << -1;
    }else{
        cout << dp[m] << '\n';
        while(m){
            cout << path[m]+1 << ' ' << m-ssize(s[path[m]])+1;
            m = parent[m];
            if (m){
                cout << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
