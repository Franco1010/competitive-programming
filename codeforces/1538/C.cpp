/*
 © 2021-06-10 09:35:02 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
lli bl(vi& v, lli l, lli x, lli posx){
  lli pos = posx - 1;
  for(lli p = sz(v); p; p /= 2) while(pos - p >= 0 and v[pos - p] + x >= l) pos -= p;
  if(v[pos] + x < l) return INF;
  return pos;
}
lli br(vi& v, lli r, lli x, lli posx){
  lli pos = 0;
  for(lli p = sz(v); p; p /= 2) while(pos + p < posx and v[pos + p] + x <= r) pos += p;
  if(v[pos] + x > r) return -INF;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, l, r; cin>> n >> l >> r;
    vi v(n); for(auto& i : v) cin >> i;
    sort(all(v));
    lli ans = 0;
    fore(i, 1, n){
      lli foo = bl(v, l, v[i], i);
      lli bar = br(v, r, v[i], i);
      if(foo <= bar)
      ans += bar - foo + 1;
    }
    cout << ans << ENDL;
  }
  return 0;
}
