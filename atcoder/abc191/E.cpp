/*
 © 2021-02-06 06:42:41 Franco1010 All Rights Reserved
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
const lli N = 2e3 + 5;
const lli INF = 1e10;
vector<ii> g[N];
lli vis[N];
lli dp[N];
lli curvis;
lli n, m;
struct Node{
  lli u, c;
  bool operator < (const Node & n)const{
    return c > n.c;
  }
};
lli bfs(int st){
  curvis++;
  lli res = INF;
  priority_queue<Node> pq;
  pq.push({st, 0});
  vis[st] = curvis;
  dp[st] = 0;
  while(!pq.empty()){
    auto u = pq.top(); pq.pop();
    if(dp[u.u] != u.c) continue;
    // cout << u.u << ' ' << u.c << ENDL;
    for(auto v : g[u.u]){
      if(v.f == st) res = min(res, u.c + v.s);
      if(vis[v.f] != curvis or u.c + v.s < dp[v.f]){
        vis[v.f] = curvis;
        dp[v.f] = u.c + v.s;
        pq.push({v.f, dp[v.f]});
      }
    }
  }
  // fore(i, 0, n + 1) cout << dp[i] << ' '; cout << ENDL;
  return res;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  map<ii, lli> mp;
  cin >> n >> m;
  fore(i, 0, m){
    lli u, v, w; cin >> u >> v >> w;
    if(!mp.count({u, v})) mp[{u, v}] = w;
    else mp[{u, v}] = min(mp[{u, v}], w);
  }
  for(auto i : mp){
    g[i.f.f].pb({i.f.s, i.s});
  }
  fore(i, 1, n + 1){
    curvis++;
    auto foo = bfs(i);
    if(foo < INF) cout << foo << ENDL;
    else cout << -1 << ENDL;
  }
  return 0;
}
