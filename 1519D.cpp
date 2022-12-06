using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> A(n), B(n);
    for (long long&x:A){
        cin >> x;
    }
    for (long long&x:B){
        cin >> x;
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    long long mx = 0, ans = 0;
    for (int i = n-1; ~i; --i){
        for (int j = i; j < n; ++j){
            dp[i][j] = (j-i>1?dp[i+1][j-1] : 0) + A[j]*B[i] + A[i]*B[j] - A[i]*B[i] - A[j]*B[j];
            mx = max(mx, dp[i][j]);
            if (j == i){
                ans += A[i] * B[j];
            }
        }
    }
    cout << ans + mx;
}
