/*
 © 2020-10-02 01:05:29 Franco1010 All Rights Reserved
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
const lli N = 1e5 + 5;
vi g[N];
vi pref[N], suff[N];
lli n, m;
lli dp[N];
void reroot(int u = 1, int pr = -1){
  fore(i, 0, sz(g[u])){
    if(g[u][i] == pr) {
      g[u].erase(begin(g[u]) + i);
      break;
    }
  }
  for(auto v : g[u]) reroot(v, u);
}
lli dfs(lli u = 1){
  pref[u].pb(1);
  for(auto v : g[u]){
    lli foo = dfs(v);
    pref[u].pb((foo + 1ll) % m);
    suff[u].pb((foo + 1ll) % m);
  }
  suff[u].pb(1);
  fore(i, 1, sz(pref[u])) pref[u][i] = pref[u][i] * pref[u][i - 1] % m;
  for(lli i = sz(suff[u]) - 2; i >= 0; i--) suff[u][i] = suff[u][i] * suff[u][i + 1] % m;
  return pref[u].back();
}
void dfs1(lli u = 1, lli up = 1){
  dp[u] = up * pref[u].back() % m;
  fore(i, 0, sz(g[u])){
    dfs1(g[u][i], (up * pref[u][i] % m * suff[u][i + 1] % m + 1 + m) % m);
  }
}
int main(){ _
  cin >> n >> m;
  fore(i, 0, n - 1){
    lli u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  reroot();
  dfs();
  dfs1();
  fore(i, 1, n + 1) cout << (dp[i] + m) % m << ENDL;
  return 0;
}
