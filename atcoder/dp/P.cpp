/*
 © 2020-09-29 02:13:08 Franco1010 All Rights Reserved
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
const lli N = 1E5 + 5;
vi g[N];
lli dp[N][2];
bool vis[N][2];
lli solve(lli u = 1, bool black = true, lli pr = -1){
  lli &ans = dp[u][black];
  if(!vis[u][black]){
    bool leaf = true;
    vis[u][black] = true;
    ans = 0;
    lli foo = black, bar = 1; // b, w
    for(auto v : g[u]){
      if(v == pr) continue;
      leaf = false;
      bar = bar * solve(v, true, u) % MOD;
      if(black) foo = foo * solve(v, false, u) % MOD;
    }
    ans = (foo + bar + MOD) % MOD;
    if(leaf) ans = black ? 2 : 1;
  }
  return ans;
}
int main(){ _
  lli n; cin >> n;
  fore(i, 0, n - 1){
    lli u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  cout << (solve() + MOD) % MOD << ENDL;
  return 0;
}
