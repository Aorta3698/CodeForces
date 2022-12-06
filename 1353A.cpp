using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, m;
    cin >> m >> n;
    if (m == 1){
        cout << 0 << '\n';
    }else if (m == 2){
        cout << n << '\n';
    }else{
        cout << 2*n << '\n';
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
