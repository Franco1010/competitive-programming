/*
 © 2020-06-28 09:35:02 Franco1010 All Rights Reserved
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

int main(){ _
  lli n, k; cin >> n >> k;
  vector<lli> both, a, b;
  both.pb(0);
  fore(i, 0, n){
    lli x, y, z; cin >> x >> y >> z;
    if(y and z) both.pb(x);
    else if(y) a.pb(x);
    else if(z) b.pb(x);
  }
  sort(all(both));
  sort(all(a));
  sort(all(b));
  vector<lli> acu;
  acu.pb(0);
  for(lli i = 0; i < min(sz(a), sz(b)); i++){
    acu.pb(acu.back() + a[i] + b[i]);
  }
  for(lli i = 1; i < sz(both); i++){
    both[i] += both[i - 1ll];
  }
  lli res = 1e18;
  for(lli i = 0; i < min(k + 1, (lli)sz(acu)); i++){
    if(sz(both) > k - i) res = min(res, acu[i] + both[k - i]);
  }
  if(res == lli(1e18)) cout << -1 << ENDL;
  else cout << res << ENDL;
  return 0;
}
