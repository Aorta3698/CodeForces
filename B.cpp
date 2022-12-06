using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    int odd = ranges::count_if(v, [](auto x){return x&1;});
    if (odd != n/2){
        cout << -1 << '\n';
    }else{
        int ans = 0;
        for (int i = 1; i < n; i+=2){
            ans += v[i]%2==0;
        }
        cout << ans << '\n';
    }
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
