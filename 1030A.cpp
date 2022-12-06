using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int now;
        cin >> now;
        if (now){
            cout << "hard";
            return 0;
        }
    }
    cout << "easy";
}
