using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, cur = -1;
    cin >> n;
    vector<pair<int,int>> A(n);
    for (auto& [a, b] : A){
        cin >> a >> b;
    }
    ranges::sort(A, [](auto&a, auto&b){return a.second < b.second;});
    for (auto& [a, b] : A){
        if (a > cur){
            cur = b;
            ans++;
        }
    }
    cout << ans;
}
