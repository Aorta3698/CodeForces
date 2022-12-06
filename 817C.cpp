using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, s, ans = 0, i = 0;
    cin >> n >> s;
    for (i = s; i <= min(n, s+170); ++i){
        long long c = i, cnt = 0;
        while(c){
            cnt += c%10;
            c/=10;
        }
        ans += i-cnt >= s;
    }
    cout << max(0LL, ans + n + 1 - i);
}
