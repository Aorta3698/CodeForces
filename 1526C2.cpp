using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> potion(n);
    for (int& x : potion){
        cin >> x;
    }
    priority_queue<int> maxheap;
    int ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i){
        sum += potion[i];
        ans++;
        if (potion[i] < 0){
            maxheap.push(-potion[i]);
        }
        while(sum < 0){
            sum += maxheap.top();
            maxheap.pop();
            ans--;
        }
    }
    cout << ans;
}
