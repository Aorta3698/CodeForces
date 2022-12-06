using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n, w;
    cin >> k >> n >> w;
    int need {(1+w)*w/2*k};
    cout << max(0, need - n);
}
