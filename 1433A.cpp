using namespace std;
#include <bits/stdc++.h>

void solve(){
    int x;
    cin >> x;
    cout << (x%10-1)*10+ssize(to_string(x))*(1+ssize(to_string(x)))/2 << '\n';
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
