using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    string s = to_string(n);
    int sz = ssize(s);
    string t = string(sz, s[0]);
    cout << (sz-1)*9-(t.compare(s)>0?1:0)+s[0]-'0' << '\n';
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
