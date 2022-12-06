using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        ans += (a>b?1:a==b?0:-1);
    }
    cout << (ans==0?"Friendship is magic!^^":ans>0?"Mishka":"Chris");
}
