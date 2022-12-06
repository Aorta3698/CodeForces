using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    ranges::reverse(s);
    if (s == t){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
