/*
 © 2021-01-14 08:35:01 Franco1010 All Rights Reserved
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
const lli N = 2E5 + 5;
vector<ii> g[N];
lli dis[2][2][N];
struct Node{
  lli dis, u;
  bool mn, mx;
  bool operator < (const Node& n) const {
    return dis > n.dis;
  }
};
lli n, m;
void dijkstra(int ini){
  fore(i, 0, 2) fore(j, 0, 2) fore(k, 0, N) dis[i][j][k] = -1;
  priority_queue<Node> pq;
  pq.push({0, ini, 0, 0});
  dis[0][0][ini] = 0;
  while(!pq.empty()){
    auto u = pq.top(); pq.pop();
    if(u.dis != dis[u.mn][u.mx][u.u]) continue;
    for(auto v : g[u.u]){
      if(dis[u.mn][u.mx][v.f] == -1 or dis[u.mn][u.mx][u.u] + v.s < dis[u.mn][u.mx][v.f]){// -
        dis[u.mn][u.mx][v.f] = dis[u.mn][u.mx][u.u] + v.s;
        pq.push({dis[u.mn][u.mx][v.f], v.f, u.mn, u.mx});
      }
      if(!u.mn and (dis[1][u.mx][v.f] == -1 or dis[u.mn][u.mx][u.u] + 2ll * v.s < dis[1][u.mx][v.f])){// mn
        dis[1][u.mx][v.f] = dis[u.mn][u.mx][u.u] + 2ll * v.s;
        pq.push({dis[1][u.mx][v.f], v.f, 1, u.mx});
      }
      if(!u.mx and (dis[u.mn][1][v.f] == -1 or dis[u.mn][u.mx][u.u] < dis[u.mn][1][v.f])){// mx
        dis[u.mn][1][v.f] = dis[u.mn][u.mx][u.u];
        pq.push({dis[u.mn][1][v.f], v.f, u.mn, 1});
      }
      if(!u.mx and !u.mn and (dis[1][1][v.f] == -1 or dis[u.mn][u.mx][u.u] + v.s < dis[1][1][v.f])){// mn&mx
        dis[1][1][v.f] = dis[u.mn][u.mx][u.u] + v.s;
        pq.push({dis[1][1][v.f], v.f, 1, 1});
      }
    }
  }
  fore(i, 1, n) cout << dis[1][1][i] << ' '; cout << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> m;
  fore(i, 0, m){
    lli u, v, w; cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  dijkstra(0);
  return 0;
}
