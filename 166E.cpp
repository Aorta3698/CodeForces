using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M = 1e9+7, n;
    cin >> n;
    long long a = 1, b = 0;
    while(--n){
        b = 2*b + 3*a;
        a = (b - 3*a)/2;
        b %= M;
        a %= M;
        a += M;
        a %= M;
    }
    cout << b;
}
