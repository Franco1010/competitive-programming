/*
 © 2021-03-29 08:35:40 Franco1010 All Rights Reserved
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
const lli N = 1e3 + 10;
const lli MOD = 1e9 + 7;
lli dp[2][N][N];
lli vis[2][N][N];
lli curvis;
lli n;
lli solve(lli pos, lli k, lli dir){
  if(pos < 0 or pos >= n) return 0;
  if(k == 1) return 0;
  auto& ans = dp[dir][pos][k];
  auto& mem = vis[dir][pos][k];
  if(mem != curvis){
    mem = curvis;
    ans = 0;
    if(dir == 0) {
      ans = (ans + solve(pos - 1, k, 0)) % MOD;
      ans = (ans + solve(pos + 1, k - 1, 1) + 1ll) % MOD;
    }
    if(dir == 1){
      ans = (ans + solve(pos + 1, k, 1)) % MOD;
      ans = (ans + solve(pos - 1, k - 1, 0) + 1ll) % MOD;
    }
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli k; cin >> n >> k;
    curvis++;
    cout << (solve(0, k, 1) + 1ll) % MOD << ENDL;
  }
  return 0;
}
