using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i){
        int b;
        cin >> b;
        a[b]=i;
    }
    for (int i = 1; i <= n; ++i){
        cout << a[i] << ' ';
    }
}
