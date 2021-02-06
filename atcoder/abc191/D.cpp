/*
 © 2021-02-06 07:10:53 Franco1010 All Rights Reserved
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
const ld EPS = 1E-9;
const lli LIM = 2e5 + 5;
bool leq(ld a, ld b){ return b - a >= -EPS; }
ld x, y, r;
bool dis(ld a, ld b){
  ld m = (a - x) * (a - x);
  ld n = (b - y) * (b - y);
  return leq(m + n, r * r);
}
lli bsr(lli h){
  lli pos = floor(x);
  for(lli p = LIM; p; p /= 2) while(pos + p <= LIM and dis(pos + p, h)) pos += p;
  return pos;
}
lli bsl(lli h){
  lli pos = ceil(x);
  for(lli p = LIM; p; p /= 2) while(pos - p >= -LIM and dis(pos - p, h)) pos -= p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
   cin >> x >> y >> r;
  lli d = ceil(y - r) - 1, u = floor(y + r) + 1;
  lli res = 0;
  fore(i, d, u + 1){
    if(!dis(x, i)) continue;
    lli rr = bsr(i), ll = bsl(i);
    // cout << i << ": " << ll << ' ' << rr << ENDL;
    if(ll <= rr) res += rr - ll + 1ll;
  }
  cout << res << ENDL;
  return 0;
}
