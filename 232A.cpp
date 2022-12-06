using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    array<array<bool, 100>, 100> all{};
    int ans;
    for (ans = 0; k; ++ans){
        for (int j = 0; j < ans; ++j){
            if (k >= j){
                k -= j;
                all[j][ans] = all[ans][j] = 1;
            }else{
                break;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i){
        for (int j = 0; j < ans; ++j){
            cout << all[i][j];
        }
        cout << '\n';
    }
}
