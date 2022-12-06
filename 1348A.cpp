using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    int ans = 1<<n, j = n;
    while(j-- > 1){
        ans += (1<<j)*(j<n/2?1:-1);
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
