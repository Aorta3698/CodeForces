using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int MAX=1e5+1, n;
    int cnt[MAX]{};
    long long dp[MAX]{};
    cin >> n;
    while(cin >> n){
        ++cnt[n];
    }
    for (int i = 1; i < MAX; ++i){
        dp[i] = max((i==1?0:dp[i-2])+1LL*i*cnt[i], dp[i-1]);
    }
    cout << dp[MAX-1];
    /* map<int, int> mp; */
    /* int n; */
    /* cin >> n; */
    /* while(cin >> n){ */
    /*     ++mp[n]; */
    /* } */
    /* long long dp[]{0, 0, -1}; */
    /* for (auto k : mp){ */
    /*     long long ndp[3]{}; */
    /*     ndp[0] = max(dp[0], dp[1]); */
    /*     ndp[1] = 1LL*k.first*k.second + (k.first == dp[2]+1? dp[0] : max(dp[0], dp[1])); */
    /*     ndp[2] = k.first; */
    /*     swap(dp, ndp); */
    /* } */
    /* cout << max(dp[0], dp[1]); */
}
