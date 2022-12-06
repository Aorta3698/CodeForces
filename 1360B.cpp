using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    ranges::sort(v);
    int ans = INT_MAX;
    for (int i = 1; i < n; ++i){
        ans = min(ans, v[i]-v[i-1]);
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
