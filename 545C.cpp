using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), h(n);
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        x[i] = a;
        h[i] = b;
    }
    int ans = 0, prev = INT_MIN;
    for (int i = 0; i < n; ++i){
        if (x[i]-h[i]>prev){
            ++ans;
            prev=x[i];
        }else if (i==n-1||i<n-1&&x[i]+h[i]<x[i+1]){
            ++ans;
            prev=x[i]+h[i];
        }else{
            prev=x[i];
        }
    }
    cout << ans;
}
