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
const lli MOD = 1E9 + 7;
lli fpow(lli x, lli y){
  lli res = 1;
  while(y > 0){
    if(y & 1) res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return (res + MOD) % MOD;
}
int main(){ _
  lli n; cin >> n;
  lli foo = 1, bar = 1, faa = 1;
  cout << (fpow(10, n) - (2ll * fpow(9, n) % MOD - fpow(8, n) + MOD) % MOD + MOD) % MOD << ENDL;
  return 0;
}
