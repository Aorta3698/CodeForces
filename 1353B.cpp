using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int& x : a){
        cin >> x;
    }
    for (int& x : b){
        cin >> x;
    }
    ranges::sort(b);
    ranges::sort(a);
    int ans = 0;
    for (int i = 0; i < n && k--; ++i){
        ans += max(b[n-1-i]-a[i], 0);
    }
    cout << reduce(begin(a), end(a)) + ans << '\n';
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
