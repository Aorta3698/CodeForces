using namespace std;
#include <bits/stdc++.h>

void solve(){
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> A(n);
    for (int& y : A){
        cin >> y;
    }
    for (int i = 0; i < n-1; ++i){
        int j = i;
        if (A[j] <= A[j+1]){
            continue;
        }
        while(j > 0 && A[j-1] > x){
            --j;
        }
        while(j <= i){
            if (x != A[j]){
                swap(x, A[j]);
                ++ans;
            }
            if (A[j] > A[j+1]){
                cout << -1;
                return;
            }
            j++;
        }
    }
    cout << ans;
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
