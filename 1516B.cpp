using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    unordered_set<int> dp[n];
    for (int i = 0; i < n; ++i){
        int cur = 0;
        for (int j = i; j >= 0; --j){
            cur ^= v[j];
            if (j==0&&i<n-1||j>0&&dp[j-1].contains(cur)){
                dp[i].insert(cur);
            }
        }
    }
    cout << (dp[n-1].size()? "YES" : "NO") << '\n';
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
