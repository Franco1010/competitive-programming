/*
 © 2020-10-20 16:50:02 Franco1010 All Rights Reserved
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
  vi pr, tot;
  DSU(int nn = 0){ // O(N)
    pr.resize(nn);
    tot.resize(nn, 1);
    iota(all(pr), 0);
  }
  int find(int u){ // O(logN)
    return pr[u] == u ? u: pr[u] = find(pr[u]);
  }
  void unite(int u, int v){ // O(logN)
    u = find(u), v = find(v);
    if( u != v ){
      if( tot[u] < tot[v] ) swap(u, v);
      tot[u] += tot[v];
      pr[v] = u;
    }
  }
};
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n ;cin >> n;
    vi v(n); fore(i, 0, n) cin >> v[i];
    vector<ii> ans;
    DSU dsu(n);
    fore(i, 0, n){
      fore(j, i + 1, n){
        if(v[i] != v[j] and dsu.find(i) != dsu.find(j)){
          dsu.unite(i, j);
          ans.pb({i, j});
        }
      }
    }
    if(dsu.tot[dsu.find(0)] == n){
      cout << "YES" << ENDL;
      for(auto i : ans) cout << i.f + 1ll << ' ' << i.s + 1ll << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
