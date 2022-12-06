using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(--t >= 0){
        string s;
        cin >> s;
        if (s.size() <= 10){
            cout << s;
        }else{
            cout << s.substr(0, 1) + to_string(s.size() - 2) + s.substr(s.size()-1);
        }
        cout << "\n";
    }
};
