using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        set<int> s;
        int a;
        cin >> a;
        while(a--){
            int b;
            cin >> b;
            s.insert(b);
        }
        if (*--end(s) - *begin(s) + 1 == ssize(s)){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
}
