using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    auto L = [](char ch){return islower(ch);};
    auto U = [](char ch){return isupper(ch);};
    int a = (int)count_if(begin(s), end(s), L);
    int b = (int)count_if(begin(s), end(s), U);
    if (a >= b){
        transform(begin(s), end(s), begin(s), ::tolower);
    }else{
        transform(begin(s), end(s), begin(s), ::toupper);
    }
    cout << s << "\n";
}
