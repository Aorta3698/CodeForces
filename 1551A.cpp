using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    if (int res = n-n/3*3; res==0){
        cout << n/3 << ' ' << n/3;
    }else if (res == 1){
        cout << n/3+1 << ' ' << n/3;
    }else{
        cout << n/3 << ' ' << n/3+1;
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
