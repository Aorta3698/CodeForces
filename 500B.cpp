using namespace std;
#include <bits/stdc++.h>

class UF {
    public:
    vector<int> rank, parent;
    UF (int n) : rank(n), parent(n){
        iota(begin(parent), end(parent), 0);
    }

    inline int leader(int x){
        return x == parent[x]? x : (parent[x] = leader(parent[x]));
    }

    void unite(int x, int y){
        x = leader(x);
        y = leader(y);
        if (x == y){
            return;
        }
        if (rank[y] > rank[x]){
            swap(x, y);
        }
        if (rank[y] == rank[x]){
            ++rank[x];
        }
        parent[y] = x;
    }

    unordered_map<int, vector<int>> groups(){
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < int(parent.size()); ++i){
            mp[leader(i)].push_back(i);
        }
        return mp;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    UF uf(n);
    for (int& x : A){
        cin >> x;
    }
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j){
            if (s[j] == '1'){
                uf.unite(i, j);
            }
        }
    }
    auto groups = uf.groups();
    for (auto& [_, a] : groups){
        ranges::sort(a, [&](int i, int j){return A[i] > A[j];});
    }
    for (int i = 0; i < n; ++i){
        cout << A[groups[uf.leader(i)].back()] << ' ';
        groups[uf.leader(i)].pop_back();
    }
}
