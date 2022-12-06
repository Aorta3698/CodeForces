using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    array<int, 26> count{};
    for (char& ch : s){
        count[ch-'a']++;
    }
    int ans = 0;
    for (int i{0}; i < 26; ++i){
        ans += count[i]>0;
    }
    if (ans&1){
        cout << "IGNORE HIM!";
    }else{
        cout << "CHAT WITH HER!";
    }
}
