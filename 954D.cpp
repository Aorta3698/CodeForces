using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> adj(n);
    --s, --t;
    while(m--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int d = 0, ans = 0, INF = int(1e9);
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(t);
    dist[t] = 0;
    while(q.size()){
        ++d;
        for (int sz = int(q.size()); sz; --sz){
            int cur = q.front();
            q.pop();
            for (int next : adj[cur]){
                if (dist[next] == INF){
                    dist[next] = d;
                    q.push(next);
                }
            }
        }
    }
    d = 0;
    q.push(s);
    vector<int> dist2(n, INF);
    dist2[s] = 0;
    while(q.size()){
        ++d;
        for (int sz = int(q.size()); sz; --sz){
            int cur = q.front(), add = 0;
            q.pop();
            for (int i = 0; i < n; ++i){
                add += i != cur && min(dist2[cur] + dist[i], dist2[i] + dist[cur]) + 1 >= dist[s];
            }
            for (int next : adj[cur]){
                add -= min(dist2[cur] + dist[next], dist2[next] + dist[cur]) + 1 >= dist[s];
                if (dist2[next] == INF){
                    dist2[next] = d;
                    q.push(next);
                }
            }
            ans += add;
        }
    }

    cout << ans/2;
}
