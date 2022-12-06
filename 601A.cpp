using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, which = 0;
    cin >> n >> m;
    vector<vector<bool>> mp(n, vector<bool>(n));
    while(m--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        mp[a][b] = mp[b][a] = 1;
        which |= min(a, b) == 0 && max(a, b) == n - 1;
    }
    queue<int> q;
    vector<bool> seen(n);
    q.push(0);
    int ans = 0;
    seen[0] = 1;
    while(q.size()){
        for (int sz = int(q.size()); sz; --sz){
            int cur = q.front();
            q.pop();
            if (cur == n - 1){
                cout << ans;
                return 0;
            }
            for (int i = 0; i < n; ++i){
                if (mp[cur][i] ^ which && !seen[i]){
                    seen[i] = 1;
                    q.push(i);
                }
            }
        }
        ++ans;
    }
    cout << -1;
}
