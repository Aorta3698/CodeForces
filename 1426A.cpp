using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, x;
    cin >> n >> x;
    int cur = 2;
    for (int i = 1; ;++i){
        if (cur >= n){
            cout << i << '\n';
            return;
        }
        cur += x;
    }
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
