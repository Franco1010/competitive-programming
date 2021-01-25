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
lli bs(vi& v, lli x){
  lli pos = sz(v) - 1;
  for(lli p = pos; p; p /= 2) while(pos - p >= 0 and v[pos - p] >= x) pos -= p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    vector<ii> v(n); fore(i, 0, n) cin >> v[i].f;
    fore(i, 0, n) cin >> v[i].s;
    vi one, two;
    for(auto i : v){
      if(i.s == 1) one.pb(i.f);
      else two.pb(i.f);
    }
    sort(all(one)); reverse(all(one));
    sort(all(two)); reverse(all(two));
    lli cost = 1e18;
    fore(i, 1, sz(one)) one[i] += one[i - 1];
    fore(i, 1, sz(two)) two[i] += two[i - 1];
    fore(i, 0, sz(one)){
      lli foo = m - one[i];
      if(foo <= 0) cost = min(cost, i + 1ll);
      else if(!two.empty()){
        lli bar = bs(two, foo);
        if(foo - two[bar] <= 0) cost = min(cost, i + 1ll + (bar + 1ll) * 2ll);
      }
    }
    fore(i, 0, sz(two)){
      lli foo = m - two[i];
      if(foo <= 0) cost = min(cost, (i + 1ll) * 2ll);
    }
    if(cost == 1e18) cout << -1 << ENDL;
    else cout << cost << ENDL;
  }
  return 0;
}
