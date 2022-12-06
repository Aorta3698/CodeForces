using namespace std;
#include <bits/stdc++.h>

void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    int got = n/x*x+y;
    cout << (got > n? got - x : got) << '\n';
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
