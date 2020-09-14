/*
 © 2020-09-13 21:16:02 Franco1010 All Rights Reserved
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
const lli MOD = 1e9 + 7;
const lli N = 2e3 + 5;
lli fac[N];
lli fpow(lli x, lli y){
  lli res = 1;
  while(y > 0){
    if(y & 1) res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return (res + MOD) % MOD;
}
lli dp[N];
lli solve(lli res){
  if(res == 0) return 1;
  lli &ans = dp[res];
  if(ans == -1){
    ans = 0;
    fore(i, 3, res+1){
      ans = (ans + solve(res - i) + MOD) % MOD;
    }
    ans = (ans + MOD) % MOD;
  }
  return ans;
}
int main(){ _
  fore(i, 0, N) dp[i] = -1;
  lli n; cin >> n;
  if(n < 3){
    cout << 0 << ENDL;
    return 0;
  }
  lli res = solve(n);
  res = (res + MOD) % MOD;
  cout << res << ENDL;
  return 0;
}
