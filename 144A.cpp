using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a = 0, b = 0;
    cin >> n;
    for (int i = 0, mx = 0, mn = 101; i < n; ++i){
        int cur;
        cin >> cur;
        if (cur > mx){
            mx = cur;
            a = i;
        }
        if (cur <= mn){
            mn = cur;
            b = i;
        }
    }
    cout << a+n-1-b-(a>b);
}
