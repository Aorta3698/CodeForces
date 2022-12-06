using namespace std;
#include <bits/stdc++.h>

void solve(){
    string s;
    cin >> s;
    cout << (s[0]+s[1]+s[2]==s[3]+s[4]+s[5]? "YES" : "NO") << '\n';
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
