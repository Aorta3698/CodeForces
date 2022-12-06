using namespace std;
#include <bits/stdc++.h>

void solve(){
    int cnt[10]{};
    int mx = 0;
    string s;
    cin >> s;
    for (int i = 0; i < ssize(s); ++i){
        mx = max(mx, ++cnt[s[i]-'0']);
    }
    for (int i = 0; i < 10; ++i){
        for (int j = i+1; j < 10; ++j){
            int prev = -1, cur = 0;
            for (char ch : s){
                if (int d = ch - '0'; d==i || d==j){
                    cur += d != prev;
                    prev = d;
                }
            }
            mx = max(mx, cur/2*2);
        }
    }
    cout << ssize(s) - mx << '\n';
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
