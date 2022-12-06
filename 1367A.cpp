using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans;
        for (int i = 0; i < ssize(s)/2; ++i){
            ans += s[2*i];
        }
        ans += s[ssize(s)-1];
        cout << ans << '\n';
    }
}
