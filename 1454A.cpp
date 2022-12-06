using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= n+2; ++i){
        if (i != n+1){
            cout << i%(n+1) << ' ';
        }
    }
    cout << '\n';
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
