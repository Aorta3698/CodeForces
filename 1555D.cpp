using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<int>> all;
    for (string t : {"abc", "acb", "bca", "bac", "cab", "cba"}){
        all.push_back({0});
        for (int i = 1; i <= n; ++i){
            all.back().push_back(all.back().back() + (s[i-1] != t[(i-1)%3]));
        }
    }
    while(m--){
        int l, r, res = n;
        cin >> l >> r;
        for (int i = 0; i < 6; ++i){
            res = min(res, all[i][r] - all[i][l-1]);
        }
        cout << res << '\n';
    }
}
