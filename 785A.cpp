using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    string s;
    cin.ignore(1e9, '\n');
    int cnt[128];
    cnt['T'] = 4;
    cnt['C'] = 6;
    cnt['O'] = 8;
    cnt['D'] = 12;
    cnt['I'] = 20;
    while(cin >> s){
        ans += cnt[s[0]];
    }
    cout << ans;
}

