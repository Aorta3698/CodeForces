using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (!(i&1) || i%4==1&&j==m-1 || i%4==3&&j==0){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << '\n';
    }
}
