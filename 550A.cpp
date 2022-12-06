using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (auto p : vector<vector<string>>{{"AB", "BA"}, {"BA", "AB"}}){
        if (int d = s.find(p[0]); d != -1 && s.find(p[1], d+2) != -1){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
