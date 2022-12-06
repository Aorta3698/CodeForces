using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> v(n+1);
    for (int i = 2; i*i <= n; ++i){
        for (int j = i*i; j <= n && !v[i]; j += i){
            v[j]=1;
        }
    }
    for (int i = 2; ;i++){
        if (v[i] && v[n-i]){
            cout << i << ' ' << (n-i);
            return 0;
        }
    }
}
