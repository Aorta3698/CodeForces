using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans{0};
    while(n--){
        string s;
        cin >> s;
        ans += s.find("+") != -1? 1 : -1;
    }
    cout << ans;
}
