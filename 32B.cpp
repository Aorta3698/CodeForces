using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, a;
    cin >> s;
    for(int i = 0; i != ssize(s);){
        if (s.find(".", i) == i){
            a += '0';
            ++i;
        }else if (s.find("-.", i) == i){
            a += '1';
            i += 2;
        }else{
            a += '2';
            i += 2;
        }
    }
    cout << a;
}
