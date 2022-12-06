using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> team(n);
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        team[i].push_back(a);
        team[i].push_back(b);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            ans += team[i][0] == team[j][1];
        }
    }
    cout << ans << '\n';
}
