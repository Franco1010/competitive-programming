/*
 © 2021-02-18 08:35:02 Franco1010 All Rights Reserved
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
lli fx(vector<ii>& v, lli x){
  lli res = 0;
  for(auto i : v) res += abs(i.f - x);
  return res;
}
lli tx(vector<ii>& v){
  lli l = -1e9, r = 1e9;
  while(r - l > 2){
    lli m1 = l + (r - l) / 3;
    lli m2 = r - (r - l) / 3;
    if(fx(v, m1) < fx(v, m2)) r = m2;
    else l = m1;
  }
  lli mn = 1e18;
  lli pos = l;
  fore(i, l, r + 1){
    if(fx(v, i) < mn){
      mn = fx(v, i);
      pos = i;
    }
  }
  return pos;
}
lli fy(vector<ii>& v, lli x){
  lli res = 0;
  for(auto i : v) res += abs(i.s - x);
  return res;
}
lli ty(vector<ii>& v){
  lli l = -1e9, r = 1e9;
  while(r - l > 2){
    lli m1 = l + (r - l) / 3;
    lli m2 = r - (r - l) / 3;
    if(fy(v, m1) < fy(v, m2)) r = m2;
    else l = m1;
  }
  lli mn = 1e18;
  lli pos = l;
  fore(i, l, r + 1){
    if(fy(v, i) < mn){
      mn = fy(v, i);
      pos = i;
    }
  }
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<ii> v;
    fore(i, 0, n){
      lli x, y; cin >> x >> y;
      v.pb({x, y});
    }
    lli x = tx(v), y = ty(v);
    lli bx = fx(v, x), by = fy(v, y);
    lli xl = x, xr = x, yl = y, yr = y;
    for(lli p = 2e9; p; p /= 2ll) while(xl - p >= lli(-1e9) and fx(v, xl - p) == bx) xl -= p;
    for(lli p = 2e9; p; p /= 2ll) while(xr + p <= lli(1e9) and fx(v, xr + p) == bx) xr += p;
    for(lli p = 2e9; p; p /= 2ll) while(yl - p >= lli(-1e9) and fy(v, yl - p) == by) yl -= p;
    for(lli p = 2e9; p; p /= 2ll) while(yr + p <= lli(1e9) and fy(v, yr + p) == by) yr += p;
    cout << (xr - xl + 1) * (yr - yl + 1) << ENDL;
  }
  return 0;
}
