using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, prev = -1;
    cin >> n;
    string all;
    while(n--){
        string s;
        cin >> s;
        ans += s[0] == prev;
        prev = s[1];
    }
    cout << ans+1;
}
