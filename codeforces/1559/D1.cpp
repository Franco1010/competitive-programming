/*
 © 2021-08-15 09:35:02 Franco1010 All Rights Reserved
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
  vector<int> pr, rank;
  stack<pair<int,int>> what;
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
  bool same(int u, int v) {return find(u) == find(v);}
  pair<int,int> rollback(){ // O(1)
    pair<int,int> last = what.top();
    what.pop();
    int u = last.f, v = last.s;
    if(u != -1){
      rank[u] -= rank[v];
      pr[v] = v;
    }
    return last;
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, a, b; cin >> n >> a >> b;
  DSU aa(n), bb(n);
  fore(i, 0, a){
    lli u, v; cin >> u >> v; u--, v--;
    aa.unite(u, v);
  }
  fore(i, 0, b){
    lli u, v; cin >> u >> v; u--, v--;
    bb.unite(u, v);
  }
  vector<ii> res;
  fore(i, 0, n){
    fore(j, 0, n){
      if(!aa.same(i, j) and !bb.same(i, j)){
        aa.unite(i, j); bb.unite(i, j);
        res.pb({i, j});
      }
    }
  }
  cout << sz(res) << ENDL;
  for(auto i : res) cout << i.f + 1 << ' ' << i.s + 1 << ENDL;
  return 0;
}
