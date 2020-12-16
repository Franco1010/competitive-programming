/*
 © 2020-12-16 02:25:26 Franco1010 All Rights Reserved
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
struct Node{
  lli l, r, ind;
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<Node> v;
    vi res(n);
    vi comp;
    fore(i, 0, n){
      lli l, r; cin >> l >> r;
      v.pb({l, r, i});
      comp.pb(l); comp.pb(r);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), end(comp));
    lli N = sz(comp) + 1;
    vector<vi> tin(N), tout(N);
    for(auto &i : v){
      i.l = lower_bound(all(comp), i.l) - begin(comp);
      i.r = lower_bound(all(comp), i.r) - begin(comp);
      tin[i.l].pb(i.ind);
      tout[i.r].pb(i.ind);
    }
    lli foo = 0;
    fore(i, 0, N){
      for(auto j : tin[i]) res[j] += foo;
      foo += sz(tout[i]);
    }
    foo = 0;
    for(lli i = N - 1; i >= 0; i--){
      for(auto j : tout[i]) res[j] += foo;
      foo += sz(tin[i]);
    }
    cout << *min_element(all(res)) << ENDL;
  }
  return 0;
}
