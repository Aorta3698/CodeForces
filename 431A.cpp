using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v{0};
    for (int i = 0; i < 4; ++i){
        int n;
        cin >> n;
        v.push_back(n);
    }
    string s;
    cin >> s;
    int ans{};
    for (char ch : s){
        ans += v[ch-'0'];
    }
    cout << ans;
}
