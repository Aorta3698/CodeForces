using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0, sz = ssize(s); i < sz; ++i){
        for (int j = i; j < sz; ++j){
            for (int k = j; k < sz; ++k){
                int a = s[i] - '0';
                int b = s[j] - '0';
                int c = s[k] - '0';
                int res = -1;
                if (j > i && k > j && a && b && (100*a+10*b+c)%8 == 0){
                    res = 100*a+10*b+c;
                }
                if (j > i && a && (10*a+b)%8 == 0){
                    res = 10*a+b;
                }
                if (a%8==0){
                    res = a;
                }
                if (res >= 0){
                    cout << "YES" << '\n' << res;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}
