using namespace std;
#include <bits/stdc++.h>
mt19937 mt((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

int random(int a, int b){
    return uniform_int_distribution<int>(a,b)(mt);
}

/* void solve(vector<vector<bool>> adj){ // C++20, otherwise won't compile. */
/*     int n = ssize(adj), odd = 0; */
/*     bool ok = 1; */
/*     for (auto a : adj){ */
/*         int deg = ranges::count(a, 1); */
/*         odd += deg&1; */
/*         ok &= !(deg==n-1&&deg&1); // if deg is odd, it can't be FULL */
/*     } */
/*     ok &= !(odd%2||odd>4); // can't have odd numbers of or more than 4 odd degs */
/*     cout << (ok? "TRUE" : "FALSE") << '\n'; */
/* } */

/* void solve(vector<int> A){ */
/*     const int N = (int)1e6+1; */
/*     int cnt[N]{}, got[N]{}; */
/*     for (int n : A){ */
/*         ++cnt[n]; */
/*     } */
/*     got[1] = ssize(A) - cnt[1]; */
/*     for (int i = 2; i < N; ++i){ */
/*         for (int j = 2*i; j < N; j += i){ */
/*             got[i] += cnt[j]; */
/*             got[j] -= cnt[i]; */
/*         } */
/*     } */
/*     for (int n : A){ */
/*         cout << got[n] << ' '; */
/*     } */
/*     cout << '\n'; */
/* } */

/* void solve(vector<int> A){ */
/*     if (ssize(set<int>(begin(A), end(A))) != ssize(A)){ */
/*         cout << "-1" << '\n'; */
/*         return; */
/*     } */
/*     vector<int> B{A}; */
/*     auto check = [&]{ */
/*         long long a = 0, b = 0; */
/*         bool mis = 0; */
/*         int res = 0; */
/*         for (int i = 0; i < ssize(A); ++i){ */
/*             if (mis && b > B[i-1] && (A[i]>A[i-1])^(A[i-1]>A[i-2])){ */
/*                 break; */
/*             } */
/*             if (!mis && A[i] != B[i]){ */
/*                 res += b > 0; */
/*                 mis = 1; */
/*                 a = b = 0; */
/*             } */
/*             a += A[i]; */
/*             b += B[i]; */
/*             if (a == b && mis){ */
/*                 a = b = mis = 0; */
/*                 ++res; */
/*             } */
/*         } */
/*         return mis? INT_MAX : res; */
/*     }; */
/*     ranges::sort(B); */
/*     int a = check(); */
/*     sort(rbegin(B), rend(B)); */
/*     int b = check(); */
/*     cout << (min(a, b) == INT_MAX? -1 : min(a, b)) << '\n'; */
/* } */

/* void solve(vector<string> A, string T){ */
/*     const int M = 1e9+7; */
/*     vector<int> dp(ssize(T)+1); */
/*     dp[0] = 1; */
/*     for (int i = 0; i < ssize(A[0]); ++i){ */
/*         array<int, 26> cnt{}; */
/*         for (int j = 0; j < ssize(A); ++j){ */
/*             ++cnt[A[j][i]-'a']; */
/*         } */
/*         for (int j = ssize(T); j >= 1; --j){ */
/*             dp[j] += 1LL * cnt[T[j-1]-'a'] * dp[j-1] % M; */
/*             dp[j] %= M; */
/*         } */
/*     } */
/*     cout << dp[ssize(T)] << '\n'; */
/* } */

/* void solve(string msg, int limit){ */
/*     int avail = 0, now = 0, target = ssize(msg); */
/*     auto sz = [](int n){return n < 10? 1 : n < 100? 2 : n < 1000? 3 : 4;}; */
/*     for (int space = limit-5; ; space-=2){ */
/*         int head = avail - now; */
/*         avail = head + (9 * now + 9) * space; */
/*         if (avail >= target){ */
/*             target -= head; */
/*             now += (target-1) / space + 1; */
/*             break; */
/*         } */
/*         if (space < 0){ */
/*             cout << "IMPOSSIBLE" << '\n'; */
/*             return; */
/*         } */
/*         now = 10 * now + 9; */
/*     } */
/*     vector<string> ans(now); */
/*     int e = limit - sz(now) - 3; */
/*     for (int i = 1, j = 0; i <= now; ++i){ */
/*         ans[i-1] = msg.substr(j, e-sz(i)) + "<" + to_string(i) + "/" + to_string(now) + ">"; */
/*         j += e - sz(i); */
/*         assert(ssize(ans[i-1]) <= limit); */
/*     } */
/*     for (string s : ans){ */
/*         cout << s << '\n'; */
/*     } */
/* } */

/* class UF { */
/*     public: */
/*     vector<int> parent; */
/*     vector<int> rank; */
/*     UF (int n) : parent(n), rank(n){ */
/*         iota(begin(parent), end(parent), 0); */
/*     } */
/*     inline int leader(int x){ */
/*         return x == parent[x]? x : (parent[x]=leader(parent[x])); */
/*     } */
/*     inline bool unite(int x, int y){ */
/*         x = leader(x); y = leader(y); */
/*         if (x == y){ */
/*             return false; */
/*         } */
/*         if (rank[y] > rank[x]){ */
/*             swap(x, y); */
/*         } */
/*         parent[y] = x; */
/*         if (rank[y] == rank[x]){ */
/*             ++rank[x]; */
/*         } */
/*         return true; */
/*     } */
/* }; */

/* void solve(vector<int> on, vector<int> dist){ */
/*     int n = ssize(on), OK = n, ans = 0; */
/*     UF uf(n+1); */
/*     vector<pair<int, pair<int, int>>> all; */
/*     for (int i = 1; i < n; ++i){ */
/*         all.push_back({dist[i]-dist[i-1], {i-1, i}}); */
/*         if (on[i] == 1){ */
/*             uf.unite(i, OK); */
/*         } */
/*     } */
/*     ranges::sort(all); */
/*     for (auto& [cost, p] : all){ */
/*         auto [x, y] = p; */
/*         if (uf.unite(x, y)){ */
/*             ans += cost; */
/*         } */
/*     } */
/*     cout << ans << '\n'; */
/* } */

/* int brute(vector<int> all){ */
/*     int n = ssize(all),ans = 0; */
/*     for (int i = 0; i < n; ++i){ */
/*         set<int> cur; */
/*         for (int j = i; j < n; ++j){ */
/*             cur.insert(all[j]); */
/*             int prev = *begin(cur); */
/*             for (int x : cur){ */
/*                 if (x - prev > 1){ */
/*                     ++ans; */
/*                 } */
/*                 prev = x; */
/*             } */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<int> A, int k){ */
/*     unordered_map<int, bool> mp; */
/*     int ans = 0; */
/*     for (int i = 0, j = 0; i < ssize(A); ++i){ */
/*         if (!(mp[A[i]] ^= 1)){ */
/*             --k; */
/*         } */
/*         while(k == 0){ */
/*             k += (mp[A[j++]] ^= 1); */
/*         } */
/*         ans += j; */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<int> all){ */
/*     int n = ssize(all), ans = 0; */
/*     ranges::for_each(all, [](int& x){return --x;}); */
/*     vector<int> has(n, -1); */
/*     for (int i = 0; i < n; ++i){ */
/*         int cnt = -1; */
/*         for (int j = i; j < n; ++j){ */
/*             bool L = all[j] && has[all[j]-1] == i; */
/*             bool R = all[j] < n-1 && has[all[j]+1] == i; */
/*             cnt -= (L+R-1); */
/*             ans += cnt; */
/*             has[all[j]] = i; */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* vector<int> solve(vector<int> A){ */
/*     vector<int> ans; */
/*     vector<queue<int>> all(ssize(A)+1); */
/*     for (int i = 0; i < ssize(A); ++i) if (A[i] < ssize(A)){ */
/*         all[A[i]].push(i); */
/*     } */
/*     for (int i = 0, j = -1; i < ssize(A); ++i){ */
/*         for (int mex = 0; ; ++mex){ */
/*             while(!all[mex].empty() && all[mex].front() <= j){ */
/*                 all[mex].pop(); */
/*             } */
/*             if (all[mex].empty()){ */
/*                 ans.push_back(mex); */
/*                 j = i; */
/*                 break; */
/*             }else{ */
/*                 i = max(i, all[mex].front()); */
/*             } */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<int> A, int B){ */
/*     int n = ssize(A), l = 0, r = n-1; */
/*     for (int i = 1; i < n && abs(A[i]-A[i-1]) <= B; ++i){ */
/*         ++l; */
/*     } */
/*     for (int i = n-2; ~i && abs(A[i]-A[i+1]) <= B; --i){ */
/*         --r; */
/*     } */
/*     vector<int> L(l+1), R(n-r); */
/*     iota(begin(L), end(L), 0); */
/*     iota(begin(R), end(R), r); */
/*     ranges::sort(L, [&](int a, int b){return A[a]<A[b];}); */
/*     ranges::sort(R, [&](int a, int b){return A[a]<A[b];}); */
/*     deque<int> dq; */
/*     int ans = R[0]; */
/*     for (int i = 0, j = 0; i <= l; ++i){ */
/*         while(j < ssize(R) && A[R[j]] - A[L[i]] <= B){ */
/*             while(!dq.empty() && R[j] < dq.back()){ */
/*                 dq.pop_back(); */
/*             } */
/*             dq.push_back(R[j++]); */
/*         } */
/*         while(!dq.empty() && A[L[i]] - A[dq.front()] > B){ */
/*             dq.pop_front(); */
/*         } */
/*         int END = dq.empty()? ssize(A) : dq.front(); */
/*         ans = min(ans, max(0, END - L[i] - 1)); */
/*     } */
/*     return ans; */
/* } */
/* class UF{ */
/* public: */
/*     vector<int> rank, parent; */
/*     int N; */
/*     UF (int n) : N{n}, rank(n), parent(n){ */
/*         iota(begin(parent), end(parent), 0); */
/*     } */

/*     int leader(int x){ */
/*         return parent[x] == x? x : (parent[x]=leader(parent[x])); */
/*     } */

/*     void unite(int x, int y){ */
/*         x = leader(x); */
/*         y = leader(y); */
/*         if (x == y){ */
/*             return; */
/*         } */
/*         if (rank[y] > rank[x]){ */
/*             swap(x, y); */
/*         } */
/*         if (rank[y] == rank[x]){ */
/*             ++rank[x]; */
/*         } */
/*         parent[y] = x; */
/*     } */

/*     vector<vector<int>> getGroups(){ */
/*         unordered_map<int,int> mp; */
/*         for (int i = 0; i < N; ++i){ */
/*             int sz = ssize(mp); */
/*             mp.try_emplace(leader(i), sz); */
/*         } */
/*         vector<vector<int>> ans(ssize(mp)); */
/*         for (int i = 0; i < N; ++i){ */
/*             ans[mp[leader(i)]].push_back(i); */
/*         } */
/*         return ans; */
/*     } */
/* }; */

/* int solve(int N, int C, vector<int> money, vector<int> candy, vector<pair<int,int>> friends){ */
/*     UF uf(N); */
/*     for (auto& [a, b] : friends){ */
/*         --a; --b; */
/*         uf.unite(a, b); */
/*     } */
/*     vector<vector<int>> groups = uf.getGroups(); */
/*     vector<int> dp(C+1); */
/*     for (auto& g : groups){ */
/*         vector<int> ndp {dp}; // don't pick any from this group */
/*         for (int person : g){ */
/*             for (int j = candy[person]; j <= C; ++j){ */
/*                 ndp[j] = max(ndp[j], dp[j-candy[person]]+money[person]); // pick from this group */
/*             } */
/*         } */
/*         swap(ndp, dp); */
/*     } */
/*     return dp[C]; */
/* } */

/* int solve(vector<int> from, vector<int> to, vector<int> val){ */
/*     int N = ssize(val), root = -1, ans = 0; */
/*     vector<vector<int>> mp(N); */
/*     vector<int> indg(N); */
/*     for (int i = 0; i < ssize(to); ++i){ // build the adj list */
/*         mp[--from[i]].push_back(--to[i]); */
/*         ++indg[to[i]]; */
/*     } */
/*     for (int i = 0; i < N; ++i) if (indg[i] == 0){ // find the root */
/*         root = i; */
/*         break; */
/*     } */
/*     function<int(int)> dfs = [&](int cur){ // pair them with post-order DFS */
/*         vector<int> res; */
/*         for (int next : mp[cur]) if (int got = dfs(next); ~got){ */
/*             res.push_back(got+1); */
/*         } */
/*         if (val[cur]&1){ */
/*             res.push_back(0); */
/*         } */
/*         if (ssize(res) >= 2){ */
/*             ans += res[0] + res[1]; */
/*             res[1] = -1; */
/*         } */
/*         return res.empty()? -1 : res.back(); */
/*     }; */
/*     dfs(root); // dfs from the root */
/*     return ans; */
/* } */

/* class UF { */
/* public: */
/*     vector<int> parent, sz; */
/*     UF (int n) : parent(n), sz(n, 1){ */
/*         iota(begin(parent), end(parent), 0); */
/*     } */

/*     inline int leader(int x){ */
/*         return x == parent[x]? x : (parent[x]=leader(parent[x])); */
/*     } */

/*     inline void unite(int x, int y){ */
/*         x = leader(x), y = leader(y); */
/*         if (sz[y] > sz[x]){ */
/*             swap(x, y); */
/*         } */
/*         sz[x] += sz[y]; */
/*         parent[y] = x; */
/*     } */

/*     inline int size(int x){ */
/*         return sz[leader(x)]; */
/*     } */
/* }; */

/* long long solve(int N, vector<vector<int>> edges){ */
/*     UF uf(N); */
/*     ranges::sort(edges, [](auto& a, auto& b){return a[2]<b[2];}); */
/*     long long ans = 0; */
/*     for (auto & e : edges){ */
/*         e[0]--, e[1]--; */
/*         int groupA = uf.size(e[0]); */
/*         int groupB = uf.size(e[1]); */
/*         ans += 1LL * groupA * groupB * e[2]; */
/*         uf.unite(e[0], e[1]); */
/*     } */
/*     return ans; */
/* } */


/* int solve(vector<vector<int>> A){ */
/*     auto cmp = [&](auto& a, auto& b){return A[a[0]][a[1]] > A[b[0]][b[1]];}; */
/*     priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq{cmp}; */
/*     int mx = 0, mi = 0, mul = 0, ans = 0, k = INT_MAX; */
/*     unordered_map<int,int> mp; */
/*     for (int i = 0; i < ssize(A); ++i){ */
/*         ranges::sort(A[i]); */
/*         int r =  (ssize(A[i])-1)/2; */
/*         for (int x : A[i]){ // store counts for each num */
/*             ++mp[x]; */
/*         } */
/*         mx = max(mx, A[i][r]); */
/*         pq.push({i, 0, r}); */
/*     } */
/*     for (auto& a : A) for (int x : a) { // base case for multipler */
/*         mul += x <= mx; */
/*     } */
/*     while(ssize(pq) == ssize(A)){ // for each lowest value */
/*         auto [row, l, r] = pq.top(); */
/*         if (mx < A[row][r]){ // if mx is increased, add to count as well */
/*             mul += mp[A[row][r]]; */
/*             mx = A[row][r]; */
/*         } */
/*         if (mi < A[row][l]){ // if mi is increased, remove count as well */
/*             mul -= mp[mi]; */
/*             mi = A[row][l]; */
/*         } */
/*         if (k == mx - mi){ // if k is the same, set ans to max of the two */
/*             ans = max(ans, k * mul); */
/*         } */
/*         if (k > mx - mi){ // if k is lower than before, set ans to that */
/*             k = mx - mi; */
/*             ans = k * mul; */
/*         } */
/*         pq.pop(); */
/*         if (r+1 < ssize(A[row])){ */
/*             pq.push({row, l+1, r+1}); */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<int> nutrition, vector<int> price, int k, int m){ */
/*     vector<vector<int>> dp(m+1, vector<int>(k+1)); */
/*     for (int a = 0; a < ssize(price); ++a){ */
/*         for (int i = min(k, a+1); ~i; --i){ */
/*             for (int j = m; j >= price[a]/2; --j){ */
/*                 if (j >= price[a] && a >= i){ */
/*                     dp[j][i] = max(dp[j][i], dp[j-price[a]][i] + nutrition[a]); */
/*                 } */
/*                 if (i){ */
/*                     dp[j][i] = max(dp[j][i], dp[j-price[a]/2][i-1] + nutrition[a]); */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     return dp[m][k]; */
/* } */

/* void solve(vector<pair<int, int>> pages){ */
/*     unordered_map<int,int> mp; */
/*     auto ADD = [](int a, int b, auto& mp){ */
/*         ++mp[a]; */
/*         if (a != b){ */
/*             ++mp[b]; */
/*         } */
/*     }; */
/*     for (auto& [a, b] : pages){ */
/*         ADD(a, b, mp); */
/*     } */
/*     for (auto& [key, cnt] : mp) if (2*cnt >= ssize(pages)){ */
/*         unordered_map<int,int> other; */
/*         for (auto& [a, b] : pages) if (a != key && b != key){ */
/*             ADD(a, b, other); */
/*         } */
/*         for (auto& [val, c] : other) if (c + cnt == ssize(pages)){ */
/*             cout << val << ' ' << key << '\n'; */
/*             return; */
/*         } */
/*     } */
/*     cout << "IMPOSSIBLE" << '\n'; */
/* } */

/* long long solve(vector<int> a) { */
/*     int n = ssize(a); */
/*     vector<int64_t> b(n), c(n); */
/*     for (int i = 1; i < n; ++i) { */
/*         if (i % 2) { */
/*             b[i] = abs(a[i] - a[i-1]); */
/*         } else { */
/*             b[i] = -abs(a[i] - a[i-1]); */
/*         } */
/*         c[i] = -b[i]; */
/*     } */
/*     int64_t ans = 0, s1 = 0, s2 = 0; */
/*     for (int i = 1; i < n; ++i) { */
/*         s1 = max(b[i], s1 + b[i]); */
/*         s2 = max(c[i], s2 + c[i]); */
/*         ans = max({ans, s1, s2}); */
/*     } */
/*     return ans; */
/* } */

/* long long mine(vector<int> A){ */
/*     auto n = ssize(A); */
/*     /1* array<long long, 2> lo{}, hi{INT_MIN, INT_MIN}; *1/ */
/*     long long ans = INT_MIN, sum = 0, lo = 0, hi = INT_MIN; */
/*     for (int i = 0, s = 1; i < n-1; ++i, s = -s){ */
/*         sum += abs(A[i] - A[i+1]) * s; */
/*         ans = max({ans, sum - lo, -(sum - hi)}); */
/*         lo = i&1? min(lo, sum) : lo; */
/*         hi = i&1? hi : max(hi, sum); */
/*         /1* ans = max({ans, sum - lo[1], -(sum - hi[0])}); *1/ */
/*         /1* if (i%2) { *1/ */
/*         /1*     ans = max({ans, sum - lo[i&1], -(sum - hi[i&1^1])}); *1/ */
/*         /1* }else{ *1/ */
/*         /1*     ans = max({ans, sum - lo[i&1^1], -(sum - hi[i&1])}); *1/ */
/*         /1* } *1/ */
/*         /1* lo[i&1] = min(lo[i&1], sum); *1/ */
/*         /1* hi[i&1] = max(hi[i&1], sum); *1/ */
/*     } */
/*     return ans; */
/* } */


/* void solve(){ */
/*     int n, k; */
/*     cin >> n >> k; */
/*     vector<int> L(n), R(n); */
/*     for (int i = 0; i < n; ++i){ // read in data */
/*         cin >> L[i] >> R[i]; */
/*     } */
/*     vector<int> all; // all numbers */
/*     for (int i = 0; i < ssize(L); ++i){ */
/*         all.push_back(L[i]); */
/*         all.push_back(R[i]); */
/*     } */
/*     ranges::sort(all); // sort */
/*     all.resize(unique(begin(all), end(all)) - begin(all)); // delete dup */
/*     unordered_map<int, int> mp; */
/*     for (int i = 0; i < ssize(all); ++i){ // assign a rank */
/*         mp[all[i]] = i; */
/*     } */
/*     vector<int> add(ssize(all)), lose(ssize(all)); */
/*     for (int i = 0; i < ssize(L); ++i){ */
/*         ++add[mp[L[i]]]; // put rank into it */
/*         ++lose[mp[R[i]]]; */
/*     } */
/*     const int N = 200002, M = (int) 1e9+7; */
/*     array<long long, N> fact{1, 1}, invfact{1, 1}, inv{0, 1}; */
/*     for (int i = 2; i < N; ++i){ // mod inverse stuff */
/*         inv[i] = M - M/i*inv[M%i] % M; */
/*         fact[i] = i * fact[i-1] % M; */
/*         invfact[i] = invfact[i-1] * inv[i] % M; */
/*     } */
/*     auto comb = [&](int a, int b){ // comb fun */
/*         return fact[a] * invfact[a-b] % M * invfact[b] % M; */
/*     }; */
/*     long long ans = 0; */
/*     for (int i = 0, sum = 0; i < ssize(all); ++i){ */
/*         sum += add[i]; */
/*         if (sum >= k && lose[i]){ // if sum is enough, and that something ends, we add to ans. */
/*             for (int j = max(1, k - sum + lose[i]); j <= min(lose[i], k); ++j){ */
/*                 ans += comb(lose[i], j) * comb(sum - lose[i], k - j) % M; */
/*                 ans %= M; */
/*             } */
/*         } */
/*         sum -= lose[i]; */
/*     } */
/*     cout << ans; // output ans */
/* } */


/* int solve(vector<int> A){ */
/*     priority_queue<int, vector<int>, greater<>> pending; */
/*     priority_queue<int, vector<int>, greater<>> matched; */
/*     vector<int> B; */
/*     ranges::copy_if(A, back_inserter(B), [](int o){return o > 0;}); */
/*     ranges::sort(B); */
/*     for (int n : B){ */
/*         if (pending.size()){ // has pending */
/*             if (pending.top() * 2 <= n){ // basic requirement */
/*                 pending.pop(); */
/*                 matched.push(n); */
/*             }else{ */
/*                 if (matched.size() && matched.top() * 2 <= n){ // try backup plan */
/*                     matched.push(n); */
/*                     matched.push(pending.top()); */
/*                     matched.pop(); */
/*                     pending.pop(); */
/*                 }else{ // nothing works, so add to pending */
/*                     pending.push(n); */
/*                 } */
/*             } */
/*         }else{ */
/*             pending.push(n); */
/*         } */
/*     } */
/*     int locked = (ssize(B) - ssize(pending)) / 2; */
/*     int nonPos = ssize(A) - ssize(B); */
/*     int pos = ssize(pending); */
/*     if (nonPos >= pos){ */
/*         /1* cout << (nonPos - pos + 1) / 2 + pos + locked << '\n'; *1/ */
/*         return (nonPos - pos + 1) / 2 + pos + locked; */
/*     }else{ */
/*         return pos + locked; */
/*     } */
/* } */

/* class UF { */
/*     public: */
/*         vector<int> rank, parent; */
/*         UF (int n) : rank(n), parent(n){ */
/*             iota(begin(parent), end(parent), 0); */
/*         } */
/*         inline int leader(int x){ */
/*             return x == parent[x]? x : (parent[x] = leader(parent[x])); */
/*         } */
/*         inline void unite(int x, int y){ */
/*             x = leader(x), y = leader(y); */
/*             if (x == y){ */
/*                 return; */
/*             } */
/*             if (rank[y] > rank[x]){ */
/*                 swap(x, y); */
/*             } */
/*             if (rank[y] == rank[x]){ */
/*                 ++rank[x]; */
/*             } */
/*             parent[y] = x; */
/*         } */
/* }; */

/* void solve(vector<int> A, vector<pair<int,int>> B, vector<array<int, 3>> C){ */
/*     vector<int> all = A, ans(ssize(C)); */
/*     unordered_map<int, vector<array<int, 3>>> Q; */
/*     for (int i = 0; i < ssize(C); ++i){ // re-arrange queries */
/*         auto& [u, v, w] = C[i]; */
/*         --u, --v; */
/*         all.push_back(w); */
/*         if (u == v){ */
/*             ans[i] = A[u] <= w; */
/*             continue; */
/*         } */
/*         Q[u].push_back({v, w, i}); */
/*         Q[v].push_back({u, w, i}); */
/*     } */

/*     vector<vector<int>> adj(ssize(A)); // build adj list */
/*     for (auto& [u, v] : B){ */
/*         --u, --v; */
/*         adj[u].push_back(v); */
/*         adj[v].push_back(u); */
/*     } */

/*     ranges::sort(all); // rank transformation */
/*     all.resize(unique(begin(all), end(all)) - begin(all)); */
/*     unordered_map<int,int> mp; */
/*     for (int i = 0; i < ssize(all); ++i){ */
/*         mp[all[i]] = i; */
/*     } */

/*     vector<int> bit(size(all)+1); // BIT section */
/*     auto add = [&](int idx, int inc){ */
/*         for (++idx; idx < ssize(bit); idx += idx & -idx){ */
/*             bit[idx] += inc; */
/*         } */
/*     }; */
/*     auto sum = [&](int idx){ */
/*         int res = 0; */
/*         for (++idx; idx; idx -= idx & -idx){ */
/*             res += bit[idx]; */
/*         } */
/*         return res; */
/*     }; */

/*     vector<int> ancestor(ssize(A)); // answer queries */
/*     vector<bool> seen(ssize(A)); */
/*     unordered_map<int, vector<pair<int,int>>> dup; */
/*     UF uf(ssize(A)); */
/*     function<void(int)> dfs = [&](int cur){ */
/*         seen[cur] = 1; */
/*         ancestor[cur] = cur; */
/*         add(mp[A[cur]], 1); */
/*         for (auto& [_, weight, idx] : Q[cur]){ */
/*             ans[idx] += sum(mp[weight]); */
/*         } */
/*         for (int next : adj[cur]) if (!seen[next]){ */
/*             dfs(next); */
/*             uf.unite(next, cur); */
/*             ancestor[uf.leader(cur)] = cur; */
/*         } */
/*         add(mp[A[cur]], -1); */
/*         for (auto& [weight, idx] : dup[cur]){ */
/*             ans[idx] -= (2*sum(mp[weight]) + (A[cur] <= weight)); */
/*         } */
/*         for (auto& [other, weight, idx] : Q[cur]) if (seen[other]){ */
/*             dup[ancestor[uf.leader(other)]].emplace_back(weight, idx); */
/*         } */
/*     }; */

/*     dfs(0); */
/*     for (int a : ans){ // print out answer */
/*         cout << a << ' '; */
/*     } */
/* } */

/* struct TreeNode{ */
/*     TreeNode* left=nullptr, *right=nullptr; */
/*     int node_number; */
/*     TreeNode(int id){ */
/*         node_number = id; */
/*     } */
/* }; */

/* vector<pair<int,int>> solve(TreeNode* root){ */
/*     vector<pair<int,int>> ans; */
/*     unordered_map<TreeNode*, int> mp; */
/*     function<int(TreeNode*)> dfs = [&](TreeNode* cur){ */
/*         return cur? (mp[cur] = 1 + max(dfs(cur->left), dfs(cur->right))) : 0; */
/*     }; */
/*     function<void(TreeNode*,int,int)> go = [&](TreeNode* cur, int depth, int mx){ */
/*         if (!cur){ */
/*             return; */
/*         } */
/*         if (++depth){ */
/*             ans.emplace_back(cur->node_number, mx); */
/*         } */
/*         go(cur->right, depth, max(mx, depth + mp[cur->left])); */
/*         go(cur->left, depth, max(mx, depth + mp[cur->right])); */
/*     }; */
/*     dfs(root); */
/*     go(root, -1, 0); */
/*     return ans; */
/* } */

/* long long solve(int N, vector<int> from, vector<int> to, vector<int> weight, int k){ */
/*     vector<vector<pair<int,int>>> adj(N); */
/*     for (int i = 0; i < N-1; ++i){ */
/*         adj[from[i]].emplace_back(to[i], weight[i]); */
/*         adj[to[i]].emplace_back(from[i], weight[i]); */
/*     } */
/*     function<array<long long,2>(int,int)> dfs = [&](int cur, int parent){ */
/*         array<long long, 2> ans{}; */
/*         vector<long long> take, skip, diff; */
/*         for (auto& [next, w] : adj[cur]) if (parent != next){ */
/*             auto [not_full, full] = dfs(next, cur); */
/*             take.push_back(not_full + w); */
/*             skip.push_back(full); */
/*             diff.push_back(take.back() - skip.back()); */
/*         } */
/*         int n = int(diff.size()); */
/*         ranges::nth_element(diff, begin(diff) + k - 1, greater<>()); */
/*         ans[0] = reduce(begin(diff), begin(diff) + min(k, n)) + reduce(begin(skip), end(skip)); */
/*         if (n && n >= k){ */
/*             ans[1] = ans[0]; */
/*             ans[0] -= *min_element(begin(diff), begin(diff) + k); */
/*         } */
/*         return ans; */
/*     }; */
/*     auto ans = dfs(0, -1); */
/*     return max(ans[0], ans[1]); */
/* } */

/* class UF { */
/*     public: */
/*     vector<int> parent, rank; */
/*     vector<unordered_map<int,int>> cnt; */
/*     UF (int n) : parent(n, -1), rank(n), cnt(n) { */

/*     } */

/*     inline int leader(int x){ */
/*         return x == parent[x]? x : (parent[x] = leader(parent[x])); */
/*     } */

/*     inline bool unite(int x, int y, int val){ */
/*         if (parent[x] < 0 || parent[y] < 0){ */
/*             return false; */
/*         } */
/*         x = leader(x), y = leader(y); */
/*         if (x == y){ */
/*             return false; */
/*         } */
/*         if (rank[y] > rank[x]){ */
/*             swap(x, y); */
/*         } */
/*         if (rank[x] == rank[y]){ */
/*             rank[x]++; */
/*         } */
/*         parent[y] = x; */
/*         cnt[x][val] += cnt[y][val]; */
/*         return true; */
/*     } */

/*     inline void add(int id, int val){ */
/*         parent[id] = id; */
/*         ++cnt[id][val]; */
/*     } */

/*     inline count(int id, int val){ */
/*         return cnt[leader(id)][val]; */
/*     } */
/* }; */

/* long long solve(int N, vector<pair<int,int>> edges, vector<int> A){ */
/*     vector<vector<int>> adj(N); */
/*     for (auto& [a, b] : edges){ */
/*         --a, --b; */
/*         adj[a].push_back(b); */
/*         adj[b].push_back(a); */
/*     } */
/*     vector<int> idx(N); */
/*     UF uf(N); */
/*     iota(begin(idx), end(idx), 0); */
/*     ranges::sort(idx, [&](int& a, int &b){return A[a] < A[b];}); */
/*     long long ans = 0; */
/*     for (int i : idx){ */
/*         uf.add(i, A[i]); */
/*         for (int j : adj[i]){ */
/*             int sizeFromGroupA = uf.count(i, A[i]); */
/*             if (uf.unite(i, j, A[i])){ */
/*                 int sizeFromGroupB = uf.count(j, A[i]) - sizeFromGroupA; */
/*                 ans += 1LL * sizeFromGroupA * sizeFromGroupB; */
/*             } */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* vector<int> solve(vector<string> A){ */
/*     int last = 2; */
/*     vector<array<int, 26>> trie(last); */
/*     vector<int> cnt(last); */
/*     for (string s : A){ */
/*         int cur = 1; */
/*         for (char ch : s){ */
/*             if (!trie[cur][ch-'a']){ */
/*                 trie[cur][ch-'a']=last++; */
/*                 trie.emplace_back(); */
/*                 cnt.emplace_back(); */
/*             } */
/*             cur = trie[cur][ch-'a']; */
/*             cnt[cur]++; */
/*         } */
/*     } */
/*     vector<int> ans; */
/*     for (string s : A){ */
/*         int cur = 1, res = 0; */
/*         for (char ch : s){ */
/*             cur = trie[cur][ch-'a']; */
/*             res += cnt[cur]; */
/*         } */
/*         ans.push_back(res); */
/*     } */
/*     return ans; */
/* } */

/* long long solve(int D, vector<int> W){ */
/*     long long lo = *ranges::max_element(W), hi = (long long)1e14; */
/*     while(lo < hi){ */
/*         long long mid = (lo+hi) >> 1, cnt = 0, sum = 0; */
/*         for (int w : W){ */
/*             if (sum + w > mid){ */
/*                 ++cnt; */
/*                 sum = 0; */
/*             } */
/*             sum += w; */
/*         } */
/*         if (cnt+1 <= D){ */
/*             hi = mid; */
/*         }else{ */
/*             lo = mid+1; */
/*         } */
/*     } */
/*     return lo; */
/* } */

/* int minCost(vector<int> A, int n) */
/* { */
/* // Initialize cost to 0 */
/* int cost = 0; */

/* // Sort the array */
/* ranges::sort(A); */
/* /1* sort(A, A + n); *1/ */

/* // Middle element */
/* int K = A[n / 2]; */

/* // Find Cost */
/* for (int i = 0; i < n; ++i) */
/*     cost += abs(A[i] - K); */

/* // If n, is even. Take minimum of the */
/* // Cost obtained by considering both */
/* // middle elements */
/* if (n % 2 == 0) { */
/*     int tempCost = 0; */

/*     K = A[(n / 2) - 1]; */
/*     for (int i = 0; i < n; ++i) */
/*         tempCost += abs(A[i] - K); */

/*     // Take minimum of two cost */
/*     cost = min(cost, tempCost); */
/* } */

/* // Return total cost */
/* return cost; */
/* } */

/* long long solve(vector<int> A){ */
/*     auto go = [&]{ */
/*         long long ans = 0; */
/*         int n = int(A.size()), cur = A[n - 1]; */
/*         for (int i = n -1; ~i; --i, --cur){ */
/*             if (cur >= A[i]){ */
/*                 ans += cur - A[i]; */
/*             }else{ */
/*                 ans += 1LL * (n - 1 - i) * (A[i] - cur); */
/*                 cur = A[i]; */
/*             } */
/*         } */
/*         return ans; */
/*     }; */
/*     long long a = go(); */
/*     ranges::reverse(A); */
/*     return min(a, go()); */
/* } */

/* long long solve(vector<int> indicators, vector<int> profit, int n, int k){ */
/*     auto cal = [&](int mask){ */
/*         long long res = 0; */
/*         for (int i = 0; i < n; ++i) if ((indicators[i] | mask) == mask){ */
/*             res += profit[i]; */
/*         } */
/*         return res; */
/*     }; */
/*     long long ans = cal(k); */
/*     for (int i = 30; ~i; --i) if ((k & 1 << i)){ */
/*         int mask = (k | ((1 << i) - 1)) - (1<<i); */
/*         ans = max(ans, cal(mask)); */
/*     } */
/*     return ans; */
/* } */

/* long long solve(vector<int> indicators, vector<int> profit, int n, int k){ */
/*     long long ans = 0; */
/*     int mask = k^1; // the lowest bit is an edge case, because we are flipping bit, we flip it now to account for that. */
/*     for (int i = 0; i < 30; ++i){ */
/*         mask ^= 1 << i; */
/*         long long cur = 0; */
/*         for (int j = 0; j < n && mask <= k; ++j) if ((indicators[j] | mask) == mask){ */
/*             cur += profit[j]; */
/*         } */
/*         ans = max(ans, cur); */
/*         mask |= 1 << i; */
/*     } */
/*     return ans; */
/* } */

/* long long alt(vector<int> indicators, vector<int> profit, int n, int k){ */
/*     long long ans = 0; */
/*     vector<pair<int,int>> A; */
/*     for (int i = 0; i < n; ++i) if (indicators[i] <= k){ */
/*         A.emplace_back(indicators[i], profit[i]); */
/*     } */
/*     int mask = 0; */
/*     for (int msb = 30; msb >= -1; msb--){ */
/*         if (msb != -1 && ((k >> msb) & 1) == 0){ */
/*             mask <<= 1; */
/*             continue; */
/*         } */
/*         long long cur = 0; */
/*         for (auto& [i,p] : A){ */
/*             if (msb == -1 || ((i >> msb) & 1) == 0){ */
/*                 int top = msb != -1? (i >> (msb + 1)) : i; */
/*                 if ((top | mask) == mask){ */
/*                     cur += p; */
/*                 } */
/*             } */
/*         } */
/*         mask = (mask << 1) | 1; */
/*         ans = max(ans, cur); */
/*     } */
/*     return ans; */
/* } */

/* void solve(vector<pair<int,int>> A){ */
/*     ranges::sort(A); */
/*     /1* auto cmp = [&](int a, int b){ *1/ */
/*     /1*     return A[a] > A[b]; *1/ */
/*     /1* }; *1/ */
/*     auto cmp = [&](int a, int b){ */
/*         return A[a].second - A[a].first > A[b].second - A[b].first; */
/*     }; */
/*     priority_queue<int, vector<int>, decltype(cmp)> pq{cmp}; */
/*     priority_queue<int, vector<int>, decltype(cmp)> pending{cmp}; */
/*     for (int i = 0; i < int(A.size()); ++i){ */
/*         auto& [a, b] = A[i]; */
/*         while (pq.size() && a >= A[pq.top()][0]){ */
/*             pq.pop(); */
/*         } */
/*         if (pq.size() < 3){ */
/*             pq.push(i); */
/*         }else{ */
/*             int change = b - A[pq.top()].first; */
/*             int skip = */
/*         } */
/*     } */
/* } */

/* bool solve(vector<vector<int>> grid){ */
/*     bool ok = 1; */
/*     int N = 9, all = (1 << 9) - 1; */
/*     vector<int> sq(N); */
/*     for (int i = 0; i < N; ++i){ */
/*         int a = 0, b = 0; */
/*         for (int j = 0; j < N; ++j){ */
/*             int v = grid[i][j] - 1; */
/*             int vv = grid[j][i] - 1; */
/*             a |= 1 << v; */
/*             b |= 1 << vv; */
/*             sq[i/3*3+j/3] |= 1 << v; */
/*         } */
/*         ok &= a == all; */
/*         ok &= b == all; */
/*     } */
/*     for (int s : sq){ */
/*         ok &= s == all; */
/*     } */
/*     return ok; */
/* } */

/* long long solve(vector<string> queryType, vector<int> query){ */
/*     long long ans = 0, adj = 0, val = 0; */
/*     unordered_map<long long, long long> mp; */
/*     unordered_map<long long, long long> cnt; */
/*     for (int i = 0; i < int(query.size()); ++i){ */
/*         string q = queryType[i]; */
/*         if (q == "Add"){ */
/*             mp[query[0] - adj] += query[1] - val; */
/*             ++cnt[query[0] - adj]; */
/*         }else if (q == "AddToKey"){ */
/*             adj += query[0]; */
/*         }else if (q == "AddToValue"){ */
/*             val += query[0]; */
/*         }else{ */
/*             ans += mp[query[0] - adj] + cnt[query[0] - adj] * val; */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<vector<int>> A){ */
/*     int m = int(A.size()), n = int(A[0].size()), k = INT_MAX, cnt = 0, need = (1 + n) / 2; */
/*     vector<int> all; */
/*     unordered_map<int, unordered_set<int>> idx; */
/*     for (int i = 0; i < m; ++i){ */
/*         ranges::sort(A[i]); */
/*         for (int x : A[i]){ */
/*             idx[x].insert(i); */
/*             all.push_back(x); */
/*         } */
/*     } */
/*     ranges::sort(all); */
/*     all.resize(unique(begin(all), end(all)) - begin(all)); */
/*     vector<int> R(m), L(m); */
/*     unordered_set<int> ok; */
/*     for (int i = 0, j = 0, in = 0; i < int(all.size()); ++i){ */
/*         for (int k : idx[all[i]]){ */
/*             while(R[k] < n && A[k][R[k]] == all[i]){ */
/*                 ++R[k]; */
/*                 ++in; */
/*             } */
/*             if (R[k] - L[k] >= need){ */
/*                 ok.insert(k); */
/*             } */
/*         } */
/*         while(int(ok.size()) == m){ */
/*             int now = all[i] - all[j]; */
/*             if (now < k){ */
/*                 cnt = in; */
/*                 k = now; */
/*             }else if (now == k){ */
/*                 cnt = min(cnt, in); */
/*             } */
/*             for (int k : idx[all[j]]){ */
/*                 while(L[k] < R[k] && A[k][L[k]] == all[j]){ */
/*                     ++L[k]; */
/*                     --in; */
/*                 } */
/*                 if (R[k] - L[k] < need){ */
/*                     ok.erase(k); */
/*                 } */
/*             } */
/*             ++j; */
/*         } */
/*     } */

/*     return cnt * k; */
/* } */

/* vector<int> solve(int n, vector<int> A){ */
/*     vector<int> ans(n); */
/*     int mx = 0, M = int(1e9) + 7, sum = 0, ssum = 0; */
/*     for (int i = 0; i < n; ++i){ */
/*         sum += A[i]; */
/*         sum %= M; */
/*         ssum += sum; */
/*         ssum %= M; */
/*         mx = max(mx, A[i]); */
/*         ans[i] = ssum + 1LL * mx * (i + 1) % M; */
/*         ans[i] %= M; */
/*     } */
/*     return ans; */
/* } */

/* vector<int> alt(int n, vector<int> A){ */
/*     int mx = 0, tot = 0, M = int(1e9) + 7; */
/*     vector<int> ans(n); */
/*     for (int i = 0; i < n; ++i){ */
/*         tot += A[i]; */
/*         tot %= M; */
/*         int nmax = max(mx, A[i]); */
/*         ans[i] = ((i == 0? 0 : ans[i-1]) + tot) % M + 1LL * i * (nmax - mx + M) % M; */
/*         ans[i] %= M; */
/*         ans[i] += nmax; */
/*         ans[i] %= M; */
/*         mx = nmax; */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<int> A){ */
/*     int ans = 0, N = 1 << 12; */
/*     vector<int> cnt(N); */
/*     for (int x : A){ */
/*         ++cnt[x]; */
/*     } */
/*     int c= 0; */
/*     for (int i = 1; i < N; i <<= 1){ */
/*         for (int a = i; a < N; a = (a + 1) | i){ */
/*             for (int mask = (a^(N-1))|i, b = mask; b >= a && cnt[a]; b = (b - 1) & mask){ */
/*                 ++c; */
/*                 if ((b | i) != b){ */
/*                     continue; */
/*                 } */
/*                 if (a == b){ */
/*                     ans += cnt[a] * (cnt[b] - 1) / 2; */
/*                 }else{ */
/*                     ans += cnt[a] * cnt[b]; */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     cout << "c = " << c << '\n'; */
/*     return ans; */
/* } */


/* int getMinCost(vector<int> val, int t_nodes, vector<int> t_from, vector<int> t_to) { */
/*     int ans = 0, n = int(val.size()); */
/*     vector<vector<int>> adj(n); */
/*     for (int i = 0; i < n-1; ++i){ */
/*         --t_from[i]; */
/*         --t_to[i]; */
/*         adj[t_from[i]].push_back(t_to[i]); */
/*         adj[t_to[i]].push_back(t_from[i]); */
/*     } */
/*     function<int(int,int)> dfs = [&](int cur, int parent){ */
/*         int cnt = val[cur] & 1; */
/*         for (int next : adj[cur]) if (next != parent){ */
/*             int res = dfs(next, cur) & 1; */
/*             ans += res; */
/*             cnt ^= res; */
/*         } */
/*         return cnt; */
/*     }; */
/*     dfs(0, -1); */
/*     return ans; */
/* } */

/* long getMaxProduct(vector<vector<int>> arr) { */
/*     int m = int(arr.size()), n = int(arr[0].size()), req = (n + 1) / 2; */
/*     vector<int> A; */
/*     unordered_map<int, vector<int>> mp; */
/*     for (int i = 0; i < m; ++i){ */
/*         sort(begin(arr[i]), end(arr[i])); */
/*         for (int j = 0; j < n; ++j){ */
/*             A.push_back(arr[i][j]); */
/*             if (mp[arr[i][j]].empty() || mp[arr[i][j]].back() != i){ */
/*                 mp[arr[i][j]].push_back(i); */
/*             } */
/*         } */
/*     } */
/*     sort(begin(A), end(A)); */
/*     A.resize(unique(begin(A), end(A)) - begin(A)); */
/*     vector<int> L(m), R(m); */
/*     int cnt = 0, k = 1e9, num = 0; */
/*     unordered_set<int> s; */
/*     for (int i = 0, l = 0; i < int(A.size()); ++i){ */
/*         for (int j : mp[A[i]]){ */
/*             while(R[j] < n && arr[j][R[j]] == A[i]){ */
/*                 ++R[j]; */
/*                 ++cnt; */
/*             } */
/*             if (R[j] - L[j] >= req){ */
/*                 s.insert(j); */
/*             } */
/*         } */
/*         while(int(s.size()) == m){ */
/*             if (A[i] - A[l] < k){ */
/*                 k = A[i] - A[l]; */
/*                 num = cnt; */
/*             }else if (A[i] - A[l] == k){ */
/*                 num = max(num, cnt); */
/*             } */
/*             for (int j : mp[A[l]]){ */
/*                 while(L[j] < R[j] && arr[j][L[j]] == A[l]){ */
/*                     ++L[j]; */
/*                     --cnt; */
/*                 } */
/*                 if (R[j] - L[j] < req){ */
/*                     s.erase(j); */
/*                 } */
/*             } */
/*             ++l; */
/*         } */
/*     } */
/*     return 1LL * k * num; */
/* } */


/* int solve(vector<vector<bool>> grid, int X){ */
/*     int m = int(grid.size()), n = int(grid[0].size()), tot = 0; */
/*     int dp[m+1][n+1][X+1]; */
/*     int dp2[n+1][n+1][m+1][X+1]; */
/*     memset(dp, 0, sizeof(dp)); */
/*     memset(dp2, 0, sizeof(dp2)); */
/*     vector<int> row(m+1), col(n+1); */
/*     for (int i = 0; i < m; ++i){ */
/*         for (int j = 0; j < n; ++j){ */
/*             dp[i][j][0] = 1; */
/*         } */
/*     } */
/*     for (int i = 0; i < n; ++i){ */
/*         for (int j = 0; j < n; ++j){ */
/*             for (int k = 0; k < m; ++k){ */
/*                 dp2[i][j][k][0] = 1; */
/*             } */
/*         } */
/*     } */
/*     for (int i = 1; i <= n; ++i){ */
/*         for (int j = 1; j <= i; ++j){ */
/*             for (int k = 1; k <= m; ++k){ */
/*                 bool ok = 0; */
/*                 for (int w = k; w; w--){ */
/*                     for (int a = i; a <= j; ++a){ */
/*                         ok |= grid[w-1][a-1]; */
/*                     } */
/*                     for (int x = 1; x <= X && ok; ++x){ */
/*                         dp2[j][i][k][x] += dp2[j][i][w-1][x-1]; */
/*                     } */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     for (int i = 1; i <= m; ++i){ */
/*         for (int j = 1; j <= n; ++j){ */
/*             for (int k = 0; k < j; ++k){ */
/*                 for (int x = 0; x <= X; ++x){ */
/*                     for (int xx = 0; x+xx <= X; ++xx){ */
/*                         dp[i][j][x+xx] += dp[i][k][x] * dp2[k+1][j][i][xx]; */
/*                         /1* if (dp[i][j][x+xx]){ *1/ */
/*                         /1*     cout << "i = " << i << ", j = " << j << "x+xx, = " << x+xx << ", got = " << dp[i][j][x+xx] << '\n'; *1/ */
/*                         /1* } *1/ */
/*                     } */
/*                 } */
/*             } */
/*         } */
/*     } */

/* #define debug(...) cout << __LINE__ << ": " << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'; */

    /* for (int i = 0; i <= m; ++i){ */
    /*     for (int j = 0; j <= n; ++j){ */
    /*         for (int x = 0; x <= X; ++x){ */
    /*             if (dp[i][j][x]){ */
    /*                 debug(dp[i][j][x]); */
    /*                 /1* cout << __LINE__ << ": " << #(dp[i][j][x]) << " = " << dp[i][j][x] << '\n'; *1/ */
    /*             } */
    /*             /1* cout << "i = " << i << ", j = " << j << ". x, = " << x << ", got = " << dp[i][j][x] << '\n'; *1/ */
    /*         } */
    /*     } */
    /* } */

    /* for (int i = 1; i <= m; ++i){ */
    /*     for (int j = 1; j <= n; ++j){ */
    /*         tot += grid[i-1][j-1]; */
    /*         row[i] += grid[i-1][j-1]; */
    /*         col[j] += grid[i-1][j-1]; */
    /*         for (int k = 0, good = tot; k < i && good; good -= row[++k]){ */
    /*             for (int x = 1; x <= X; ++x){ */
    /*                 dp[i][j][x] += dp[k][j][x-1]; */
    /*             } */
    /*         } */
    /*         for (int k = 1, good = tot; k < j && good; good -= col[++k]){ */
    /*             for (int x = 1; x <= X; ++x){ */
    /*                 dp[i][j][x] += dp[i][k][x-1]; */
    /*             } */
    /*         } */
    /*     } */
    /* } */
    /* for (int i = 0; i <= X; ++i){ */
    /*     cout << dp[n][m][i] << ' '; */
    /* } */
    /* cout << '\n'; */
    /* return dp[n][m][X]; */
/* } */

/* bool solve(vector<int> A, vector<int> B){ */
/*     constexpr static int N = 2000000; */
/*     bool ok = 1; */
/*     array<int, 2*N+2> a{}; */
/*     array<int, 2*N+2> b{}; */
/*     for (int x : A) ++a[x]; */
/*     for (int x : B) ++b[x]; */
/*     for (int i = 0; i < 2*N+2; ++i){ */
/*         ok &= b[i] >= 0; */
/*         int t = min(a[i], b[i]); */
/*         a[i] -= t; */
/*         b[i] -= t; */
/*         if (i < 2*N+1){ */
/*             b[i+1] -= a[i]; */
/*         } */
/*     } */
/*     return ok; */
/* } */

/* int solve(vector<vector<int>> A, int K) { */
/*     int m = int(A.size()), n = int(A[0].size()), M = int(1e9) + 7; */
/*     int dp[m+1][n+1][K+1]; */
/*     int row[m+1][n+1], col[n+1][m+1]; */
/*     memset(dp, 0, sizeof(dp)); */
/*     memset(row, 0, sizeof(row)); */
/*     memset(col, 0, sizeof(col)); */
/*     for (int i = m-1; ~i; --i){ */
/*         for (int j = n-1; ~j; --j){ */
/*             dp[i][j][1] = A[i][j] == 2 || dp[i+1][j][1] || dp[i][j+1][1]; */
/*             row[i][j] = row[i][j+1] + (A[i][j] == 2); */
/*             col[j][i] = col[j][i+1] + (A[i][j] == 2); */
/*         } */
/*     } */
/*     for (int i = m-1; ~i; --i){ */
/*         for (int j = n-1; ~j; --j){ */
/*             for (int jj = j, cnt = col[jj][i]; jj < n; cnt += col[++jj][i]){ */
/*                 for (int k = 2; k <= K && cnt; ++k){ */
/*                     dp[i][j][k] += dp[i][jj+1][k-1]; */
/*                     dp[i][j][k] %= M; */
/*                 } */
/*             } */
/*             for (int ii = i, cnt = row[ii][j]; ii < m; cnt += row[++ii][j]){ */
/*                 for (int k = 2; k <= K && cnt; ++k){ */
/*                     dp[i][j][k] += dp[ii+1][j][k-1]; */
/*                     dp[i][j][k] %= M; */
/*                 } */
/*             } */
/*         } */
/*     } */

/*     return dp[0][0][K]; */
/* } */

/* void solve(vector<pair<int,int>> A){ */
/*     vector<stack<int>> freq(1); */
/*     unordered_map<int,int> mp; */
/*     for (auto& [type, num] : A){ */
/*         if (type == 1){ */
/*             if (++mp[num] >= int(freq.size())){ */
/*                 freq.emplace_back(); */
/*             } */
/*             freq[mp[num]].push(num); */
/*         }else{ */
/*             int bye = freq.back().top(); */
/*             --mp[bye]; */
/*             freq.back().pop(); */
/*             if (freq.back().empty()){ */
/*                 freq.pop_back(); */
/*             } */
/*             cout << bye << ' '; */
/*         } */
/*     } */
/* } */

// 1 <= int(A.size()) <= 1e5
// 0 <= A[i] <= 1e9
/* long long solve(vector<int> A){ */
/*     long long sum = 0, ans = 0; */
/*     /1* ranges::sort(A); *1/ */
/*     for (int n : A){ */
/*         sum += n; */
/*         ans |= n | sum; */
/*     } */
/*     return ans; */
/* } */

/* long long brute(vector<int> A){ */
/*     int n = int(A.size()); */
/*     long long ans = 0; */
/*     for (int i = 0; i < 1<<n; ++i){ */
/*         long long sum = 0; */
/*         for (int j = 0; j < n; ++j){ */
/*             if (i & 1 << j){ */
/*                 sum += A[j]; */
/*             } */
/*         } */
/*         ans |= sum; */
/*     } */

/*     return ans; */
/* } */

/* void solve(string a, string b, int x){ */
/*     if (x > 18){ */
/*         cout << "IMPOSSIBLE"; */
/*         return; */
/*     } */
/*     vector<bool> has(20); */
/*     for (char ch : a){ */
/*         has[ch-'0'] = 1; */
/*     } */
/*     for (char ch : b){ */
/*         if (has[x - ch + '0']){ */
/*             cout << ch-'0' << ' ' << x-ch+'0'; */
/*             return; */
/*         } */
/*     } */
/*     cout << "IMPOSSIBLE"; */
/* } */

/* while(1){ */
/*     wait(WHAT); */
/*     /1* CS *1/ */
/*     signal(WHAT); */
/*     /1* RS *1/ */
/* } */

/* void solve(vector<int> A, vector<array<int, 3>> Q){ */
/*     partial_sum(begin(A), end(A), begin(A)); */
/*     for (auto& [k, y, x] : Q){ */
/*         int mask = 0; */
/*         for (int i = 30; ~i; --i){ */
/*             int cnt = 0; */
/*             for (int j = k-1; j < int(A.size()) && (x & 1<<i) == 0; ++j){ */
/*                 int sum = A[j] - (j < k? 0 : A[j-k]); */
/*                 cnt += (sum & (mask | 1<<i)) == (mask | 1<<i); */
/*             } */
/*             if (cnt >= y){ */
/*                 mask |= 1 << i; */
/*             } */
/*         } */
/*         cout << (mask|x) << ' '; */
/*     } */
/* } */

/* #define NONE -1 */
/* #define RR 0 */
/* #define SJF 1 */
/* #define FCFS 2 */
/* #define PRI 3 */
/* #define SRJF 4 */
/* #define NPRI 5 */

/* void solve(vector<array<int, 3>> A, int cmp1, int cmp2=NONE, int quantum=0){ */
/*     cout << "\nCaution: This is 0-indexed.\n"; */
/*     deque<int> dq; */
/*     int n = int(A.size()); */
/*     bitset<100> done; */
/*     vector<int> wait(n), used(n); */
/*     vector<array<int, 3>> B{A}; */

/*     auto First = [&](int a, int b) -> bool{ */
/*         return cmp2 == FCFS && A[a][0] < A[b][0]; */
/*     }; */

/*     auto Job = [&](int a, int b) -> bool{ */
/*         return cmp2 == SJF && A[a][1] < A[b][1]; */
/*     }; */

/*     auto Priority = [&](int a, int b) -> bool{ */
/*         return cmp2 == PRI && A[a][2] < A[b][2]; */
/*     }; */


/*     // Round Robin */
/*     for (int t = 0, cnt = 0; cnt < n && cmp1 == RR; ++t){ */
/*         for (int j = 0; j < n; ++j) if (t == A[j][0]){ */
/*             dq.push_back(j); */
/*         } */
/*         if (dq.empty()){ */
/*             cout << '-'; */
/*             continue; */
/*         } */
/*         int cur = dq.front(); */
/*         cout << cur; */
/*         for (int i = 1; i < int(dq.size()); ++i){ */
/*             ++wait[dq[i]]; */
/*         } */
/*         if (++used[cur] == A[cur][1]){ */
/*             dq.pop_front(); */
/*             ++cnt; */
/*             continue; */
/*         } */
/*         if (used[cur] % quantum == 0){ */
/*             dq.pop_front(); */
/*             dq.push_back(cur); */
/*         } */
/*     } */

/*     // Shortest Job First */
/*     set<int> s; */
/*     for (int cnt = 0, t = 0, c = -1; cmp1 == SJF && cnt < n; ++t){ */
/*         for (int j = 0; j < n; ++j) if (t == A[j][0]){ */
/*             s.insert(j); */
/*         } */
/*         if (s.empty()){ */
/*             cout << '-'; */
/*             continue; */
/*         } */
/*         if (c == -1){ */
/*             for (int d : s){ */
/*                 if (c == -1 || A[d][1] < A[c][1] || (A[d][1] == A[c][1] && (Priority(d, c) || First(d, c)))){ */
/*                     c = d; */
/*                 } */
/*             } */
/*         } */
/*         cout << c; */
/*         for (int d : s) if (d != c){ */
/*             ++wait[d]; */
/*         } */
/*         if (++used[c] == A[c][1]){ */
/*             ++cnt; */
/*             s.erase(c); */
/*             c = -1; */
/*         } */
/*     } */

/*     // First Come First Served */
/*     for (int cnt = 0, t = 0, c = -1; cmp1 == FCFS && cnt < n; ++t){ */
/*         for (int j = 0; j < n; ++j) if (t == A[j][0]){ */
/*             s.insert(j); */
/*         } */
/*         if (s.empty()){ */
/*             cout << '-'; */
/*             continue; */
/*         } */
/*         if (c == -1){ */
/*             for (int d : s){ */
/*                 if (c == -1 || A[c][0] > A[d][0] || (A[c][0] == A[d][0] && (Priority(d, c) || Job(d, c)))){ */
/*                     c = d; */
/*                 } */
/*             } */
/*         } */
/*         cout << c; */
/*         for (int d : s) if (c != d){ */
/*             ++wait[d]; */
/*         } */
/*         if (++used[c] == A[c][1]){ */
/*             ++cnt; */
/*             s.erase(c); */
/*             c = -1; */
/*         } */
/*     } */

/*     // Priority */
/*     for (int cnt = 0, t = 0, c = -1; cmp1 == PRI && cnt < n; ++t){ */
/*         for (int j = 0; j < n; ++j) if (t == A[j][0]){ */
/*             s.insert(j); */
/*         } */
/*         if (s.empty()){ */
/*             cout << '-'; */
/*             continue; */
/*         } */
/*         if (c == -1){ */
/*             for (int d : s){ */
/*                 if (c == -1 || A[c][2] > A[d][2] || (A[c][2] == A[d][2] && (First(d, c) || Job(d, c)))){ */
/*                     c = d; */
/*                 } */
/*             } */
/*         } */
/*         cout << c; */
/*         for (int d : s) if (c != d){ */
/*             ++wait[d]; */
/*         } */
/*         if (++used[c] == A[c][1]){ */
/*             ++cnt; */
/*             s.erase(c); */
/*             c = -1; */
/*         } */
/*     } */

/*     // Shortest Remaining Job First */
/*     for (int cnt = 0, t = 0, c = -1; cmp1 == SRJF && cnt < n; ++t){ */
/*         for (int j = 0; j < n; ++j) if (t == A[j][0]){ */
/*             s.insert(j); */
/*         } */
/*         if (s.empty()){ */
/*             cout << '-'; */
/*             continue; */
/*         } */
/*         if (c == -1){ */
/*             for (int d : s){ */
/*                 if (c == -1 || B[d][1] < B[c][1] || (B[d][1] == B[c][1] && (Priority(d, c) || First(d, c)))){ */
/*                     c = d; */
/*                 } */
/*             } */
/*         } */
/*         cout << c; */
/*         --B[c][1]; */
/*         for (int d : s) if (d != c){ */
/*             ++wait[d]; */
/*         } */
/*         if (++used[c] == A[c][1]){ */
/*             ++cnt; */
/*             s.erase(c); */
/*         } */
/*         c = -1; */
/*     } */

/*     // Preemptive Priority */
/*     for (int cnt = 0, t = 0, c = -1; cmp1 == NPRI && cnt < n; ++t){ */
/*         for (int j = 0; j < n; ++j) if (t == A[j][0]){ */
/*             s.insert(j); */
/*         } */
/*         if (s.empty()){ */
/*             cout << '-'; */
/*             continue; */
/*         } */
/*         if (c == -1){ */
/*             for (int d : s){ */
/*                 if (c == -1 || A[c][2] > A[d][2] || (A[c][2] == A[d][2] && (First(d, c) || Job(d, c)))){ */
/*                     c = d; */
/*                 } */
/*             } */
/*         } */
/*         cout << c; */
/*         for (int d : s) if (c != d){ */
/*             ++wait[d]; */
/*         } */
/*         if (++used[c] == A[c][1]){ */
/*             ++cnt; */
/*             s.erase(c); */
/*         } */
/*         c = -1; */
/*     } */

/*     // Print Details */
/*     int tot_wait = reduce(begin(wait), end(wait)); */
/*     int tot_turn = tot_wait; */
/*     for (int i = 0; i < n; ++i){ */
/*         tot_turn += A[i][1]; */
/*     } */
/*     cout << '\n'; */
/*     cout << "Total Wait Time = " << 1.*tot_wait/n << '\n'; */
/*     cout << "Total Turnaround Time = " << 1.*tot_turn/n << '\n'; */
/*     for (int i = 0; i < n; ++i){ */
/*         cout << "P" << i << ' ' << wait[i] << ' ' << wait[i]+A[i][1] << '\n'; */
/*     } */
/* } */

/* void solve(vector<int> A){ */
/*     int n = int(A.size()); */
/*     vector<queue<int>> v(n+1); */
/*     stack<queue<int>> stk; */
/*     for (int i = 0; i < n; ++i){ */
/*         v[A[i]].push(i); */
/*     } */
/*     vector<int> ans(n); */
/*     for (int i = 0; n; ++i){ */
/*         if (v[i].size()){ */
/*             stk.push(v[i]); */
/*         } */
/*         if (stk.empty()){ */
/*             continue; */
/*         } */
/*         --n; */
/*         ans[stk.top().front()] = i; */
/*         stk.top().pop(); */
/*         if (stk.top().empty()){ */
/*             stk.pop(); */
/*         } */
/*     } */
/*     return ans; */
/* } */

/* int solve(vector<int> A){ */
/*     array<long long, 1<<14> dp{}; */
/*     int M = int(1e9) + 7, ans = 0; */
/*     dp[0] = 1; */
/*     for (int x : A){ */
/*         dp[x] = x? 1 : dp[x] + 1; */
/*         ans += x == 0; */
/*     } */
/*     for (int i = 1; i < 1<<14; ++i){ */
/*         for (int j = i-1; j > (i^j); j = (j-1)&i){ */
/*             dp[i] += dp[j] * dp[i^j] % M; */
/*             dp[i] %= M; */
/*         } */
/*         ans += int(dp[i] * dp[0] % M); */
/*         ans %= M; */
/*     } */
/*     return ans; */
/* } */

long long solve(vector<int> A, int K){
    int n = int(A.size()), M = int(1e9) + 7;
    vector<long long> dp(K+1);
    unordered_map<int,int> cnt;
    dp[0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = min(K, i+1); j; --j){
            dp[j] = dp[j - 1] + max(0LL, dp[j] * (j - cnt[A[i]]));
            dp[j] %= M;
            /* cout << dp[j] << ' '; */
        }
        dp[0] = 0;
        ++cnt[A[i]];
        /* cout << '\n'; */
    }
    return dp[K];
    /* vector<long long> dp(n); */
    /* unordered_map<int, int> cnt; */
    /* for (int i = 0; i < n; ++i){ */
    /*     dp[i] = ++cnt[A[i]] == 1 && (i == 0 || dp[i-1]); */
    /* } */
    /* cout << dp[n-1] << '\n'; */
    /* for (int i = 2; i <= K; ++i){ */
    /*     auto tmp = cnt; */
    /*     for (int j = n-1; j >= i; --j){ */
    /*         --cnt[A[j]]; */
    /*         dp[j] = max(0LL, dp[j - 1] + dp[j] * (i - cnt[A[j]])); */
    /*         dp[j] %= M; */
    /*     } */
    /* cout << dp[n-1] << '\n'; */
    /*     cnt = tmp; */
    /* } */
    /* return dp[n-1]; */
}

constexpr static int SIZE = int(1e9);
array<int, SIZE> arr{};
/* int arr[SIZE]; */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve({1,2,3}, 2) << '\n';
    cout << solve({1,2,3}, 1) << '\n';
    cout << solve({1,2,3,4,5}, 3) << '\n';
    cout << solve({1,1}, 1) << '\n';
    cout << solve({1,1}, 2) << '\n';
    cout << solve({1,1,2,1,1}, 4) << '\n';
    cout << solve({2,1,1,1,1}, 4) << '\n';
    cout << solve({1,1,1,1,2}, 4) << '\n';
    cout << solve({1,1,1,1}, 4) << '\n';
    cout << solve({1,1,2,2,3}, 4) << '\n';
    cout << solve({1,1,2,2,3}, 5) << '\n';
    cout << solve({1,1,2,2,3}, 3) << '\n';
    cout << solve({1,1,2,2,3}, 2) << '\n';



    /* char* ans = new char[100]; */
    /* vector<string> all; */
    /* for (int i = 0; i < all.size() - 1; ++i){ */
    /*     cout << i << '\n'; */
    /* } */
    /* cout << itoa(28358358235, ans, 16) << '\n'; */
    /* solve({1,2,3,2,4}); */
    /* solve({1,3,3,3,2}); */
    /* solve({1,1,1,1}); */
    /* solve({7,3,11,3,4,3,11,7,5,6,1,4,2,8,4,3,5,5,3,2,6,1}); */
    /* cout << solve({1,2,3}) << '\n'; */
    /* cout << solve({1,2,3,0}) << '\n'; */
    /* cout << solve({0,0,0,0}) << '\n'; */
    /* cout << solve({1,2}) << '\n'; */
    /* cout << solve({1,2,0,0,0}) << '\n'; */
    /* solve({1,2,3,2,4}); */
    /* solve({1,3,3,3,2}); */
    /* solve({1,1,1,1}); */
    /* solve({7,3,11,3,4,3,11,7,5,6,1,4,2,8,4,3,5,5,3,2,6,1}); */
    /* solve({5,5,5,5,5}); */
    /* solve({1,1,1,2,2}); */
    /* solve({1,2,2,1}); */

    /* solve({{1, 6, 20}, {6, 2, 20}, {2, 5, 50}, {6, 6, 20}, {5, 2, 20}}, RR, -1, 2); // arrival, duration, priority */
    /* solve({{6, 5, 30}, {1, 1, 20}, {3, 4, 30}, {6, 6, 20}, {6, 1, 40}}, RR, -1, 1); // arrival, duration, priority */
    /* solve({{6, 5, 30}, {4, 3, 50}, {0, 3, 30}, {2, 5, 30}, {3, 3, 40}}, SJF, PRI, 0); */
    /* solve({{1, 6, 40}, {4, 3, 30}, {5, 5, 40}, {4, 6, 40}, {0, 1, 20}}, SJF, FCFS, 0); */
    /* solve({{1,2,30}, {6,1,50},{0,2,30},{4,1,30},{1,2,50}}, FCFS, PRI, 0); */
    /* solve({{5,6,40},{2,5,20},{6,2,50},{2,6,50},{2,1,20}}, PRI, FCFS, 0); */
    /* solve({{5,2,50},{3,1,20},{6,4,20},{0,3,40},{3,5,30}}, SRJF, FCFS, 0); */
    /* solve({{2,4,20},{5,5,50},{0,4,20},{3,3,50},{1,4,30}}, NPRI, FCFS, 0); */

    /* solve({{1,6,50},{0,1,30},{5,1,30},{0,6,40},{3,4,50}}, SRJF, PRI, 0); */
    /* solve({{5,6,50},{0,4,20},{0,6,40},{0,6,20},{0,3,30}}, NPRI, FCFS, 0); */
    /* solve({{6,1,20},{4,6,20},{4,6,20},{4,4,30},{2,3,30}}, RR, NONE, 2); */
    /* solve({{0,3,40},{3,6,20},{4,6,50},{2,4,30},{5,2,40}}, RR, NONE, 3); */
    /* solve({{4,6,50},{0,4,40},{3,6,40},{2,6,40},{0,2,30}}, SRJF, FCFS, 0); */
    /* solve({{5,1,30},{0,4,40},{1,6,30},{3,3,50},{3,6,40}}, SJF, PRI, 0); */
    /* solve({{2,1,20},{4,2,40},{4,1,40},{4,5,20},{3,1,50}}, SJF, PRI); */
    /* solve({{0,3,20},{4,6,50},{3,4,30},{0,5,40},{0,4,20}}, FCFS, PRI); */
    /* solve({{0,5,50},{1,5,30},{1,3,40},{0,4,20},{6,3,20}}, SRJF, FCFS); */
    /* solve({{0, 10, 3}, {0, 1, 1}, {0, 2, 4}, {0, 1, 5}, {3, 5, 2}}, NPRI); */





    /* vector<int> A {3,1,2}; */
    /* ranges::sort(A, &cmp); */
    /* for (int x : A){ */
    /*     cout << x << ' '; */
    /* } */

    /* solve({1,2,3,4,5}, {{2,3,9}, {3,2,17}}); // 9, 25 */
    /* cout << '\n'; */
    /* solve({5,4,2,4,9}, {{2,2,7}, {2,3,6}}); //15, 6 */

    /* for (int i = 0; i < 10000; ++i){ */
    /*     int n = random(1, 15); */
    /*     vector<int> A(n); */
    /*     for (int j = 0; j < n; ++j){ */
    /*         A[j] = random(0, 100); */
    /*     } */
    /*     long long a = solve(A); */
    /*     long long b = brute(A); */
    /*     if (a != b){ */
    /*         cout << '\n'; */
    /*         cout << a << '\n' << b << '\n'; */
    /*         for (int n : A){ */
    /*             cout << n << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         return 0; */
    /*     } */
    /* } */
    /* cout << solve({1,2,3,4}) << '\n'; */
    /* cout << solve({1,1}) << '\n'; */
    /* brute({1,1}); */
    /* solve({{1,2},{1,3},{1,2},{1,4},{2,-1},{2,-1}}); */
    /* string s = "10 111"; */
    /* stringstream ss; */
    /* ss << s; */
    /* int a; */
    /* while(ss >> a){ */
    /*     cout << a << '\n'; */
    /* } */
    /* cout << solve({{1,1,1},{1,1,1},{1,1,1}}, 9) << '\n'; */
    /* cout << solve({{1}}, 1) << '\n'; */
    /* cout << solve({10,7,2,8,3}) << '\n'; */
    /* cout << solve({{1,2},{3,4},{8,9}}) << '\n'; // 24 */
    /* cout << solve({{2,3},{1,2},{4,3}}) << '\n'; // 4 */
    /* cout << solve({{1,4,3},{3,5,6}}) << '\n'; // 8 */
    /* cout << solve({{1,1,1,1},{1,1,1,1}}) << '\n'; */
    /* cout << solve({{1,1,1,2},{2,2,2,3}}) << '\n'; */
    /* cout << solve({{1},{2}}) << '\n'; */
    /* for (int i = 0; i< 100; ++i){ */
    /*     int n = random(1, 1000); */
    /*     vector<int> A(n); */
    /*     for (int& x : A){ */
    /*         x = random(0, 1e9); */
    /*     } */
    /*     auto a = solve(n, A); */
    /*     auto b = alt(n, A); */
    /*     if (a != b){ */
    /*         for (int x : a){ */
    /*             cout << x << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         for (int x : b){ */
    /*             cout << x << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         return 0; */
    /*     } */
    /* } */
    /* for (int x : alt(3, {1, 2, 3})){ */
    /*     cout << x << ' '; */
    /* } */
    /* cout << '\n'; */
    /* solve({{1, 3}, {1, 4}, {1, 2}, {1, 2}, {1, 4}, {2, 3}, {2, 5}, {2, 6}, {2, 3}, {2, 4}, {5, 6}, {4, 6}}); */
    /* for (int i = 0; i < 100000; ++i){ */
    /*     int n = random(1, 1000); */
    /*     int MAX = (1<<5)-1; */
    /*     vector<int> ind(n), profit(n); */
    /*     for (int i = 0; i < n; ++i){ */
    /*         ind[i] = random(0, MAX); */
    /*         profit[i] = random(1, 1e2); */
    /*     } */
    /*     int k = random(0, MAX); */
    /*     long long a = solve(ind, profit, n, k); */
    /*     long long b = alt(ind, profit, n, k); */
    /*     if (a != b){ */
    /*         cout << a << ' ' << b << '\n'; */
    /*         cout << "k = " << k << '\n'; */
    /*         for (int n : ind){ */
    /*             cout << n << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         for (int n : profit){ */
    /*             cout << n << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         cout << '\n'; */
    /*     } */
    /* } */

    /* cout << solve({3,4,2}, {3,4,5}, 3, 6) << '\n'; // 9 */
    /* cout << solve({2,3,1,5,9}, {1,2,6,1,5}, 5, 3) << '\n'; // 9 */
    /* cout << solve({1,2,3,4}, {4,3,2,1}, 4, 1) << '\n'; // 4 */

    /* cout << alt({3,4,2}, {3,4,5}, 3, 6) << '\n'; // 9 */
    /* cout << alt({2,3,1,5,9}, {1,2,6,1,5}, 5, 3) << '\n'; // 9 */
    /* cout << alt({1,2,3,4}, {4,3,2,1}, 4, 1) << '\n'; // 4 */
    /* cout << solve({19,20,10,11}) << '\n'; */
    /* cout << solve({5,7,9,4,11}) << '\n'; */
    /* cout << solve({7,8,9,10,11}) << '\n'; */
    /* cout << solve({1}) << '\n'; */
    /* cout << solve({1,3}) << '\n'; */
    /* cout << solve({1,2}) << '\n'; */
    /* cout << solve({30,20,10}) << '\n'; */
    /* cout << solve({1,3,2}) << '\n'; */


    /* cout << '\n'; */
    /* cout << minCost({19,20,10,11},4) << '\n'; */
    /* cout << minCost({5,7,9,4,11},5) << '\n'; */
    /* cout << minCost({7,8,9,10,11},5) << '\n'; */
    /* cout << minCost({1},1) << '\n'; */
    /* cout << minCost({1,3},2) << '\n'; */
    /* cout << minCost({1,2},2) << '\n'; */
    /* cout << minCost({30,20,10},3) << '\n'; */
    /* cout << minCost({1,3,2},3) << '\n'; */
    /* cout << solve(2, {1,4,7,5}) << '\n'; */
    /* cout << solve(3, {1,4,7,5}) << '\n'; */
    /* for (int x : solve({"aab", "aac"})){ */
    /*     cout << x << ' '; */
    /* } */
    /* cout << solve(6, {{1,2},{1,3},{3,5},{3,4},{2,6}}, {2,3,1,2,3,3}) << '\n'; */
    /* cout << solve(6, {{1,2},{1,3},{3,5},{3,4},{2,6}}, {2,2,2,2,2,2}) << '\n'; */
    /* string s = "a ,   b ,  c"; */
    /* stringstream ss{s}; */
    /* string w; */
    /* while(ss >> w){ */
    /*     cout << w << '\n'; */
    /* } */
    /* TreeNode* root = new TreeNode(1); */
    /* TreeNode* two = new TreeNode(2); */
    /* TreeNode* three = new TreeNode(3); */
    /* TreeNode* four = new TreeNode(4); */
    /* TreeNode* five = new TreeNode(5); */
    /* TreeNode* six = new TreeNode(6); */
    /* TreeNode* seven = new TreeNode(7); */
    /* TreeNode* eight = new TreeNode(8); */
    /* TreeNode* nine = new TreeNode(9); */
    /* auto L = [](auto& a, auto& b){ */
    /*     a->left=b; */
    /* }; */
    /* auto R = [](auto& a, auto& b){ */
    /*     a->right=b; */
    /* }; */
    /* L(root, three); */
    /* L(three, four); */
    /* L(four, five); */
    /* L(five, eight); */
    /* L(eight, nine); */
    /* L(two, six); */
    /* R(root, two); */
    /* R(two, seven); */
    /* for (auto& [id, mx] : solve(root)){ */
    /*     cout << id << ' ' << mx << '\n'; */
    /* } */
    /* cout << solve(8, {0, 1, 1, 3, 3, 5, 5}, {1, 2, 3, 4, 5, 6, 7}, {100, 19, 22, 21, 20, 10, 15}, 0) << '\n'; */
    /* cout << solve(8, {0, 1, 1, 3, 3, 5, 5}, {1, 2, 3, 4, 5, 6, 7}, {100, 19, 22, 21, 20, 10, 15}, 1) << '\n'; */
    /* cout << solve(8, {0, 1, 1, 3, 3, 5, 5}, {1, 2, 3, 4, 5, 6, 7}, {100, 19, 22, 21, 20, 10, 15}, 2) << '\n'; */
    /* cout << solve(8, {0, 1, 1, 3, 3, 5, 5}, {1, 2, 3, 4, 5, 6, 7}, {100, 19, 22, 21, 20, 10, 15}, 3) << '\n'; */
    /* cout << solve(8, {0, 1, 1, 3, 3, 5, 5}, {1, 2, 3, 4, 5, 6, 7}, {100, 19, 22, 21, 20, 10, 15}, 30000000) << '\n'; */
    /* cout << solve(5, {0, 0, 2, 2}, {1, 2, 3 ,4}, {10, 5, 30, 15}, 2) << '\n'; */
    /* cout << solve(3, {0, 0}, {2, 1}, {4, 10}, 0) << '\n'; */
    /* cout << solve(4, {0, 1, 2}, {1, 2, 3}, {1, 1, 1}, 2) << '\n'; */
    /* cout << solve(6, {0, 0, 0, 4, 4}, {1, 2, 4, 3, 5}, {14, 13, 12, 1, 22}, 2) << '\n'; */
    /* TreeNode* root = new TreeNode(1); */
    /* TreeNode* two = new TreeNode(2); */
    /* TreeNode* three = new TreeNode(3); */
    /* TreeNode* four = new TreeNode(4); */
    /* TreeNode* five = new TreeNode(5); */
    /* TreeNode* six = new TreeNode(6); */
    /* root->left=two; */
    /* root->right=three; */
    /* three->left=four; */
    /* three->right=five; */
    /* five->left=six; */
    /* for (auto& [id, mx] : solve(root)){ */
    /*     cout << id << ' ' << mx << '\n'; */
    /* } */
    /* solve({10,5,12,1,30,25,27,7,1,20}, {{1,3},{1,2},{3,5},{3,4},{4,6},{4,7},{2,8},{8,9},{9,10}}, {{2,4,6}, {9,7,10},{1,2,10},{9,9,1},{5,6,27},{9,6,0}}); */
    /* int T; */
    /* cin >> T; */
    /* while(T--) */
    /*     solve(); */
    /* for (int i = 0; i < 1000; ++i){ */
    /*     int n = random(1, 10000); */
    /*     int add = random(0, 1); */
    /*     vector<int> A(2*n+add); */
    /*     for (int j = 0; j < 2*n; j += 2){ */
    /*         int s = random(-1000, 1000); */
    /*         A[j] = s; */
    /*         A[j+1] = 2*s+random(0, 1380); */
    /*     } */
    /*     if (add){ */
    /*         A[2*n] = random(-1000, 1000); */
    /*     } */
    /*     ranges::shuffle(A, mt); */
    /*     int a = solve(A); */
    /*     assert(a == n+add); */
    /* } */
    /* solve({2,2,3,3,5,5,11,11});               // 4 -> (2, 5)x2, (5, 11)x2 */
    /* solve({1,2,3,4,5,6,7});                   // 4 -> (3, 6), (2, 5), (1, 4), (7) */
    /* solve({1,1,1,1,2,2,2,2,4,4,4,4,7,7,7,7}); // 8 -> (1, 4)x4, (2, 7)x4 */
    /* solve({1,2,3,3,3,3,0,0,0,-1});            // 5 -> (1, 2), (3, 0)x3, (3, -1) */
    /* solve({0,0,0,0,-1,-2,-2,-3,-2});          // 5 -> (any 2 elements) */
    /* solve({1,1,1,-2,-2,-2,-2,-2});            // 4 -> (1,-2)x3, (-2,-2) */
    /* solve({1,1,1,1,1,-2,-2,-2});              // 5 -> (1,-2)x3, (1)x2 */

    /* cout << solve({2}, {0,1,10,12,15,8}) << '\n'; */
    /* int T; */
    /* cin >> T; */
    /* while(T--){ */
    /*     solve(); */
    /*     cout << '\n'; */
    /* } */
    /* for (int i = 0; i < 1000; ++i){ */
    /*     int n = random(2, 500); */
    /*     vector<int> A; */
    /*     for (int j = 0; j < n; ++j){ */
    /*         A.push_back(random(-1, 1)); */
    /*     } */
    /*     long long a = solve(A); */
    /*     long long b = mine(A); */
    /*     if (a != b){ */
    /*         for (int m : A){ */
    /*             cout << m << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         cout << "ans = " << a << '\n'; */
    /*         cout << "got = " << b << '\n'; */
    /*         throw; */
    /*     } */
    /* } */
    /* set<int> s; */
    /* s.insert(5); */
    /* s.insert(7); */
    /* for (int& x : s){ */
    /*     x = 1; */
    /* } */
    /* solve({{1,3},{2,1},{4,1},{2,4},{4,6},{4,6}}); */
    /* solve({{1,2},{2,3},{3,4},{4,1}}); */
    /* cout << solve({20,17,15},{2,4,5},1,4) << '\n'; */
    /* cout << solve({9,10},{10,20},1,10) << '\n'; */
    /* cout << solve(6, {{1,2,1},{2,3,5},{3,4,2},{4,5,5},{5,6,1}}) << '\n'; */
    /* cout << solve(5, {{1,2,4}, {2,3,1}, {1,4,6}, {4,5,12}}) << '\n'; */
    /* cout << solve(5, {{1,2,4}, {2,3,4}, {1,4,4}, {4,5,4}}) << '\n'; */
    /* cout << solve(5, {{2,3,4}, {1,4,4}, {4,5,4}, {1,2,4}}) << '\n'; */
    /* cout << solve(5, {{2,3,4}, {4,5,4}, {4,1,4}, {1,2,4}}) << '\n'; */
    /* cout << solve(3, {{1,2,10}, {1,3,2}}) << '\n'; */
    /* long long a = 1, b = 1, n = 2; */
    /* while(b <= 1e18){ */
    /*     b += a; */
    /*     a = b - a; */
    /*     ++n; */
    /*     cout << b << ' '; */
    /* } */
    /* cout << n << '\n'; */
    /* int b = solve({{1,2},{3,4},{8,9}}); */
    /* int a = solve({{2,3},{1,2},{4,3}}); */
    /* int c = solve({{1,4,3},{3,5,6}}); */
    /* int d = solve({{1,1,1,1},{1,1,1,1}}); */
    /* int e = solve({{1,1,1,2},{2,2,2,3}}); */
    /* int f = solve({{1},{2}}); */
    /* cout << b << '\n'; */
    /* cout << a << '\n'; */
    /* cout << c << '\n'; */
    /* cout << d << '\n'; */
    /* cout << e << '\n'; */
    /* cout << f << '\n'; */
    /* int a = solve({1,1},{2,3},{3,1,2}); */
    /* cout << a << '\n'; */
    /* int a = solve(4, 40, {100,20,90,90}, {10,20,30,40}, {{2,3}}); */
    /* int b = solve(10, 10, {1,6,3,3,8,4,8,10,1,3},{2,2,3,3,2,3,1,3,3,2},{{10,10}}); */
    /* int c = solve(1,0,{1},{1},{{1,1}}); */
    /* int d = solve(2,5,{2,1},{1,4},{{1,2}}); */
    /* cout << a << '\n'; */
    /* cout << b << '\n'; */
    /* cout << c << '\n'; */
    /* cout << d << '\n'; */
    /* vector<int> a {7, 1, 3}, b {5, 10, 15, 20}, c {1,2,3,4}, d{1,2,4,5,10,9}, e{1}, f{1,2}; */
    /* cout << solve(a, 2) << '\n'; */
    /* cout << solve(b, 4) << '\n'; */
    /* cout << solve(c, 2) << '\n'; */
    /* cout << solve(d, 1) << '\n'; */
    /* cout << solve(e, 5) << '\n'; */
    /* cout << solve(f, 0) << '\n'; */
    /* tuple<int,int,int> t {1, 2, 3}; */
    /* cout << get<2>(t); */
    /* vector<int> A{38,58,23,1}; */
    /* vector<int> B{2,2,3,4,0,1,2,0}; */
    /* for (int x : solve(A)){ */
    /*     cout << x << ' '; */
    /* } */
    /* cout << '\n'; */
    /* for (int x : solve(B)){ */
    /*     cout << x << ' '; */
    /* } */
    /* cout << '\n'; */
    /* vector<int> A{0,1,0,1,0}; */
    /* cout << solve(A, 2) << '\n'; */

    /* bitset<5> b("1111"); */
    /* cout << b[4] << '\n'; */
    /* vector<int> all{1, 2, 3}; */
    /* int x = 5; */
    /* int* y = &x; */
    /* cout << *y << '\n'; */
    /* for (int i = 0; i < 100; ++i){ */
    /*     int n = random(1, 300); */
    /*     vector<int> all(n); */
    /*     iota(begin(all), end(all), 1); */
    /*     ranges::shuffle(all, mt); */
    /*     int a = brute(all); */
    /*     int b = solve(all); */
    /*     assert(a == b); */
    /* assert(a == c); */
    /* if (a != b){ */
    /*     cout << "ans = " << a << ", got = " << c << '\n'; */
    /*     for (int x : all){ */
    /*         cout << x << ' '; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
    /* } */
    /* int n; */
    /* cin >> n; */
    /* vector<int> on(n), dist(n); */
    /* for (int& x : on){ */
    /*     cin >> x; */
    /* } */
    /* for (int& x : dist){ */
    /*     cin >> x; */
    /* } */
    /* solve(on, dist); */


    /* std::string str = "08/04/2012"; */
    /* std::vector<std::string> tokens; */
    /* regex re("\\/"); */
    /* std::regex re(R"(/)"); */
    /* std::copy( std::sregex_token_iterator(str.begin(), str.end(), re), */
    /*         {}, */
    /*            std::ostream_iterator<std::string>(std::cout, "\n")); */

    //start/end points of tokens in str
    /* std::sregex_token_iterator a(str.begin(), str.end(), re); */
    /* std::copy(a, {}, std::back_inserter(tokens)); */
    /* copy(sregex_token_iterator(begin(str), end(str), re, -1), {}, back_inserter(tokens)); */
    /* for (string t : tokens){ */
    /*     cout << t << '\n'; */
    /* } */
    /* string all; */
    /* for (char i = 'a'; i <= 'z'; ++i){ */
    /*     all += i; */
    /* } */
    /* for (int i = 0; i < 1000; ++i){ */
    /*     int sz = random(1, 500); */
    /*     int limit = random(6, 100); */
    /*     string text; */
    /*     for (int j = 0; j < sz; ++j){ */
    /*         text += all[random(0, 25)]; */
    /*     } */
    /*     /1* cout << "Text = " << text << '\n'; *1/ */
    /*     /1* cout << "Limit = " << limit << '\n'; *1/ */
    /*     solve(text, limit); */
    /*     cout << '\n'; */
    /* } */
    /* solve("HI", 6); */
    /* solve("kajdslfjsadklfjasdjflaskdjflaksdjflkasdjflaskdjflaskdjflksadjflkasdf", 7); */
    /* solve("Hello, world!", 10); */
    /* string t; */
    /* int n; */
    /* cin >> t >> n; */
    /* vector<string> all(n); */
    /* for (auto& x : all){ */
    /*     cin >> x; */
    /* } */
    /* solve(all, t); */
    /* int n; */
    /* cin >> n; */
    /* vector<int> v(n); */
    /* for (int& x : v){ */
    /*     cin >> x; */
    /* } */
    /* solve(v); */
    /* queue<array<int, 3>> q; */
    /* q.push({1, 2, 3}); */
    /* auto [a, b, c] = q.front(); */
    /* int n; */
    /* cin >> n; */
    /* vector<int> num(n); */
    /* for (int& x : num){ */
    /*     cin >> x; */
    /* } */
    /* solve(num); */

    /* cout << popcount((unsigned)2)  << "\n"; */
    /* int a=10; */
    /* a--; */
    /* cin >> a; */
    /* int arr[a]{}; */
    /* for (int& x : arr){ */
    /*     cout << x << ' '; */
    /* } */

    /* vector<vector<int>> vec; */
    /* vec.push_back({1, 2}); */
    /* unordered_map<int, vector<pair<int, int>>> mp; */
    /* vector<int> ans(10); */
    /* int num = 0; */
    /* auto f2 = [&]() */
    /* { */
    /* 	auto lambda = [&](int a, int b, const auto& ff) */
    /*     { */
    /*         if(a == 0 || b == 1) */
    /*             return; */
    /*         for (auto&[c,d]:mp[a]){ */
    /*             if (ans[a]==-1){ */
    /*                 ans[a]=num; */
    /*             } */
    /*             ff(a, b, ff); */
    /*         } */
    /*     }; */
    /*     lambda(0, 0, lambda); */
    /* }; */
    /* f2(); */
    /* cout << f2(5) << '\n'; */
    /* int n; */
    /* cin >> n; */
    /* vector<vector<bool>> v(n, vector<bool>(n)); */
    /* for (int i = 0; i < n; ++i){ */
    /*     for (int j = 0; j < n; ++j){ */
    /*         bool a; */
    /*         cin >> a; */
    /*         v[i][j] = a; */
    /*     } */
    /* } */
    /* solve(v); */
}
