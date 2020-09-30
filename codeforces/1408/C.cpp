/*
 © 2020-09-30 09:35:01 Franco1010 All Rights Reserved
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
const ld EPS = 1e-6;
bool geq(ld a, ld b){ return a - b >= -EPS; }
bool leq(ld a, ld b){ return b - a >= -EPS; }
ld f(vi &v, ld len, ld time){
  ld l = 0, r = len;
  ld t = time, ac = 1;
  for(auto i : v){
    if(geq(l + (t * ac), i)){
      t -= (i - l) / ac;
      l = i;
      ac++;
    }else break;
  }
  l += t * ac;
  t = time, ac = 1;
  for(lli i = sz(v) - 1; i >= 0; i--){
    if(leq(r - (t * ac), v[i])){
      t -= (r - v[i]) / ac;
      r = v[i];
      ac++;
    }else break;
  }
  r -= t * ac;
  // cout << l << ' ' << r << ENDL;
  return fabs(l - r);
}
ld ts(vi &v, ld len){
  ld l = 0, r = 2e9 + 1;
  fore(i, 0, 200){
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    if(f(v, len, m1) < f(v, len, m2)) r = m2;
    else l = m1;
  }
  return l;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, l; cin >> n >> l;
    vi v(n);
    fore(i, 0, n){
      cin >> v[i];
    }
    cout << fixed << setprecision(6);
    cout << ts(v, l) << ENDL;
    // deb(f(v, l, 3));
  }
  return 0;
}
