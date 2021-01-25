/*
 © 2021-01-25 09:00:01 Franco1010 All Rights Reserved
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
const lli N = 1E3 + 5;
const lli MOD = 1e9 + 7;
lli v[N];
ii dp[N][N];
lli vis[N][N];
lli curvis;
lli n;
ii solve(lli k, lli pos = 0){
  if(k == 0) return ii{0, 1};
  if(pos == n) return ii{-1e9, 0};
  auto &ans = dp[k][pos];
  if(vis[k][pos] != curvis){
    vis[k][pos] = curvis;
    ans = {0, 0};
    auto foo = solve(k - 1, pos + 1);
    ans = {foo.f + v[pos], foo.s};
    foo = solve(k, pos + 1);
    if(foo.f == ans.f) ans.s = (ans.s + foo.s) % MOD;
    if(foo.f > ans.f) ans = foo;
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli k; cin >> n >> k;
    fore(i, 0, n) cin >> v[i];
    curvis++;
    cout << solve(k).s << ENDL;
  }
  return 0;
}
