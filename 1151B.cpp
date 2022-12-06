using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r = -1, tot = 0;
    cin >> m >> n;
    vector<vector<int>> A(m);
    vector<int> ans(m);
    for (int k = 0; k < m; ++k){
        bool ok = 0;
        for (int i = 0, e; i < n; ++i){
            cin >> e;
            A[k].push_back(e);
            ok |= i && e != A[k][i-1];
        }
        if (ok && r < 0){
            r = k;
        }else{
            tot ^= A[k][0];
        }
    }
    if (r >= 0){
        for (int i = 0; i < n; ++i){
            if (tot ^ A[r][i]){
                ans[r] = i;
                tot = 1;
                break;
            }
        }
    }
    if (tot == 0){
        cout << "NIE";
    }else{
        cout << "TAK\n";
        for (int n : ans){
            cout << n+1 << ' ';
        }
    }
}
