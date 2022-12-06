using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans{0}, m{0}, s{0};
    while(n--){
        cin >> s;
        if (--k == 0){
            m = s;
        }
        ans += s >= m && s > 0;
    }
    cout << ans;
}
