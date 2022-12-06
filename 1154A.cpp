using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v(4);
    for (int& n : v){
        cin >> n;
    }
    ranges::sort(v);
    for (int i = 0; i < 3; ++i){
        cout << v[3] - v[i] << ' ';
    }
}
