using namespace std;
#include <bits/stdc++.h>

void solve(){
    queue<int> q[2];
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    vector<int> idx;
    for (char ch : s){
        if (int d = ch - '0'; !q[d^1].empty()){
            q[d].push(q[d^1].front());
            q[d^1].pop();
        }else{
            q[d].push(++cur);
        }
        idx.push_back(q[ch-'0'].back());
    }
    cout << cur << '\n';
    for (int o : idx){
        cout << o << ' ';
    }
    cout << '\n';
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
