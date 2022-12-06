using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> type(n);
    vector<vector<int>> q(k);
    vector<vector<int>> dist(n, vector<int>(k, -1));
    for (int i = 0; i < n; ++i){
        cin >> type[i];
        q[--type[i]].push_back(i);
        dist[i][type[i]] = 0;
    }
    vector<vector<int>> adj(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < k; ++i){
        for (int j = 0; j < int(q[i].size()); ++j){
            for (int u : adj[q[i][j]]){
                if (dist[u][i] == -1){
                    dist[u][i] = 1 + dist[q[i][j]][i];
                    q[i].push_back(u);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i){
        ranges::nth_element(dist[i], begin(dist[i]) + s - 1);
        cout << reduce(begin(dist[i]), begin(dist[i]) + s) << ' ';
    }
}
