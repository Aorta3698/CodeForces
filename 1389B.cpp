using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, k, z;
    long long ans = 0;
    cin >> n >> k >> z;
    vector<long long> A(n), dp(k+2);
    for (long long& x : A){
        cin >> x;
    }
    for (int i = 0; i <= z; ++i){
        vector<long long> ndp(k+2);
        for (int j = 0; j <= k-2*i; ++j){
            ndp[j] = max(j==0?0:ndp[j-1], dp[j+1]) + A[j];
        }
        swap(ndp, dp);
        ans = max(ans, *ranges::max_element(dp));
    }
    cout << ans;
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
