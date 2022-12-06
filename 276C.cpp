using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> line(n+1), v(n);
    for (int& x : v){
        cin >> x;
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        line[a]++;
        line[b+1]--;
    }
    for (int i = 1; i < n; ++i){
        line[i] += line[i-1];
    }
    line.pop_back();
    ranges::sort(line);
    ranges::sort(v);
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        ans += 1LL*line[i]*v[i];
    }
    cout << ans;
}
