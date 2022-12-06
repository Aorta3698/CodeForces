using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, maxi = 0, mini = INT_MAX;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        maxi = max(maxi, a);
        mini = min(mini, a);
    }
    cout << maxi - mini << '\n';
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
