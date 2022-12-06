using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int pre = 1;
    for (int i = 0; ;++i){
        n -= pre;
        if (n < 0){
            cout << i;
            return 0;
        }
        pre += i+2;
    }
}
