using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 1, s=a; ;++i){
        if (s % 10 == 0 || s % 10 == b){
            cout << i;
            return 0;
        }
        s += a;
    }
}
