using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n,p,k;
    cin >> n >> p >>k ;
    vector<int> dp(n+1,-1), A(n);
    dp[0] = p;
    for (int& x : A){
        cin >> x;
    }
    ranges::sort(A);
    for (int i = 1; i <= n; ++i){
        dp[i] = i >= k? -A[i-1] + dp[i-k]: -A[i-1] + dp[i-1];
    }
    for (int i = n; ~i; --i) if (dp[i] >= 0){
        cout << i;
        return;
    }
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
