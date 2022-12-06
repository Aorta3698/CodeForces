using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans {0};
    cin >> n;
    for(int cur{0}; n--;){
        int a, b;
        cin >> a >> b;
        cur += b-a;
        ans = max(cur, ans);
    }
    cout << ans << "\n";
}
