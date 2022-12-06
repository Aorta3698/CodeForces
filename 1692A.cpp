using namespace std;
#include <bits/stdc++.h>

void solve(){
    array<int, 4> a;
    for (int& i : a){
        cin >> i;
    }
    int y = a[0];
    ranges::sort(a);
    cout << find(rbegin(a), rend(a), y) - rbegin(a) << '\n';
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
