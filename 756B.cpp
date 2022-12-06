using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& x : A){
        cin >> x;
    }
    vector<long long> dp(n+1, 1e18);
    dp[0] = 0;
    for (int i = 1, j = 1, k = 1; i <= n; ++i){
        while(A[i-1] - A[j - 1] >= 90){
            ++j;
        }
        while(A[i-1] - A[k - 1] >= 1440){
            ++k;
        }
        long long opt1 = dp[i - 1] + 20;
        long long opt2 = dp[j - 1] + 50;
        long long opt3 = dp[k - 1] + 120;
        dp[i] = min({opt1, opt2, opt3});
        cout << dp[i] - dp[i-1] << '\n';
    }
}
