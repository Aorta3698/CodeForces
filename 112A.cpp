using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    transform(begin(a), end(a), begin(a), ::tolower);
    transform(begin(b), end(b), begin(b), ::tolower);
    cout << a.compare(b);
}
