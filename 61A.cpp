using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < ssize(a); ++i){
        cout << (a[i]^b[i]);
    }
}
