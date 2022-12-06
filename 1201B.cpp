using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    long long sum = reduce(begin(v), end(v), 0LL);
    int mx = *ranges::max_element(v);
    bool ok = sum%2==0 && mx <= sum-mx;
    cout << (ok? "YES" : "NO") << '\n';
}
