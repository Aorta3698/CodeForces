using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int mi = min(a, b);
    a -= mi;
    b -= mi;
    cout << mi << ' ' << max(a, b)/2;
}
