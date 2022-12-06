using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M = (int)1e9+7;
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> A(n+1,1), B(n+1,1);
    for (int i = 1; i < m; ++i){
        vector<int> a(n+1), b(n+1);
        for (int j = 1, pre = 0; j <= n; ++j){
            pre += A[j];
            pre %= M;
            a[j] = pre;
        }
        for (int j = n, pre = 0; j; --j){
            pre += B[j];
            pre %= M;
            b[j] = pre;
        }
        A=a;
        B=b;
    }
    for (int i = n, pre = 0; i; --i){
        pre += B[i];
        pre %= M;
        ans += 1LL * A[i] * pre % M;
        ans %= M;
    }
    cout << ans;
}
