using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s = 0, ans = 0, a;
    cin >> n;
    while(n--){
        cin >> a;
        s += a;
        ans += s < 0;
        s = max(0, s);
    }
    cout << ans;
}
