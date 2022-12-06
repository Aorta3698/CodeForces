using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin >> n >> s;
    int ans{0};
    for (int cnt{0}, i{0}; i < n; ++i){
        ++cnt;
        if (i == n-1 || s[i] != s[i+1]){
            ans += cnt-1;
            cnt = 0;
        }
    }
    cout << ans;
}
