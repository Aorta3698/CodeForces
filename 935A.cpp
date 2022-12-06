using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n/2; ++i){
        ans += (n-i)%i==0;
    }
    cout << ans;
}
