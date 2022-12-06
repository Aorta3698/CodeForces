using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    string s;
    cin >> n >> s;
    auto[a, b] = ranges::unique(s);
    s.erase(a, b);
    set<char> S;
    for (char ch : s){
        if (S.contains(ch)){
            cout << "NO" << '\n';
            return;
        }
        S.insert(ch);
    }
    cout << "YES" << '\n';
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
