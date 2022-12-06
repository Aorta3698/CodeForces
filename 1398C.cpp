using namespace std;
#include <bits/stdc++.h>

void solve(){
    unordered_map<int,int> mp;
    mp[0] = 1;
    int n, adj = 0;
    long long ans = 0;
    string s;
    cin >> n >> s;
    for (char c : s){
        int now = c - '0';
        adj += now-1;
        ans += mp[adj]++;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
