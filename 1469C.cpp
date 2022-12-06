using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, k, h, lo = -1, hi;
    cin >> n >> k;
    while(n--){
        cin >> h;
        if (lo == -1){
            lo = h, hi = k + h;
        }else{
            if (lo + (n? 1 - k : 0) > h + k - 1 || hi - 1 < h){
                cout << "NO";
                cin.ignore(INT_MAX, '\n');
                return;
            }
            lo = max(h, lo + 1 - k);
            hi = min(h + k - 1 + k, hi - 1 + k);
        }
    }
    cout << "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}
