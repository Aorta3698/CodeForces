using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, ans = 0;
    cin >> n;
    vector<int> A(n);
    for (int& x : A){
        cin >> x;
    }
    queue<int> q, nq;
    q.push(A[0]);
    nq.push(A[1]);
    for (int i = 2, prev = A[1]; i < n; prev = A[i++]){
        int v = A[i];
        if (v < prev){
            q.pop();
            if (q.empty()){
                swap(q, nq);
                ++ans;
            }
        }
        nq.push(v);
    }
    cout << ans+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
