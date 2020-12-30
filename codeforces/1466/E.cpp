/*
 © 2020-12-30 08:35:01 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
const lli MOD = 1e9 + 7;
const lli N = 5e5 + 5;
const lli M = 60;
lli pot2(lli x){
  return (1ll << x) % MOD;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v(n); fore(i, 0, n) cin >> v[i];
    vi pot(M);
    fore(i, 0, n){
      fore(j, 0, M){
        if(v[i]&(1ll << j)) pot[j]++;
      }
    }
    lli res = 0;
    fore(i, 0, n){
      lli foo = 0;
      fore(j, 0, M){
        if(v[i]&(1ll << j)) foo = (foo + pot2(j) * pot[j] % MOD) % MOD;
      }
      lli bar = 0;
      fore(j, 0, M){
        if(v[i]&(1ll << j)) bar = (bar + pot2(j) * n % MOD) % MOD;
        else bar = (bar + pot2(j) * pot[j] % MOD) % MOD;
      }
      res = (res + foo * bar % MOD) % MOD;
    }
    cout << res << ENDL;
  }
  return 0;
}
