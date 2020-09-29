/*
 © 2020-09-29 01:47:23 Franco1010 All Rights Reserved
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
  lli n; cin >> n;
  string s; cin >> s;
  vector<lli> dp = {1, 0, 0, 0};
  for(auto c : s){
    vector<lli> foo = dp;
    if(c == '?'){
      fore(i, 0, 4) foo[i] = foo[i] * 3ll % MOD;
      fore(i, 1, 4) foo[i] = (foo[i] + dp[i - 1] + MOD) % MOD;
    }else foo[c - 'a' + 1] = (foo[c - 'a' + 1] + dp[c - 'a'] + MOD) % MOD;
    dp = foo;
  }
  cout << (dp[3] + MOD) % MOD << ENDL;
  return 0;
}
