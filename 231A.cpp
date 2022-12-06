using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int ans{0};
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int s{a+b+c};
        ans += s >=2;
    }
    cout << ans;
}
