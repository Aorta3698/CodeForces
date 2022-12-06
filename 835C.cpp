using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q,c;
    cin >>n>>q>>c;
    int dp[11][100][100];
    memset(dp, 0, sizeof(dp));
    while(n--){
        int x, y, s;
        cin >> x >> y >> s;
        --x, --y; // do stars all have unique coordinates? NOOOOOOOOO!!!!! What a bug....
        for (int i = 0 ; i <= c; ++i){
            dp[i][x][y] += (s+i) % (c+1);
        }
    }
    for (int k = 0; k <= c; ++k){
        for (int i = 0; i < 100; ++i){
            for (int j = 0; j < 100; ++j){
                dp[k][i][j] += (i? dp[k][i-1][j] : 0) + (j? dp[k][i][j-1] : 0) - (i&&j? dp[k][i-1][j-1] : 0);
            }
        }
    }
    for (int i = 0; i < q; ++i){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        t %= (c+1);
        cout << dp[t][x2][y2] - (x1? dp[t][x1-1][y2] : 0) - (y1? dp[t][x2][y1-1] : 0) + (x1&&y1? dp[t][x1-1][y1-1] : 0) << '\n';
    }
}
