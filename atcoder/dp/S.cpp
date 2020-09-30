/*
 © 2020-09-29 23:24:48 Franco1010 All Rights Reserved
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
const lli K = 1e4 + 5;
const lli D = 105;
const lli MOD = 1E9 + 7;
lli d;
string k;
lli dp[K][D][2];
bool vis[K][D][2];
lli solve(lli pos = 0, lli mod = 0, bool less = false){
  if(pos >= sz(k)) return mod == 0;
  lli &ans = dp[pos][mod][less];
  if(not vis[pos][mod][less]){
    vis[pos][mod][less] = true;
    ans = 0;
    fore(i, 0, less ? 10 : k[pos] - '0' + 1){
      ans = (ans + solve(pos + 1, (mod + i + d) % d, less or (i < k[pos] - '0')) + MOD) % MOD;
    }
    ans = (ans + MOD) % MOD;
  }
  return ans;
}
int main(){ _
  cin >> k >> d;
  cout << (solve() - 1ll + MOD) % MOD << ENDL;
  return 0;
}
