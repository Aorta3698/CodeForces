using namespace std;
#include <bits/stdc++.h>

void solve(){
    string s;
    cin >> s;
    if (int z = ssize(s); z&1 || s.substr(0, z/2)!=s.substr(z/2)){
        cout << "NO";
    }else{
        cout << "Yes";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
