using namespace std;
#include <bits/stdc++.h>

void solve(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (int sum=a+b+c+n; sum%3 || max({a,b,c})>sum/3){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
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
