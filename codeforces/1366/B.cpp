/*
 © 2020-06-11 09:35:02 Franco1010 All Rights Reserved
*/

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
#define deb(x) cout << #x": " << (x) << endl;
bool inter(ii &a, ii &b){
  if(a.f <= b.f and b.f <= a.s) return true;
  if(a.f <= b.s and b.s <= a.s) return true;
  if(b.f <= a.f and a.f <= b.s) return true;
  if(b.f <= a.s and a.s <= b.s) return true;
  if(a.f <= b.f and b.s <= a.s) return true;
  if(b.f <= a.f and a.s <= b.s) return true;
  return false;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, x, m; cin >> n >> x >> m;
    vector<ii> v = {ii{x, x}};
    lli ll = x, rr = x;
    fore(i, 0, m){
      lli l, r; cin >> l >> r;
      ii foo = {l, r};
      fore(j, 0, sz(v)){
        if(inter(v[j], foo)) {
          v.pb(foo);
          break;
        }
      }
    }
    for(auto i : v) ll = min(ll, i.f), rr = max(rr, i.s);
    cout << rr - ll + 1 << ENDL;
  }
  return 0;
}
