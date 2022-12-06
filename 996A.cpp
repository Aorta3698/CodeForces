using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int b : {100, 20, 10, 5, 1}){
        ans += n/b;
        n %= b;
    }
    cout << ans;
}
