using namespace std;
#include <bits/stdc++.h>

void solve(){
    long long n, ans = 0;
    long long sum[2]{}, mi[2]{};
    cin >> n;
    for (int i = 0; i < n; ++i){
        int now;
        cin >> now;
        sum[i&1] += now;
        mi[i&1] = min(mi[i&1], -sum[0] + sum[1]);
        ans = max(ans, -sum[0]+sum[1]-mi[i&1]);
    }
    cout << ans + sum[0];
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
