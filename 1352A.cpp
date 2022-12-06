using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int s;
        cin >> s;
        int a = 1;
        cout << ranges::count_if(to_string(s), [](auto ch){return ch != '0';}) << '\n';
        while(s > 0){
            if (s%10){
                cout << s%10*a << ' ';
            }
            s /= 10;
            a *= 10;
        }
        cout << '\n';
    }
}
