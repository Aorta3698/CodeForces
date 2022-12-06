using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = -1, mi = -1, c, ans = 0;
    cin >> n;
    while(n--){
        cin >> c;
        if (mx == -1){
            mx = mi = c;
        }else if (mx < c){
            mx = c;
            ++ans;
        }else if (mi > c){
            mi = c;
            ++ans;
        }
    }
    cout << ans;
}
