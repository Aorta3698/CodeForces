using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int count[8001]{};
    for (int& x : v){
        cin >> x;
        count[x]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int sum = 0;
        for (int j = i; j >= 0; --j){
            sum += v[j];
            if (sum > 8000){
                break;
            }
            if (j<i){
                ans += count[sum];
                count[sum] = 0;
            }
        }
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
