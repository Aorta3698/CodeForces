using namespace std;
#include <bits/stdc++.h>

mt19937 mt((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> gen(0, INT_MAX);

void solve(){
    int n;
    cin >> n;
    while(1){
        int tot = 0;
        unordered_set<int> seen;
        vector<int> ans;
        while(ssize(seen) != n-1){
            int got = gen(mt);
            if (seen.insert(got).second){
                tot ^= got;
                ans.push_back(got);
            }
        }
        if (!seen.contains(tot)){
            ans.push_back(tot);
            for (int x : ans){
                cout << x << ' ';
            }
            return;
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
