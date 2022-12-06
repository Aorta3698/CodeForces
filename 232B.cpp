using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, M = int(1e9)+7;
    long long m;
    cin >> n >> m >> k;

    array<long long, 101> fact{1, 1}, invfact{1, 1}, inv{0, 1};
    for (int i = 2; i <= 100; ++i){
        inv[i] = M - M/i*inv[M%i] % M;
        fact[i] = fact[i-1] * i % M;
        invfact[i] = invfact[i-1] * inv[i] % M;
    }

    auto comb = [&](int a, int b){
        return fact[a] * invfact[b] % M * invfact[a-b] % M;
    };

    auto fastpow = [&M](long long v, long long e){
        v %= M;
        long long res = 1;
        while(e){
            if (e & 1){
                res *= v;
                res %= M;
            }
            v *= v;
            v %= M;
            e >>= 1;
        }
        return res;
    };

    vector<long long> c(n+1);
    for (int i = 0; i <= n; ++i){
        c[i] = fastpow(comb(n, i), m/n);
    }

    vector<vector<long long>> dp(n+1, vector<long long>(k+1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= k; ++j){
            for (int k = 0; k <= min(n, j); ++k){
                long long got = c[k] * (m % n >= i? comb(n, k) : 1) % M;
                dp[i][j] += dp[i - 1][j - k] * got % M;
                dp[i][j] %= M;
            }
        }
    }

    cout << dp[n][k];
}
