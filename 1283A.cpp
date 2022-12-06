using namespace std;
#include <bits/stdc++.h>

void solve(){
    int h, m;
    cin >> h >> m;
    cout << 60*24 - 60*h - m << '\n';
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
