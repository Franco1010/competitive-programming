/*
 © 2021-01-25 01:59:18 Franco1010 All Rights Reserved
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
const lli MOD = 1e9 + 7;
lli g(lli x){
  lli res;
  if(x&1) res =  ((x + 1) / 2ll) * x;
  else res = (x / 2ll) * (x + 1ll);
  res %= MOD;
  return res;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, k; cin >> n >> k;
  vi v(n); fore(i, 0, n) cin >> v[i];
  lli res = 0;
  fore(i, 0, n){
    lli foo = 0, bar = 0;
    fore(j, 0, n){
      foo += v[j] < v[i];
      if(j > i) bar += v[j] < v[i];
    }
    res = (res + g(k - 1ll) * foo % MOD) % MOD;
    res = (res + bar * k % MOD) % MOD;
  }
  cout << res << ENDL;
  return 0;
}
