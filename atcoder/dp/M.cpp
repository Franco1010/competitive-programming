/*
 © 2020-09-30 16:52:52 Franco1010 All Rights Reserved
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
int main(){ _
  lli n, k; cin >> n >> k;
  vector<lli> dp(k + 5); dp[0] = 1;
  fore(i, 0, n){
    lli x; cin >> x;
    vi foo(k + 5);
    fore(j, 0, k + 1){
      foo[j] = (foo[j] + dp[j] + MOD) % MOD;
      foo[min(k + 4, j + x + 1)] = (foo[min(k + 4, j + x + 1)] - dp[j] + MOD) % MOD;
    }
    fore(j, 1, sz(foo)) foo[j] = (foo[j] + foo[j - 1] + MOD) % MOD;
    dp = foo;
  }
  cout << (dp[k] + MOD) % MOD << ENDL;
  return 0;
}
