using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Y, W;
    cin >> Y >> W;
    int g = 7-max(Y,W);
    int f = gcd(g, 6);
    cout << g/f << '/' << 6/f;
}
