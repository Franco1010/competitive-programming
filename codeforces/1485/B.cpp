/*
 © 2021-02-12 08:50:01 Franco1010 All Rights Reserved
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
lli n, q, k;
lli calc(vi& v, lli i){
  lli prev, nxt;
  if(i > 0) prev = v[i - 1];
  else prev = 0;
  if(i + 1 < n) nxt = v[i + 1];
  else nxt = k + 1ll;
  // cout << v[i] << ' ' << prev << ' ' << nxt << ENDL;
  return v[i] - prev - 1ll + nxt - v[i] - 1ll;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> q >> k;
  vi v(n); for(auto& i : v) cin >> i;
  vi acu(n + 1, 0);
  fore(i, 0, n){
    acu[i + 1] = acu[i] + calc(v, i);
  }
  // for(auto i : acu) cout << i << ' '; cout << ENDL;
  while(q--){
    lli l, r; cin >> l >> r;
    if(l == r){
      cout << k - 1ll << ENDL;
      continue;
    }
    lli foo = 0;
    if(r - 1 > l) foo = acu[r - 1] - acu[l];
    lli t1 = 0, t2 = k + 1ll;
    if(l - 2 >= 0) swap(v[l - 2], t1);
    if(r < n) swap(v[r], t2);
    // deb(foo);
    // for(auto i : v) cout << i << ' '; cout << ENDL;
    cout << foo + calc(v, l - 1) + calc(v, r - 1) << ENDL;
    if(l - 2 >= 0) swap(v[l - 2], t1);
    if(r < n) swap(v[r], t2);
  }
  return 0;
}
