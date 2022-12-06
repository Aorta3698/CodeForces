using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int got = 240, a, b;
    cin >> a >> b;
    got -= b;
    for (int i = 1; ; ++i){
        got -= i*5;
        if (i == a+1 || got < 0){
            cout << i-1;
            return 0;
        }
    }
}
