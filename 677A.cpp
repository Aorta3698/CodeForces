using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, ans = 0;
    cin >> n >> h;
    while(n--){
        int cur;
        cin >> cur;
        ans += (cur > h) + 1;
    }
    cout << ans;
}
