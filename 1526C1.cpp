using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> dp(n+1);
    vector<int> p(n);
    ranges::fill(dp, -1e9);
    dp[0] = 0;
    for (int& x : p){
        cin >> x;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = i; j > 0; --j){
            if (dp[j-1]+p[i-1]>=0){
                dp[j]=max(dp[j-1]+p[i-1], dp[j]);
            }
        }
    }
    for (int i = n; i >= 0; --i) if (dp[i] >= 0){
        cout << i;
        return 0;
    }
}
