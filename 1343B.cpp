using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n%4){
            cout << "NO" << '\n';
        }else{
            cout << "YES" << '\n';
            for (int i = 1; i <= n/2; i++){
                cout << 2*i << ' ';
            }
            for (int i = 1; i < n/2; i++){
                cout << (2*i-1) << ' ';
            }
            cout << (n+n/2-1) << '\n';
        }
    }
}
