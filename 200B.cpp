using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int tot = 100*n, got = 0;
    while(n--){
        int cur;
        cin >> cur;
        got += cur;
    }
    cout << 1.*got/tot*100;
}
