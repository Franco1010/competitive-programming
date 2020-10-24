/*
 © 2020-10-24 07:00:00 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
  vi rank, pr, a, b;
  DSU(int n){
    rank.resize(n, 1);
    pr.resize(n);
    iota(all(pr), 0);
    a.resize(n);
    b.resize(n);
  }
  lli find(lli u){
    return u == pr[u] ? u : pr[u] = find(pr[u]);
  }
  void unite(lli u, lli v){
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
      a[u] += a[v];
      b[u] += b[v];
    }
  }
};
int main(){ _
  lli n, m; cin >> n >> m;
  DSU dsu(n);
  fore(i, 0, n) cin >> dsu.a[i];
  fore(i, 0, n) cin >> dsu.b[i];
  fore(i, 0, m){
    lli u, v; cin >> u >> v;
    u--,v--;
    dsu.unite(u, v);
  }
  set<lli> st;
  fore(i, 0, n) st.insert(dsu.find(i));
  bool yes = true;
  for(auto i : st){
    if(dsu.a[i] != dsu.b[i]) yes = false;
  }
  if(yes) cout << "Yes" << ENDL;
  else cout << "No" << ENDL;
  return 0;
}
