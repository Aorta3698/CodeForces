using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    cout << max(0,n-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
