using namespace std;
#include <bits/stdc++.h>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto& s : A){
        cin >> s;
    }
    array<unordered_set<int>, 26> adj;
    array<int, 26> indg{};
    bool bad = 0;
    for (int i = 1; i < n; ++i){
        int a = int(A[i-1].size()), b = int(A[i].size());
        bad |= A[i-1].starts_with(A[i]) && a > b;
        for (int j = 0; j < min(a, b); ++j){
            if (A[i][j] != A[i-1][j]){
                indg[A[i][j] - 'a'] += adj[A[i - 1][j] - 'a'].insert(A[i][j] - 'a').second;
                break;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < 26; ++i) if (indg[i] == 0){
        q.push(i);
    }
    string ans;
    while(q.size()){
        int cur = q.front();
        ans += char(cur + 'a');
        q.pop();
        for (int next : adj[cur]) if (--indg[next] == 0){
            q.push(next);
        }
    }
    bad |= int(ans.size() < 26);
    cout << (bad? "Impossible" : ans);
}
