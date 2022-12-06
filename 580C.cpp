using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> mp;
vector<int> cat;
int dfs(int cur, int parent, int has, int m){
    if (cat[cur] && ++has > m){
        return 0;
    }
    if (!cat[cur]){
        has = 0;
    }
    if (mp[cur].size() == 1 && cur){
        return 1;
    }
    int ans = 0;
    for (int next : mp[cur]) if (next != parent){
        ans += dfs(next, cur, has, m);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    mp.resize(n);
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        cat.push_back(a);
    }
    while(--n){
        int a, b;
        cin >> a >> b;
        --a; --b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cout << dfs(0, -1, 0, m);
}
