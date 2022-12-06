using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int t;
    cin >> t >> s;
    int a{count(begin(s), end(s), 'A')};
    int b{count(begin(s), end(s), 'D')};
    if (a > b){
        cout << "Anton";
    }else if (a < b){
        cout << "Danik";
    }else{
        cout << "Friendship";
    }
}
