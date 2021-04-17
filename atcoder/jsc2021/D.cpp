/*
 © 2021-04-17 02:06:01 Franco1010 All Rights Reserved
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
lli fpow(lli x, lli y){
  lli r = 1;
  while(y){
    if(y&1ll) r = r * x % MOD;
    x = x * x % MOD;
    y >>= 1ll;
  }
  return (r + MOD) % MOD;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, p; cin >> n >> p;
  lli ans = p - 1ll;
  ans = ans * fpow(p - 2ll, n - 1ll) % MOD;
  cout << ans << ENDL;
  return 0;
}
