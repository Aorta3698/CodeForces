using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << k/2 << '\n';
    for (int i = 0; i < k/2-(k&1); ++i){
        cout << 2 << ' ';
    }
    if (k&1){
        cout << 3;
    }
}
