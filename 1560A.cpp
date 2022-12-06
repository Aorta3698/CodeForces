using namespace std;
#include <bits/stdc++.h>

void solve(){
    int k;
    cin >> k;
    for (int i = 1; ;++i){
        if (i%3 && i%10!=3 && --k == 0){
            cout << i << '\n';
            return;
        }
    }
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
