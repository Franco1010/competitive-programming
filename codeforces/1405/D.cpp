/*
 © 2020-09-07 15:00:02 Franco1010 All Rights Reserved
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
const int N = 1e5 + 5;
vector<lli> g[N];
lli getd(int u, int goal, int pr = -1, int dis = 0){
  if(u == goal) return dis;
  lli res = 0;
  for(auto v : g[u]){
    if(v != pr){
      res += getd(v, goal, u, dis + 1);
    }
  }
  return res;
}
ii dfs(int u, int pr = -1, int dis = 0){
  ii res = {dis, u};
  for(auto v : g[u]){
    if(v != pr){
      res = max(res, dfs(v, u, dis + 1));
    }
  }
  return res;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, a, b, da, db; cin >> n >> a >> b >> da >> db;
    fore(i, 0,n + 3) g[i].clear();
    fore(i, 0, n - 1){
      lli u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    if(getd(a, b) <= da) cout << "Alice" << ENDL;
    else if(dfs(dfs(1).s).f <= 2 * da) cout << "Alice" << ENDL;
    else if(db > 2*da) cout << "Bob" << ENDL;
    else cout << "Alice" << ENDL;
  }
  return 0;
}
