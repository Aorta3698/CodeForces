using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    cin >> n >> a;
    unordered_set<int> s;
    while(a--){
        int b;
        cin >> b;
        s.insert(b);
    }
    cin >> a;
    while(a--){
        int b;
        cin >> b;
        s.insert(b);
    }
    cout << (ssize(s) == n? "I become the guy." : "Oh, my keyboard!");
}
