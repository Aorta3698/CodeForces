using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> d;
    int n, a;
    cin >> n;
    while(cin >> a){
        d.push_back(a);
    }
    int c[2]{};
    for (int i = 0; i < n; ++i){
        c[i&1]+=max(d[0],d.back());
        if (d[0]>d.back()){
            d.pop_front();
        }else{
            d.pop_back();
        }
    }
    cout << c[0] << ' ' << c[1];
}
