using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, M = int(1e9) + 7;
    cin >> n >> m >> k;
    long long ans = 1;
    if (k > n || k == 1){
        while(n--){
            ans *= m;
            ans %= M;
        }
    }else if (k == n){
        n = (n+1)/2;
        while(n--){
            ans *= m;
            ans %= M;
        }
    }else{
        ans = (k&1? m*m:m);
    }
    cout << ans;
}
