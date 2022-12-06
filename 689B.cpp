using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d = 0;
    cin >> n;
    vector<int> cut(n), ans(n, 1e9);
    for (int i = 1; i <= n; ++i){
        cin >> cut[i - 1];
        --cut[i - 1];
    }
    queue<int> q;
    q.push(0);
    ans[0] = 0;
    while(q.size()){
        ++d;
        for (int sz = int(q.size()); sz; --sz){
            int cur = q.front();
            q.pop();
            for (int next : {cur - 1, cur + 1, cut[cur]}){
                if (next >= 0 && next < n && ans[next] > n){
                    ans[next] = d;
                    q.push(next);
                }
            }
        }
    }
    for (int x : ans){
        cout << x << ' ';
    }
}
