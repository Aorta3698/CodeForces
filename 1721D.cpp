using namespace std;
#include <bits/stdc++.h>

// SOLUTION 2 (This is better)
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a){
        cin >> x;
    }
    for (int & x : b){
        cin >> x;
    }
    auto ok = [&](auto mask){
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i){
            ++mp[a[i] & mask];
            --mp[~b[i] & mask];
        }
        for (auto& [key, val] : mp) if (val){
            return false;
        }
        return true;
    };
    int ans = 0;
    for (int i = 30; i >= 0; --i) if (ok(ans|1<<i)){
        ans |= 1<<i;
    }
    cout << ans;
}

// SOLUTION 1 (Simulation)

/* void solve(){ */
/*     int n; */
/*     cin >> n; */
/*     vector<int> a(n), b(n); */
/*     for (int& x : a){ */
/*         cin >> x; */
/*     } */
/*     for (int& x : b){ */
/*         cin >> x; */
/*     } */
/*     auto check = [&](int bit, vector<int> pos){ */
/*         int res = 0; */
/*         for (int p : pos){ */
/*             res += (a[p] & 1<<bit)? 1 : -1; */
/*             res += (b[p] & 1<<bit)? 1 : -1; */
/*         } */
/*         return res==0; */
/*     }; */
/*     int ans = 0; */
/*     function<void(int, vector<vector<int>>&)> solve = [&](int bit, auto& pos){ */
/*         if (bit < 0){ */
/*             return; */
/*         } */
/*         for (auto p : pos) if (!check(bit, p)){ */
/*             solve(bit-1, pos); */
/*             return; */
/*         } */
/*         ans |= 1<<bit; */
/*         vector<vector<int>> nextPos; */
/*         for (auto p : pos){ */
/*             vector<int> sp[2], ssp[2]; */
/*             for (int idx : p){ */
/*                 sp[(b[idx]&1<<bit)>0].push_back(b[idx]); */
/*             } */
/*             for (int idx : p){ */
/*                 int s = (a[idx]&1<<bit)>0; */
/*                 b[idx] = sp[s^1].back(); */
/*                 sp[s^1].pop_back(); */
/*                 ssp[s].push_back(idx); */
/*             } */
/*             for (auto s : ssp) if (!s.empty()){ */
/*                 nextPos.push_back(s); */
/*             } */
/*         } */
/*         solve(bit-1, nextPos); */
/*     }; */
/*     vector<int> self(n); */
/*     iota(begin(self), end(self), 0); */
/*     vector<vector<int>> what{self}; */
/*     solve(30, what); */
/*     cout << ans; */
/* } */

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
