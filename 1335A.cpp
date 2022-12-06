using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a;
    while(a--){
        cin >> b;
        cout << (b/2 - !(b%2)) << '\n';
    }
}
