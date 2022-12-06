using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, mx = -1e9, ans = 0;
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        ans = max(ans, mx-a<=0?0:32-__builtin_clz(mx-a)); // builtin_clz(0) is undefined!
        mx = max(mx, a);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
