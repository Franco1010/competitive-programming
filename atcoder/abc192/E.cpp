/*
 © 2021-02-20 07:20:47 Franco1010 All Rights Reserved
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
const lli N = 1e5 + 5;
struct G{
  lli v, t, k;
};
vector<G> g[N];
struct Node{
  lli u, t;
  bool operator < (const Node& n) const {
    return t > n.t;
  }
};
lli d(lli x, lli y){
  vi dp(N, -1);
  priority_queue<Node> pq;
  pq.push({x, 0});
  dp[x] = 0;
  while(!pq.empty()){
    auto u = pq.top(); pq.pop();
    // cout << u.u << ' ' << u.t << ENDL;
    for(auto v : g[u.u]){
      lli nt = u.t + (u.t % v.k == 0 ? 0 : (v.k - u.t % v.k)) + v.t;
      if(dp[v.v] == -1 or nt < dp[v.v]){
        dp[v.v] = nt;
        pq.push({v.v, nt});
      }
    }
  }
  return dp[y];
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m, x, y; cin >> n >> m >> x >> y;
  fore(i, 0, m){
    lli a, b, t, k; cin >> a >> b >> t >> k;
    g[a].pb({b, t, k});
    g[b].pb({a, t, k});
  }
  cout << d(x, y) << ENDL;
  return 0;
}
