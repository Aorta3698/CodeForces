using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    for (int i = 1; i < n-1; ++i){
        if (v[i] != v[i-1] && v[i] != v[i+1]){
            cout << i+1 << '\n';
            return;
        }
    }
    cout << (v[0] == v[1]? n : 1) << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
