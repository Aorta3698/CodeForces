using namespace std;
#include <bits/stdc++.h>

void solve(){
    int a, b;
    cin >> a >> b;
    cout << (a==b? 0 : b>a&&(b-a)%2||b<a&&(a-b)%2==0? 1 : 2) << '\n';
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
