using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    bool color=0;
    for (int i = 0; i < m*n; ++i){
        char s;
        cin >> s;
        color |= s=='C'|s=='M'|s=='Y';
    }
    if (color){
        cout << "#Color";
    }else{
        cout << "#Black&White";
    }
}
