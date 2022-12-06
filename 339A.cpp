using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r[102];
    int i{0};
    while(cin>>r[i++]);
    sort(r, r+i-1);
    cout << r[0];
    for (int j{1}; j < i-1; ++j){
        cout << "+" << r[j];
    }
}
