using namespace std;
#include <bits/stdc++.h>

class UF {
public:
    vector<int> parent;
    vector<int> rank;
    int N;
    UF (int n) : N{n}, parent(n), rank(n){
        /* parent.resize(n); */
        /* rank.resize(n); */
        iota(begin(parent), end(parent), 0);
    }
    int find(int x){
        return x == parent[x]? x:(parent[x]=find(parent[x]));
    }
    void unite(int x, int y){
        if (x < 0 || y < 0 || x >= N || y >= N){
            return;
        }
        x = find(x); y = find(y);
        if (x == y){
            return;
        }
        if (rank[y] > rank[x]){
            swap(x, y);
        }
        parent[y] = x;
        if (rank[x] == rank[y]){
            ++rank[x];
        }
    }
};

void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    UF uf(n);
    for (int i = 0; i < n; ++i){
        uf.unite(i, n-1-i);
        uf.unite(i, i+k);
    }
    unordered_map<int, int[26]> mp;
    unordered_map<int, int> mx;
    for (int i = 0; i < n; ++i){
        int l = uf.find(i);
        mx[l]=max(mx[l], ++mp[l][s[i]-'a']);
    }
    int ans = ssize(s);
    for (auto m : mx){
        ans -= m.second;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
