using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int prime;
    for (prime = 2*n-2;;++prime){
        bool ok = 1;
        for (int j = 2; j*j <= prime && ok; ++j){
            ok &= prime % j > 0;
        }
        if (ok){
            break;
        }
    }
    cout << 2 << ' ' << prime << '\n';
    for (int i = 1; i <= n && m; ++i){
        for (int j = i+1; j <= n && m; ++j, --m){
            int ans = i == 1 && j != n - 1? 2 : (i == 1? prime - 2 * (n - 2) : prime);
            cout << i << ' ' << j << ' ' << ans << '\n';
        }
    }
}
