using namespace std;
#include <bits/stdc++.h>

void solve(){
    int w, h, n;
    cin >> w >> h >> n;
    cout << ((h&-h)*(w&-w)>=n? "YES" : "NO") << '\n';
    /* int c=1; */
    /* while((w&1)==0){ */
    /*     w/=2; */
    /*     ans+=c; */
    /*     c<<=1; */
    /* } */
    /* c=ans; */
    /* while((h&1)==0){ */
    /*     h/=2; */
    /*     ans+=c; */
    /*     c<<=1; */
    /* } */
    /* cout << (ans >= n? "YES" : "NO") << '\n'; */
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
