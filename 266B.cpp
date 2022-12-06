using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    string s;
    cin >> n >> t >> s;
    while(t--){
        s = regex_replace(s, regex{"BG"}, "GB");
    }
    cout << s << "\n";
}
