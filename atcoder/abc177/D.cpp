/*
 © 2020-08-29 06:57:42 Franco1010 All Rights Reserved
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
const lli MOD = 1e9 + 7;
struct DSU{
  vector<lli> rank, pr;
  DSU(int n){
    rank.resize(n + 5, 1);
    pr.resize(n + 5);
    iota(all(pr), 0);
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
    }
  }
};
int main(){ _
  lli n, m; cin >> n >> m;
  DSU dsu(n);
  fore(i, 0, m){
    lli x, y; cin >> x >> y;
    dsu.unite(x, y);
  }
  cout << *max_element(all(dsu.rank)) << ENDL;
  return 0;
}
