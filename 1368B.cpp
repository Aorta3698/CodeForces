using namespace std;
#include <bits/stdc++.h>

void solve(){
    long long k;
    cin >> k;
    long long tot = 1;
    int sz = 1;
    string s = "codeforces";
    while(tot < k){
        tot /= pow(sz, ssize(s));
        tot *= pow(++sz, ssize(s));
    }
    int d = 0;
    while(tot >= k){
        d++;
        tot /= sz;
        tot *= (sz-1);
    }
    for (char ch : s){
        cout << string(sz-(--d>0), ch);
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
}
