using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> s;
    int n;
    while(cin >> n){
        s.insert(n);
    }
    cout << 4-ssize(s);
}
