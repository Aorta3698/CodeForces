using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, d, M = (int)1e9+7;
    cin >> n >> k >> d;
    vector<array<int, 2>> dp(n+1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = min(i,k); j; --j){
            for (int k = 0; k < 2; ++k){
                int nk = j >= d || k;
                dp[i][nk] += dp[i-j][k];
                dp[i][nk] %= M;
            }
        }
    }
    cout << dp[n][1];
}
