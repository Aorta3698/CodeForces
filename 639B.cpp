using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, h;
    cin >> n >> d >> h;
    if (d == 1 && n > 2 || d - h > h){
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= h; ++i){
        cout << i << ' ' << i + 1 << '\n';
    }
    for (int i = h+1; i <= d; ++i){
        cout << (i == h+1? 1 : i) << ' ' << i + 1 << '\n';
    }
    for (int i = d+1; i < n; ++i){
        cout << h << ' ' << i + 1 << '\n';
    }
}
