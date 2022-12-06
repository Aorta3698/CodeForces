using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& x : A){
        cin >> x;
    }
    long long ans = INT_MIN, sum = 0, lo = 0, hi = INT_MIN;
    for (int i = 0, s = 1; i < n-1; ++i, s = -s){
        sum += abs(A[i] - A[i+1]) * s;
        ans = max({ans, sum - lo, -(sum - hi)});
        lo = i&1? min(lo, sum) : lo;
        hi = i&1? hi : max(hi, sum);
    }
    cout << ans;
}
