using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int, vector<pair<int, int>>> mp;
    vector<int> ans(n-1, -1);
    for (int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        mp[a].push_back({b, i});
        mp[b].push_back({a, i});
    }
    int num = 0;
    for (auto& [key, val] : mp){
        if (ssize(val) >= 3){
            for (auto& [_, idx] : val){
                ans[idx] = num++;
            }
            break;
        }
    }

    auto dfs = [&] // write this way because it is faster.
    {
        auto WTF = [&](int cur, int parent, const auto& me)
        {
            if (false) return; // It won't compile without it! SO WEIRD!!
            for (auto& [next, idx] : mp[cur]) if(next != parent){
                if (ans[idx] == -1){
                    ans[idx] = num++;
                }
                me(next, cur, me);
            }
        };
        WTF(0, -1, WTF);
    };
    /* function<void(int, int)> dfs = [&](int cur, int parent){ */
    /*     for (auto& [next, idx] : mp[cur]) if(next != parent){ */
    /*         if (ans[idx] == -1){ */
    /*             ans[idx] = num++; */
    /*         } */
    /*         dfs(next, cur); */
    /*     } */
    /* }; */
    /* dfs(0, -1); */
    dfs();
    for (int a : ans){
        cout << a << '\n';
    }
}
