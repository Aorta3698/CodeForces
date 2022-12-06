using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> w(n);
    for (int& i : w){
        cin >> i;
    }
    int sum = reduce(begin(w), end(w));
    unordered_set<int> S;
    if ((sum&1)==0){
        S.insert(0);
        for (auto x : w){
            unordered_set<int> nS(S);
            for (int y : S){
                nS.insert(y+x);
            }
            S = nS;
        }
    }
    cout << (S.contains(sum/2)? "YES" : "NO") << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
