using namespace std;
#include <bits/stdc++.h>

class UF {
    public:
        vector<int> size, parent;
        UF (int n) : size(n, 1), parent(n){
            iota(begin(parent), end(parent), 0);
        }

        inline int leader(int x){
            return x == parent[x]? x : parent[x] = leader(parent[x]);
        }

        void unite(int x,int y){
            x = leader(x), y = leader(y);
            if (x == y){
                return;
            }
            if (size[y] > size[x]){
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
        }

        vector<vector<int>> groups(){
            vector<vector<int>> g(int(parent.size()));
            for (int i = 0; i < int(parent.size()); ++i){
                g[leader(i)].push_back(i);
            }
            return g;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >>m >> k;
    vector<int> c(n);
    UF uf(n);
    for (int& a : c) cin >> a, --a;
    while(m--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        uf.unite(a, b);
    }
    int ans = 0;
    auto groups = uf.groups();
    for (int i = 0; i < int(groups.size()); ++i){
        int mx = 0;
        unordered_map<int,int> mp;
        for (int j : groups[i]){
            mx = max(mx, ++mp[c[j]]);
        }
        ans += int(groups[i].size()) - mx;
    }

    cout << ans;
}
