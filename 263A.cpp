using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i{0};;++i){
        int n;
        cin >> n;
        if (n){
            cout << abs(i/5-2) + abs(i%5-2);
            break;
        }
    }
}
