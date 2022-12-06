using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[]{"hate", "love"};
    for (int i = 0; i < n; ++i){
        cout << "I " << s[i&1];
        if (i <n-1){
            cout << " that ";
        }
    }
    cout << " it";
}
