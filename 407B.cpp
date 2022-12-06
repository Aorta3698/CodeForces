using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, M = int(1e9) + 7;
    cin >> n;
    vector<int> jump(n), dp(n+1);
    for (int& x : jump){
        cin >> x;
        --x;
    }
    for (int i = 1; i <= n; ++i){
        dp[i] = 2*dp[i-1] - dp[jump[i-1]] + 2;
        dp[i] %= M;
        dp[i] += M;
        dp[i] %= M;
    }
    cout << dp[n];
}
