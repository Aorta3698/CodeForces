using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    erase_if(v, [&](auto e){return e+k > 5;});
    cout << ssize(v)/3;
}
