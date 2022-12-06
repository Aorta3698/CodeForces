using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = n;
    bool ok=1;
    while(ok){
        string s = to_string(++ans);
        ranges::sort(s);
        auto a {ranges::unique(s)};
        /* auto [a, b]{ranges::unique(s)}; */
        ok &= begin(a)-begin(s) < 4;
    }
    cout << ans;
}
