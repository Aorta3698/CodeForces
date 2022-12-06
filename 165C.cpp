using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string s;
    cin >> k >> s;
    int n = ssize(s);
    vector<int> R(n), L(n);
    long long ans = 0;
    if (k == 0){
        int cnt = 0;
        for (char ch : s){
            if (ch == '1'){
                cnt = 0;
            }else{
                ans += ++cnt;
            }
        }
        cout << ans;
        return 0;
    }
    for (int i = 0; i < n; ++i){
        L[i] = s[i] == '1'? i : (i == 0? -1 : L[i-1]);
    }
    for (int i = n-1; ~i; --i){
        R[i] = s[i] == '1'? i : (i == n-1? n : R[i+1]);
    }
    for (int i = 0, j = 0; i < n; ++i){
        k -= s[i] - '0';
        if (k == 0){
            int l = max(1, R[j] - L[j]);
            int r = (i == n-1? n : R[i+1]) - i;
            ans += 1LL * l * r;
        }
        while(k == 0){
            k += s[j++] - '0';
        }
    }
    cout << ans;
}
