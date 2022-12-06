using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cost(n);
    vector<string> A(n), B(n);
    for (int & x : cost){
        cin >> x;
    }
    for (int i = 0; i < n; ++i){
        string s, t;
        cin >> s;
        A[i] = s;
        B[i] = string(rbegin(s), rend(s));
    }
    long long a = 0, b = cost[0], INF = 1e18;
    for (int i = 1; i < n; ++i){
        long long aa = INF, bb = aa;
        if (A[i] >= A[i-1]){
            aa = a;
        }
        if (A[i] >= B[i-1]){
            aa = min(aa, b);
        }
        if (B[i] >= A[i-1]){
            bb = a + cost[i];
        }
        if (B[i] >= B[i-1]){
            bb = min(bb, b+cost[i]);
        }
        if (aa >= INF && bb >= INF){
            cout << -1;
            return 0;
        }
        a = aa;
        b = bb;
    }
    cout << min(a, b);
}
