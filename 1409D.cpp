using namespace std;
#include <bits/stdc++.h>

void solve(){
    long long n, ans = 0;
    int k;
    cin >> n >> k;
    string s = to_string(n);
    int sum = 0, tot = reduce(begin(s), end(s), 0) - '0'*ssize(s);
    for (int i = 0; i < ssize(s); ++i){
        tot -= s[i] - '0';
        if (int m = sum + s[i] - '0'; m > k || m == k && (s[i] < '9' && tot)){
            long long hi = pow(10, ssize(s) - i);
            ans = hi - n % hi;
            break;
        }
        sum += s[i] - '0';
    }
    cout << ans << '\n';
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
