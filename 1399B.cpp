using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int&x : a){
        cin >> x;
    }
    for (int& x : b){
        cin >> x;
    }
    int amin = *ranges::min_element(a);
    int bmin = *ranges::min_element(b);
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        ans += max(b[i]-bmin, a[i]-amin);
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
