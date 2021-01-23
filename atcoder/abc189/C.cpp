/*
 © 2021-01-23 05:54:10 Franco1010 All Rights Reserved
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
  DSU(int n): pr(n), rank(n, 1) {
    iota(all(pr), 0);
  }
  lli find(lli u){
    return pr[u] == u ? u : pr[u] = find(pr[u]);
  }
  void unite(lli u, lli v){
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
    }
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vector<ii> v;
  fore(i, 0, n){
    lli x; cin >> x;
    v.pb({x, i});
  }
  sort(all(v), [&](const ii& a, const ii& b){
    return a.f > b.f;
  });
  DSU dsu(n);
  vector<bool> mark(n, false);
  lli res = 0;
  for(auto i : v){
    mark[i.s] = true;
    if(i.s > 0 and mark[i.s - 1]) dsu.unite(i.s, i.s - 1);
    if(i.s + 1 < n and mark[i.s + 1]) dsu.unite(i.s, i.s + 1);
    // deb(dsu.rank[dsu.find(i.s)]);
    res = max(res, dsu.rank[dsu.find(i.s)] * i.f);
  }
  cout << res << ENDL;
  return 0;
}
