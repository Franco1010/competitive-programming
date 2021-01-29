/*
 © 2021-01-29 08:35:02 Franco1010 All Rights Reserved
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
bool f(vi& v, lli n, lli k, lli y){
  lli acu = y;
  fore(i, 0, n){
    lli x = v[i];
    if(i){
      lli foo = x * 100ll;
      lli bar = acu * k;
      if(foo > bar) return false;
      // cout << foo << ' ' << bar << ": " << (foo <= bar) << ENDL;
    }
    acu += x;
  }
  return true;
}
lli bs(vi& v, lli n, lli k){
  lli pos = 1;
  while(!f(v, n, k, pos)) pos *= 2ll;
  for(lli p = pos; p; p /= 2ll) while(pos - p >= 0 and f(v, n, k, pos - p)) pos -= p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    vi v(n); for(auto& i : v) cin >> i;
    cout << bs(v, n, k) << ENDL;
  }
  return 0;
}
