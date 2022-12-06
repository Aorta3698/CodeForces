using namespace std;
#include <bits/stdc++.h>

void solve(){
    string s, t;
    cin >> s >> t;
    array<vector<int>, 26> all;
    for (int i = 0; i < ssize(s); ++i){
        all[s[i]-'a'].push_back(i);
    }
    int ans = 0, cur = -1;
    for (int i = 0; i < ssize(t); ++i){
        if (all[t[i]-'a'].empty()){
            cout << -1;
            return;
        }
        auto it = ranges::upper_bound(all[t[i] - 'a'], cur);
        if (it == end(all[t[i] - 'a'])){
            ++ans;
            cur = all[t[i] - 'a'][0];
        }else{
            cur = *it;
        }
    }
    cout << ans+1;
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
