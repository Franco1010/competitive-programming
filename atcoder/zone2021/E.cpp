/*
 © 2021-05-01 07:01:01 Franco1010 All Rights Reserved
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
const lli N = 5e2 + 5;
int a[N][N], b[N][N];
int dp[N][N];
bool vis[N][N];
lli n, m;
using Node = array<int,3>;
void dijkstra(){
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({0, 0, 0});
  dp[0][0] = 0;
  vis[0][0] = true;
  while(!pq.empty()){
    auto u = pq.top(); pq.pop();
    if(u[0] != dp[u[1]][u[2]]) continue;
    // (x, y + 1)
    int cost = u[0] + a[u[1]][u[2]];
    if(u[2] + 1 < m and (!vis[u[1]][u[2] + 1] or cost < dp[u[1]][u[2] + 1])){
      dp[u[1]][u[2] + 1] = cost;
      vis[u[1]][u[2] + 1] = true;
      pq.push({cost, u[1], u[2] + 1});
    }
    // (x, y - 1)
    if(u[2] > 0){
      cost = u[0] + a[u[1]][u[2] - 1];
      if(!vis[u[1]][u[2] - 1] or cost < dp[u[1]][u[2] - 1]){
        dp[u[1]][u[2] - 1] = cost;
        vis[u[1]][u[2] - 1] = true;
        pq.push({cost, u[1], u[2] - 1});
      }
    }
    // (x + 1, y)
    cost = u[0] + b[u[1]][u[2]];
    if(u[1] + 1 < n and (!vis[u[1] + 1][u[2]] or cost < dp[u[1] + 1][u[2]])){
      dp[u[1] + 1][u[2]] = cost;
      vis[u[1] + 1][u[2]] = true;
      pq.push({cost, u[1] + 1, u[2]});
    }
    // else
    fore(i, 1, u[1] + 1){
      cost = u[0] + lli(i) + 1ll;
      if(!vis[u[1] - i][u[2]] or cost < dp[u[1] - i][u[2]]){
        dp[u[1] - i][u[2]] = cost;
        vis[u[1] - i][u[2]] = true;
        pq.push({cost, u[1] - i, u[2]});
      }
    }
  }
  cout << dp[n - 1][m - 1] << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> m;
  fore(i, 0, n) fore(j, 0, m - 1) cin >> a[i][j];
  fore(i, 0, n - 1) fore(j, 0, m) cin >> b[i][j];
  dijkstra();
  return 0;
}
