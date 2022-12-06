using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    bitset<100001> sieve;
    for (int i : {a, b, c, d}){
        for (int j = i; j <= n; j += i){
            sieve[j]=1;
        }
    }
    cout << sieve.count();
}
