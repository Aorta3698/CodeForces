using namespace std;
#include <bits/stdc++.h>

void solve(){
    array<int, 4> a;
    for (int& i : a){
        cin >> i;
    }
    auto b = a;
    int maxi = *ranges::max_element(a);
    ranges::nth_element(b, begin(b)+2);
    for (int i = 1; i < 4; i+=2){
        if (a[i]+a[i-1]==maxi+b[2]){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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
