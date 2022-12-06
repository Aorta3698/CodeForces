using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> m(n), s(n);
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        m[i] = a;
        s[i] = b;
    }
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    ranges::sort(idx, [&](auto i, auto j){return m[i]<m[j];});
    long long ans = 0, sum = 0;
    for (int i = 0, j = 0; i < n; ++i){
        sum += s[idx[i]];
        while(m[idx[i]]-m[idx[j]]>=d){
            sum -= s[idx[j++]];
        }
        ans = max(sum, ans);
    }
    cout << ans << '\n';
}
