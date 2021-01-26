/*
 © 2021-01-25 09:00:01 Franco1010 All Rights Reserved
*/

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
struct DSU{
  vi pr, rank;
  stack<ii> what;
  DSU(int n): pr(n), rank(n, 1){ // O(N)
    iota(all(pr), 0);
  }
  int find(int u){ // O(1)
    return pr[u] == u ? u: pr[u] = find(pr[u]);
  }
  void unite(int u, int v){ // O(1)
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
      what.push({u, v});
    }else what.push({-1, -1});
  }
  ii rollback(){ // O(1)
    ii last = what.top();
    what.pop();
    int u = last.f, v = last.s;
    if(u != -1){
      rank[u] -= rank[v];
      pr[v] = v;
    }
    return last;
  }
};
const lli N = 2e5 + 5;
vi dd[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  fore(i, 1, N) for(lli j = i + i; j < N; j += i) dd[j].pb(i);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v(n); fore(i, 0, n) cin >> v[i];
    vi dp(N, 0);
    vi acu(N, 0);
    vector<bool> vis(n, false);
    sort(all(v));
    // DSU dsu(2e5 + 5);
    // vector<bool> mark(2e5 + 5, false);
    for(auto i : v) acu[i]++, dp[i] = acu[i];
    lli res = 0;
    for(auto i : v){
      for(auto d : dd[i]) dp[i] = max(dp[i], dp[d] + acu[i]);
      res = max(res, dp[i]);
    }
    cout << n - res << ENDL;
  }
  return 0;
}
