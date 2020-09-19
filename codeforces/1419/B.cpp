/*
 © 2020-09-19 09:35:01 Franco1010 All Rights Reserved
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
lli g(lli x){
  if(x & 1) return x * ((x + 1ll) / 2ll);
  return (x / 2ll) * (x + 1ll);
}
int main(){ _
  lli t; cin >> t;
  vector<lli> v = {0};
  lli p = 1;
  fore(i, 1, 1e8){
    v.pb(p * p + 2ll * v.back());
    p *= 2ll;
    if(v.back() >= 1e18) break;
  }
  while(t--){
    lli x; cin >> x;
    lli res = 0;
    fore(i, 1, sz(v)){
      if(v[i] <= x){
        res++;
        x -= v[i];
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
