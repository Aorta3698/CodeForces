using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    a += b;
    ranges::sort(a);
    ranges::sort(c);
    cout << (a == c? "YES" : "NO");
    /* int C[256]{}; */
    /* string s; */
    /* for (int i = 0; i < 3; ++i){ */
    /*     int inc = i < 2? 1 : -1; */
    /*     cin >> s; */
    /*     for (auto ch : s){ */
    /*         C[ch] += inc; */
    /*     } */
    /* } */
    /* for (auto ch : C){ */
    /*     if (ch != 0){ */
    /*         cout << "NO"; */
    /*         return 0; */
    /*     } */
    /* } */
    /* cout << "YES"; */
}
