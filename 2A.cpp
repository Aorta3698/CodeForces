using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = -1e9;
    cin >> n;
    unordered_map<string, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; ++i){
        string s;
        int a;
        cin >> s >> a;
        int score = mp.contains(s)?mp[s].back().first+a:a;
        mp[s].push_back({score, i});
    }
    for (auto m : mp){
        mx = max(mx, m.second.back().first);
    }
    string ans;
    int best = 1e9;
    for (auto& [name, v] : mp){
        if (v.back().first == mx){
            for (auto& [score, time] : v){
                if (score >= mx && time < best){
                    ans = name;
                    best = time;
                }
            }
        }
    }
    cout << ans;
}
