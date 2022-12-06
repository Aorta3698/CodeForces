using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(3);
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        v[--a].push_back(i+1);
    }
    int ans = min({ssize(v[0]), ssize(v[1]), ssize(v[2])});
    cout << ans << '\n';
    while(ans--){
        for (int i = 0; i < 3; ++i){
            cout << v[i].back() << ' ';
            v[i].pop_back();
        }
        cout << '\n';
    }
}
