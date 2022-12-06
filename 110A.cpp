using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    array<int, 10> cnt {};
    while(n>0L){
        cnt[n%10]++;
        n/=10;
    }
    int res = cnt[7] + cnt[4];
    cout << (res == 7 || res == 4? "YES" : "NO");
}
