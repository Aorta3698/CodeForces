using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int & x : A){
        cin >> x;
    }
    for (int & x : B){
        cin >> x;
    }
    int ans = (1<<10)-1;
    for (int i = 9; ~i; --i){
        ans ^= 1 << i;
        for (int n : A) if (n & 1 << i){
            bool avoid = 0;
            for (int m : B){
                avoid |= !(m & 1 << i) && ((n & m) | ans) == ans;
            }
            if (!avoid){
                ans |= 1 << i;
                break;
            }
        }
    }
    cout << ans;
}
