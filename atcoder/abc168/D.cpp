/*
 © 2021-01-25 01:59:18 Franco1010 All Rights Reserved
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
vi g[N];
lli pr[N];
bool vis[N];
bool bfs(lli n){
  queue<lli> q;
  q.push(1);
  lli cnt = 1;
  vis[1] = true;
  while(!q.empty()){
    auto u = q.front(); q.pop();
    for(auto v : g[u]){
      if(!vis[v]){
        vis[v] = true;
        cnt++;
        q.push(v);
        pr[v] = u;
      }
    }
  }
  return cnt == n;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; cin >> n >> m;
  fore(i, 0, m){
    lli u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  if(bfs(n)){
    cout << "Yes" << ENDL;
    fore(i, 2, n + 1) cout << pr[i] << ENDL;
  }else cout << "No" << ENDL;
  return 0;
}
