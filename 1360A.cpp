using namespace std;
#include <bits/stdc++.h>

void solve(){
    int a, b;
    cin >> a >> b;
    int s = min({max(2*a,b),max(2*b,a),a+b});
    cout << s*s << '\n';
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
