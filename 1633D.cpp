using namespace std;
#include <bits/stdc++.h>

void solve(){
    static array<vector<int>, 1001> adj{};
    if (adj[1].size() == 0){
        for (int i = 1; i <= 1000; ++i){
            for (int j = 1, p=-1; j <= i; ++j){
                if (i/j != p && i+i/j<=1000){
                    adj[i].push_back(i+i/j);
                    p = i/j;
                }
            }
        }
    }
    int n, k;
    cin >> n >> k;
    vector<int> coins(n), op(n);
    array<int, 1001> seen;
    seen.fill(-1);
    for (int i = 0, b; i < n; ++i){
        cin >> b;
        queue<int> q;
        q.push(1);
        bool ok = 1;
        while(ok){
            for (int sz = ssize(q); sz; --sz){
                int cur = q.front();
                ok &= cur != b;
                q.pop();
                for (int next : adj[cur]) if (seen[next] != i){
                    seen[next] = i;
                    q.push(next);
                }
            }
            op[i] += ok;
        }
    }
    int mx = min(reduce(begin(op), end(op)), k);
    vector<int> dp(mx+1);
    for (int i = 0, c; i < n; ++i){
        cin >> c;
        for (int j = mx; j >= op[i]; --j){
            dp[j] = max(dp[j], dp[j-op[i]] + c);
        }
    }
    cout << dp[mx];
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
