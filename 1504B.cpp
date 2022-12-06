using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<bool> ok(n);
    bool res = 1;
    for (int i = 0, cnt = 0; i < n; ++i){
        a[i] -= '0';
        b[i] -= '0';
        cnt += a[i];
        ok[i] =  2*cnt == i+1;
    }
    for (int i = n-1, now = 0; ~i; --i){
        if ((a[i]^now) != b[i]){
            res &= ok[i];
            now^=1;
        }
    }
    cout << (res? "YES" : "NO");
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
