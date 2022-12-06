using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    while(cin >> t){
        s += t;
    }
    erase_if(s, [](auto c){return c < 'a' || c > 'z';});
    cout << set<char>{begin(s), end(s)}.size();
}
